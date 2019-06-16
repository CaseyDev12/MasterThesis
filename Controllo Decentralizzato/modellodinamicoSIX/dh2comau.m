function qcomau = dh2comau(qdh)
% Converte le posizioni dei giunti dalla convenzione DH(gradi) alla
% convenzione Comau(gradi)
% 
% Ingressi:
%    qdh   : vettore 6x1 delle posizioni in convenzione DH in gradi 
% Uscite:
%    qcomau: vettore 6x1 delle posizioni in convenzione COMAU in gradi

% Note:
%   le unita' di misura devono essere necessariamente in gradi
%   IL FILE E' STATO CREATO DA MARINO


qcomau = zeros(6,1);
qcomau(1, 1) = -qdh(1);
qcomau(2, 1) =  qdh(2) + 90;
qcomau(3, 1) = -qdh(3) - 90;
qcomau(4, 1) = -qdh(4);
qcomau(5, 1) =  qdh(5);
qcomau(6, 1) = -qdh(6) + 180;

