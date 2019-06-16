Init;

global time robot N sig_in sig_fin tf_task

%%%%%%%%%%%%%%%%%Prima parte di triettoria%%%%%%%%%%%%%%%%%
% Durata traiettoria task
obj.dynamics = 0;

% Con o senza controllo delle forze interne
contr_hint = 0;

for k=1:N
    robot(k).dp0 = zeros(3,1);
    robot(k).ddp0 = zeros(3,1);
    robot(k).dm = zeros(3,1);
    robot(k).m = zeros(3,1);
end

tf_task = 3;

InitPlanningTask();

time = 0;
kn1max = 0;
kn2max = 0;
kn3max = 0;
kn4max = 0;

i = 1;

t(i) = (i-1)*T;

% Task desiderato
sig_des(:,i) = ComputeTask(sig_in);
dsig_des(:,i) = dsig0;
ddsig_des(:,i) = ddsig0;

KN = [0 0 0 0 0 0 0 0]';

% Ciclo su ogni robot implementando osservatore, inversione e controllo
for k=1:N
    robot(k).q(i,:) = robot(k).q0;
    robot(k).dq(i,:) = robot(k).dq0;
    robot(k).x = robot(k).x0';
    robot(k).u_stim = compute_u_Stim(sig_des(:,i), dsig_des(:,i), robot(k).x_stim(:,i), obj);
    sommatoria = zeros(6*N,1);
    for ll=1:length(robot(k).Ni)
        sommatoria = sommatoria + (robot(robot(k).Ni(ll)).x_stim(:,i) - robot(k).x_stim(:,i));
    end
    robot(k).dx_stim(:,i) = ko*(sommatoria + [zeros(6*(k-1),1); (robot(k).x0' - robot(k).x_stim(1+6*(k-1):6+6*(k-1),i)); zeros(6*(N-k),1)]) + robot(k).u_stim;
    
    % Calcolo dqsigma e ddqsigma per ciascun robot
    preInver(i, k);
    
    robot(k).dx(:,i) = zeros(6,1);
    robot(k).v(:,i) = [0 0 0]';
    robot(k).ufi(:,i) = zeros(3,1);
    robot(k).deltaTau(:,i) = zeros(8,1);

    robot(k).dqsigma(i,:) = InverseKinematicsFirstOrder(k, KN, i, contr_hint);
    robot(k).ddqsigma(i,:) = InverseKinematicsSecondOrder(k, i, ddsig_des(:,i), dsig_des(:,i), robot(k).dqsigma(i,:), contr_hint, obj);
    robot(k).nulloPrec = robot(k).nullo;
    
    robot(k).dqtildesigma(:,i) = zeros(8,1);
    robot(k).hi = zeros(6,1);
    
    % Controllo adattativo
    [robot(k).pigreco, robot(k).dpigreco, robot(k).ddq(i,:)] = AdaptiveControl(k, i, contr_hint);
end

obj.f0(:,i) = zeros(3,1);
obj.mu0(:,i) = zeros(3,1);
obj.h0(:,i) = zeros(6,1);
obj.ddp0(:,i) = zeros(3,1);
obj.dp0(:,i) = zeros(3,1);
obj.pos(:,i) = [0 0 0.2625];

%Gravità oggetto
obj.g0 = [0 0 9.81]';

% Calcolo delle forze interne
for k=1:N
    robot(k).hi(:,i) = zeros(6,1);
    robot(k).fi(:,i) = zeros(3,1);
    robot(k).mui(:,i) = zeros(3,1);
    robot(k).thetai(:,i) = zeros(3,1);
    robot(k).G = eye(3);
    robot(k).alfa(:,i) = obj.g0;
    robot(k).betai(:,i) = zeros(3,1);
    robot(k).m(:,i) = zeros(3,1);
    robot(k).lam(:,i) = robot(k).alfa(:,i) - robot(k).G*robot(k).fi(:,i) - robot(k).thetai(:,i);
end
G = [robot(1).G robot(2).G robot(3).G robot(4).G];
obj.M0 = diag([3 3 3]);
pinvG = G'*(G*G')^-1;


for k=1:N
    robot(k).gam = [];
    for jj=0:N-1
        robot(k).gam = horzcat(robot(k).gam, robot(k).gamma(1:3,1+jj*6:3+jj*6));
    end
%     robot(k).gam = [robot(k).gamma(1:3,1:3) robot(k).gamma(1:3,7:9) ...
%         robot(k).gamma(1:3,13:15) robot(k).gamma(1:3,19:21)];
    robot(k).hinti(:,i) = (eye(3) - robot(k).gam*pinvG*robot(k).G)*robot(k).fi(:,i) - ...
        robot(k).gam*pinvG*robot(k).thetai(:,i);
end

t_regime = 0;
obj.dynamics = 0;

obj.extr = [];
obj = puntiContatto(obj, i);

ciclo


%%%%%%%%%%%%%%%%%Seconda parte di traiettoria%%%%%%%%%%%%%%%%%
obj.dynamics = 1;

contr_hint = 0;

time = 0;
kn1max = 0;
kn2max = 0;
kn3max = 0;
kn4max = 0;

% Posizioni iniziali dei robot concatenate per la seconda parte di
% traiettoria
% Task iniziale
sig_in = sig_fin;

% Task finale desiderato
sig1_fin = [0 0 0.8 0.7854 1.5708 -1.5882]';
sig2_fin = [0.49-delta 0.49-delta 0 4.7124 0 0 ...
    0.49-delta -0.49+delta 0 -1.5708 0 0 ...
    -0.49+delta -0.49+delta 0 -1.5708 0 0]';
sig_fin = vertcat(sig1_fin, sig2_fin);

% Durata traiettoria
tf_task = 3;
t_regime = 1;

% Inizializzazione parametri traiettoria
InitPlanningTask();

ciclo;



% % PER SIMULAZIONE PRESENTAZIONE
% %%%%%%%%%%%%%%%%%Seconda parte di traiettoria%%%%%%%%%%%%%%%%%
% obj.dynamics = 1;
% 
% contr_hint = 0;
% 
% time = 0;
% kn1max = 0;
% kn2max = 0;
% kn3max = 0;
% kn4max = 0;
% 
% % Posizioni iniziali dei robot concatenate per la seconda parte di
% % traiettoria
% % Task iniziale
% sig_in = sig_fin;
% 
% % Task finale desiderato
% sig1_fin = [-1 1 0.8 0.7854 1.5708 -1.5882]';
% sig2_fin = [0.49-delta 0.49-delta 0 4.7124 0 0 ...
%     0.49-delta -0.49+delta 0 -1.5708 0 0 ...
%     -0.49+delta -0.49+delta 0 -1.5708 0 0]';
% sig_fin = vertcat(sig1_fin, sig2_fin);
% 
% % Durata traiettoria
% tf_task = 3;
% t_regime = 1;
% 
% % Inizializzazione parametri traiettoria
% InitPlanningTask();
% 
% ciclo;





%%%%%%%%%%%%%%%%%Terza parte di traiettoria%%%%%%%%%%%%%%%%%
time = 0;
kn1max = 15;
kn2max = 7;
kn3max = 7;
kn4max = 3;

contr_hint = 0;

% Task iniziale deisderato
sig_in = sig_fin;

% Task finale desiderato
sig1_fin = [1.5000         0    0.8    0.7854    1.5708   -1.5882]';
sig2_fin = [0.49-delta    0.49-delta         0    4.7124         0         0 ...
    0.49-delta   -0.49+delta         0   -1.5708         0         0 ...
    -0.49+delta   -0.49+delta         0   -1.5708         0         0]';

sig_fin = vertcat(sig1_fin, sig2_fin);

% Durata traiettoria
tf_task = 5;
t_regime = 1;

% Inizializzazione parametri traiettoria
InitPlanningTask();
ciclo;



%%%%%%%%%%%%%%%%%Quarta parte di traiettoria%%%%%%%%%%%%%%%%%
time = 0;
kn1max = 0;
kn2max = 0;
kn3max = 0;
kn4max = 0;

contr_hint = 0;

% Posizioni iniziali dei robot concatenate per la seconda parte di
% traiettoria
% Task iniziale
sig_in = sig_fin;

% Task finale desiderato
sig1_fin = [1.5000         0    0.4958    0.7854    1.5708   -1.5708]';
sig2_fin = [0.49-delta    0.49-delta         0    4.7124         0         0 ...
    0.49-delta   -0.49+delta         0   -1.5708         0         0 ...
    -0.49+delta   -0.49+delta         0   -1.5708         0         0]';
sig_fin = vertcat(sig1_fin, sig2_fin);

% Durata traiettoria
tf_task = 3;
t_regime = 20;

% Inizializzazione parametri traiettoria
InitPlanningTask();

%[i, sig_des, dsig_des, ddsig_des] = ciclo(i, sig_des, dsig_des, ddsig_des, t_regime);
obj.dynamics = 1;
ciclo;





% %%%%%%%%%%%%%%%%%Quinta parte di traiettoria%%%%%%%%%%%%%%%%%
% time = 0;
% kn1max = 15;
% kn2max = 5;
% kn3max = 5;
% kn4max = 0;
% 
% contr_hint = 1;
% 
% % Posizioni iniziali dei robot concatenate per la seconda parte di
% % traiettoria
% % Task iniziale
% sig_in = sig_fin;
% 
% % Task finale desiderato
% sig1_fin = [1.5000         0    0.4958    0.7854    1.5708   -1.5708]';
% sig2_fin = [0.8707    0.8708         0    4.7124         0         0 ...
%     0.8708   -0.8707         0   -1.5708         0         0 ...
%     -0.8707   -0.8708         0   -1.5708         0         0]';
% sig_fin = vertcat(sig1_fin, sig2_fin);
% 
% % Durata traiettoria
% tf_task = 3;
% t_regime = 7;
% 
% % Inizializzazione parametri traiettoria
% InitPlanningTask();
% 
% %[i, sig_des, dsig_des, ddsig_des] = ciclo(i, sig_des, dsig_des, ddsig_des, t_regime);
% obj.dynamics = 0;
% ciclo;




