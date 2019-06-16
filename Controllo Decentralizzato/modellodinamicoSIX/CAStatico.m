function  Attr_Statico = CAStatico(dqDH);
%Calcola le coppie di Attrito Statico
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
%            e sul fatto che siano presenti le velocità dei motori

% **********************************************************************************************************************
% Costanti
% **********************************************************************************************************************

% Lettura dei dati registrati in "costanti.m"
  % addpath('../modello SIX/')
  costanti;
 
  
  %vettore dei parametri di attrito viscoso
  fs = DYN.MODEL(41:2:52); 
%   fs = theta(41:2:52); 
  
  dq(:, 1) = dh2comau_vel(dqDH*180/pi);
  
  % Velocità dei motori
  dqm = (Kr*dq) * (pi/180); % in convenzione COMAU in rad/sec


Phi = zeros(6,6);
for i=1:6
if abs(dqm(i)) > soglia
          Phi(i,i) = dqm(i)/abs(dqm(i));
        else
          Phi(i,i) = dqm(i)/soglia;
        end % if
end

Attr_Statico = (H')^-1*Phi*fs;
