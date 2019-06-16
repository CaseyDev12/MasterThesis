
limiti_coppia =[877.8982 1462.6928 558.3315 46.3556 58.4212 46.8812];


%%%%%%%%%%%%%%%%%%%LIMITI FISICI DEL MANIPOLATORE%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
limiti_giunto_inf = [-170 -85  -170  -210 -130 -360]*pi/180; %da file CAD
limiti_giunto_sup = [170  155    0   +210 +130 +360]*pi/180; %da file CAD
dqmaxcomau = [2.433 2.7925 2.9671 7.8534 6.5443 9.5986]; %velocita' massime ai giunti rad/s
ddqmaxcomau = [20 20 20 35 45 45]; %accelerazioni massime ai giunti rad/s^2
freq_max = [7.47921986 6.20555 5.99255972 6.96794985 6.54554985 6.47969985]*2;
dddqmaxcomau = ddqmaxcomau.*freq_max; 


limitiSupDH = [2.9671    1.1345    1.3963    3.6652    2.2689   50.2655];
limitiInfDH = [-2.9671   -3.0543   -1.5708   -3.6652   -2.2689  -43.9823];



