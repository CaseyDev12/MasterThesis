clear all

global N T robot sig_in sig_fin Jsig ksigma invJsig Kpi kq

% Numero di robot
N = 4;

% Vicini di ciascun robot
robot(1).Ni = [2 3 4];
robot(2).Ni = [1 3 4];
robot(3).Ni = [1 2 4];
robot(4).Ni = [1 2 3];


% Passo di campionamento
T = 0.001;

% Matrici di rototraslazione
robot(1).A = [1   0   0   -2;
              0   1   0    0;
              0   0   1    0.2985;
              0   0   0    1];
robot(2).A = [0   1   0   0;
             -1   0   0   2;
              0   0   1   0.2985;
              0   0   0   1];
robot(3).A = [-1    0   0   2;
               0   -1   0   0;
               0    0   1   0.2985;
               0    0   0   1];
robot(4).A = [ 0   -1   0    0;
               1    0   0   -2;
               0    0   1    0.2985;
               0    0   0    1];


robot(1).Ane = [0   0   1   0;
    0   1   0   -0.0003;
    -1   0   0    0.1079;
    0   0   0    1];
robot(2).Ane = robot(1).Ane;
robot(3).Ane = robot(1).Ane;
robot(4).Ane = robot(1).Ane;

% Matrici gamma
for i=1:N
    robot(i).gamma = [repmat(zeros(6,6),1,i-1) eye(6) repmat(zeros(6,6),1,N-i)];
end


% Posizioni iniziali dei robot concatenate
for i=1:N
    robot(i).q0 = [0 -35*pi/180 20*pi/180 0 -75*pi/180 pi/2 0 0];
%     robot(i).q0 = [0 -35*pi/180 20*pi/180 0 -75*pi/180 pi/2 0.36 0];
    robot(i).dq0 = zeros(1,8);
end

% Calcolo le x iniziali dei robot in modo da poter calcolare il task
% assoluto iniziale
for i=1:N
    robot(i).x0 = cindir_mex(robot(i).q0, robot(i).A, robot(i).Ane);
end


% dq0 e dq0Prec per calcolare ddq0
for i=1:N
    robot(i).nullo = zeros(1,8);
    robot(i).nulloPrec = zeros(1,8);
end


% Calcolo il task assoluto iniziale
sigperN = zeros(1,6);
for i=1:N
    sigperN = sigperN + robot(i).x0;
end
sig1_in = (1/N)*sigperN';

% Calcolo il task relativo iniziale
sig2_in = zeros(3*(N-1),1);
for i=0:N-2
    sig2_in(1+i*6:6+i*6,1) = robot(i+2).x0' - robot(i+1).x0';
end

% Task complessivo iniziale
sig_in = vertcat(sig1_in, sig2_in);



% Task finale desiderato
delta = 0.03;
sig1_fin = [ 0         0    0.4958    0.7854    1.5708   -1.5708]';
sig2_fin = [0.49-delta    0.49-delta         0    4.7124         0         0 ...
            0.49-delta  -0.49+delta         0   -1.5708         0         0 ...
           -0.49+delta   -0.49+delta         0   -1.5708         0         0]';

sig_fin = vertcat(sig1_fin, sig2_fin);


% Calcolo jacobiano del task
Jsig = Jac_task(N);
invJsig = Jsig^(-1);

% Inizializzazione task
dsig0 = zeros(N*6,1);
ddsig0 = zeros(N*6,1);


% Parametri per il controllo
for i=1:N
    ran = 0 + (10-0).*rand(length(carico(0)),1);
    robot(i).pigreco = carico(0) + carico(0).*ran./100;
    robot(i).dpigreco = zeros(56,1);
end

% Guadagno ksigma in gamma
ksigma = 4; %(non va bene diminuire)

% Guadagni controllo
kq = 80; %(non va bene diminuire)
Kpi = (150)*eye(56);


% Parametri osservatore
robot(1).x_stim = [robot(1).x0, robot(2).x0+robot(2).x0*5/100, robot(3).x0-robot(3).x0*5/100, robot(4).x0+robot(4).x0*10/100]';
robot(2).x_stim = [robot(1).x0-robot(1).x0*10/100, robot(2).x0, robot(3).x0-robot(3).x0*5/100, robot(4).x0+robot(4).x0*10/100]';
robot(3).x_stim = [robot(1).x0-robot(1).x0*5/100, robot(2).x0+robot(2).x0*2/100, robot(3).x0, robot(4).x0+robot(4).x0*5/100]';
robot(4).x_stim = [robot(1).x0+robot(1).x0*3/100, robot(2).x0+robot(2).x0*5/100, robot(3).x0-robot(3).x0*10/100, robot(4).x0]';

% robot(1).x_stim = [robot(1).x0, robot(2).x0, robot(3).x0, robot(4).x0]';
% robot(2).x_stim = [robot(1).x0, robot(2).x0, robot(3).x0, robot(4).x0]';
% robot(3).x_stim = [robot(1).x0, robot(2).x0, robot(3).x0, robot(4).x0]';
% robot(4).x_stim = [robot(1).x0, robot(2).x0, robot(3).x0, robot(4).x0]';

ko = 10;


% Dinamica oggetto
obj.massa = 3;
obj.Io = diag([0.05 0.05 0.1]);

% Guadagno per il calcolo delle forze interne
Ktheta = 360; % Non cambia niente per le oscillazioni delle coppie
KP = 15000;
KD = 2*sqrt(KP*obj.massa);


% Parametri per controllo forze interne
kf = 0.01;
eps = 1e-3;


% Forze interne desiderate
for k=1:N
    robot(k).hint_des = [0 0 0]';
end

% Con o senza controllo delle forze interne
contr_hint = 0;



