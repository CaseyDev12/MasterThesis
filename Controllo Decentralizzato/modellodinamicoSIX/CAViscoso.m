function  Attr_Viscoso = CAViscoso(dqDH)
% Ingressi:
%        dqDH : vettori 6x1 secondo convenzioni DH in rad/s
% 
% Uscite:
%       Attr_Viscoso: Coppie di Attrito Viscoso F*dqDH in convenzione DH
%
% Note:
%   le coppie in uscita sono in convenzione DH e sono quelle richieste agli attuatori (a valle dei riduttori)
%
% File letti:
%            costanti.m : definizione delle costanti dinamiche utilizzate

% DUBBI: 
%            non sono sicuro sulla conversione da cioppie COMAU a coppie DH
%            e sul fatto che siano presenti le velocit� dei motori

% **********************************************************************************************************************
% Costanti
% **********************************************************************************************************************

% Lettura dei dati registrati in "costanti.m"
  % addpath('../modello SIX/')
  %costanti;


Attr_Viscoso = zeros(8,1);

  
  %vettore dei parametri di attrito viscoso
  %fv = DYN.MODEL(42:2:52); 
  %fv = theta(42:2:52); 
  fv =[ -0.226577007285678
   0.307912520564962
   0.300193611250022
  -0.034429350797965
   0.063358540292740
   0.022725708748977];
   dq =  zeros(6,1);
  dq = dh2comau_vel(dqDH*180/pi);
  
  % Velocit� dei motori
  dqm =  zeros(6,1);
  Kr = [ -147.8019         0         0         0         0         0
         0  153.0000         0         0         0         0
         0         0  141.0000         0         0         0
         0         0         0  -51.4170         0         0
         0         0         0         0   81.0000         0
         0         0         0         0   -1.0000   50.0000];
  dqm = (Kr*dq) * (pi/180); % in convenzione COMAU in rad/sec


Phi = zeros(6,6);
for i=1:6
  Phi(i, i) = dqm(i);
end
H = [    -1     0     0     0     0     0
     0     1     0     0     0     0
     0     0    -1     0     0     0
     0     0     0    -1     0     0
     0     0     0     0     1     0
     0     0     0     0     0    -1];
%Attr_Viscoso =  zeros(6,1);
Attr_Viscoso(1:6) = (H')^-1*Phi*fv;
Attr_Viscoso(7:8) = 10*dqDH(7:8);
