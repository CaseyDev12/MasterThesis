%%%%%%%%%%%%%%%%%%%LIMITI FISICI DEL MANIPOLATORE%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
dqmaxcomau = [2.433 2.7925 2.9671 7.8534 6.5443 9.5986]; %velocità massime ai giunti rad/s
ddqmaxcomau = [15 20 20 30 25 25]; %accelerazioni massime ai giunti rad/s^2
limiti_coppia =[877.8982 1462.6928 558.3315 46.3556 58.4212 46.8812];
limiti_giunto_inf = [-170 -85  -170  -210 -130 -360]*pi/180; %da file CAD
limiti_giunto_sup = [170  155    0   +210 +130 +360]*pi/180; %da file CAD
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  