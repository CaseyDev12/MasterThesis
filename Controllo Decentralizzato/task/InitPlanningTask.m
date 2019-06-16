function InitPlanningTask()

global sig_in sig_fin tf_task s_punto_task_pos s_punto_task_or N
global s_pp_pos s_pp_or tc_pos tc_or sub_pos sub_or L_pos L_or

s_punto_task_pos = [];
s_punto_task_or = [];
s_pp_pos = [];
s_pp_or = [];
tc_pos = [];
tc_or = [];
sub_pos = [];
sub_or = [];
L_pos = [];
L_or = [];

% Lunghezza traiettoria 
for i=0:N-1
    L_pos(i+1) = norm(sig_fin(1+i*6:3+i*6)-sig_in(1+i*6:3+i*6));
    L_or(i+1) = norm(sig_fin(4+i*6:6+i*6)-sig_in(4+i*6:6+i*6));
end

% Punto iniziale e finale del percorso
si = 0;
sf_pos = L_pos;
sf_or = L_or;

for i=1:N
    s_punto_task_pos(i) = 3*abs(sf_pos(i)-si)/(2*tf_task);
    s_punto_task_or(i) = 3*abs(sf_or(i)-si)/(2*tf_task);
end


% Istante di tempo in cui si raggiunge la velocità massima
for i=1:N
    tc_pos(i) = (si-sf_pos(i)+s_punto_task_pos(i)*tf_task)/s_punto_task_pos(i);
    tc_or(i) = (si-sf_or(i)+s_punto_task_or(i)*tf_task)/s_punto_task_or(i);
end

% Accelerazione
for i=1:N
    s_pp_pos(i) = s_punto_task_pos(i)/tc_pos(i);
    s_pp_or(i) = s_punto_task_or(i)/tc_or(i);
end

% Differenza tra task finale e iniziale 
for i=0:N-1
    sub_pos(:,i+1) = sig_fin(1+i*6:3+i*6) - sig_in(1+i*6:3+i*6);
    sub_or(:,i+1) = sig_fin(4+i*6:6+i*6) - sig_in(4+i*6:6+i*6);
end

end

