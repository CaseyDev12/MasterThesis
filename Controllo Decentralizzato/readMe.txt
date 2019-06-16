Nel vettore q i giunti prismatici sono alla fine.

addpath('C:\Users\Ines\Google Drive\Tesi Laurea Magistrale\Controllo Decentralizzato\modellocinematico');
addpath('C:\Users\Ines\Google Drive\Tesi Laurea Magistrale\Controllo Decentralizzato\modellodinamicoSIX');
addpath('C:\Users\Ines\Google Drive\Tesi Laurea Magistrale\Controllo Decentralizzato\VrepLibraryFunctions');
addpath('C:\Users\Ines\Google Drive\Tesi Laurea Magistrale\Controllo Decentralizzato\osservatore');
addpath('C:\Users\Ines\Google Drive\Tesi Laurea Magistrale\Controllo Decentralizzato\controllo');
addpath('C:\Users\Ines\Google Drive\Tesi Laurea Magistrale\Controllo Decentralizzato\dinamicaErroreStima');
addpath('C:\Users\Ines\Google Drive\Tesi Laurea Magistrale\Controllo Decentralizzato\task');
addpath('C:\Users\Ines\Google Drive\Tesi Laurea Magistrale\Controllo Decentralizzato\forza');
addpath(genpath('./'));
savepath;

Ab01 = [1   0   0   -2; 
      0   1   0    0; 
      0   0   1    0.2985;
      0   0   0    1];

Ane1 = [0   -1   0   0;
        1   0   0    0;
        0   0   1    0.0849;
        0   0   0    1];


Ab02 = [ 0   1   0   0;
        -1   0   0   2;
         0   0   1   0.2985;
         0   0   0   1];

Ane2 = [0   -1   0   0;
        1   0   0    0;
        0   0   1    0.0849;
        0   0   0    1];

Ab03 = [-1    0   0   2; 
         0   -1   0   0; 
         0    0   1   0.2985; 
         0    0   0   1];

Ane3 = [0   -1   0   0;
        1   0   0    0;
        0   0   1    0.0849;
        0   0   0    1];

Ab04 = [0   -1   0    0;
        1    0   0   -2;
        0    0   1    0.2985;
        0    0   0    1];

Ane4 = [0   -1   0   0;
        1   0   0    0;
        0   0   1    0.0849;
        0   0   0    1];


NULLO
limiti_giunto_inf = [-2.9671   -3.0543   -1.5708   -3.6652   -2.2689  -43.9823 -1000 -1000];
limiti_giunto_sup = [2.9671    1.1345    1.3963    3.6652    2.2689   50.2655 1000 1000];
q_media = (limiti_giunto_inf + limiti_giunto_sup)/2;
syms q1 q2 q3 q4 q5 q6 q7 q8
temp(1)=((q1-q_media(1))/(limiti_giunto_sup(1)-limiti_giunto_inf(1)))^2;
temp(2)=((q2-q_media(2))/(limiti_giunto_sup(2)-limiti_giunto_inf(2)))^2;
temp(3)=((q3-q_media(3))/(limiti_giunto_sup(3)-limiti_giunto_inf(3)))^2;
temp(4)=((q4-q_media(4))/(limiti_giunto_sup(4)-limiti_giunto_inf(4)))^2;
temp(5)=((q5-q_media(5))/(limiti_giunto_sup(5)-limiti_giunto_inf(5)))^2;
temp(6)=((q6-q_media(6))/(limiti_giunto_sup(6)-limiti_giunto_inf(6)))^2;
temp(7)=((q7-q_media(7))/(limiti_giunto_sup(7)-limiti_giunto_inf(7)))^2;
temp(8)=((q8-q_media(8))/(limiti_giunto_sup(8)-limiti_giunto_inf(8)))^2;
w = (temp(1)+temp(2)+temp(3)+temp(4)+temp(5)+temp(6)+temp(7)+temp(8));
gradiente = gradient(w);


