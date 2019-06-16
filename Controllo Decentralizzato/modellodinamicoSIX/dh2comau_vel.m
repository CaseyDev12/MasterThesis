function dqcomau = dh2comau_vel(dqdh)
% Converte le velocit�/accelerazioni dei giunti dalla convenzione COMAU alla convenzione DH
%
% Ingressi: 
%   dqdh   : vettore 6x1 delle velocit� (o accelerazioni) in convenzione DH
% Uscite:
%   dqcomau: vettore 6x1 delle velocit� (o accelerazioni) in convenzione
%   COMAU

% Note:
%   le unit� di misura sono ininfluenti
%   IL FILE E' STATO CREATO DA MARINO


dqcomau = zeros(6,1);
dqcomau(1,1) = -dqdh(1);
dqcomau(2,1) =  dqdh(2);
dqcomau(3,1) = -dqdh(3);
dqcomau(4,1) = -dqdh(4);
dqcomau(5,1) =  dqdh(5);
dqcomau(6,1) = -dqdh(6);


% dqdh(1) = -dqcomau(1);
% dqdh(2) =  dqcomau(2);
% dqdh(3) = -dqcomau(3);
% dqdh(4) = -dqcomau(4);
% dqdh(5) =  dqcomau(5);
% dqdh(6) = -dqcomau(6);
