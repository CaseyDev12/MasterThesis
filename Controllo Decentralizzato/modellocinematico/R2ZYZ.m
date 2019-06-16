 function [phi, theta, psi] = R2ZYZ(R, varargin)
%Coverte la Matrice R in ingresso in angoli di Eulero ZYZ
%varargin:

phi = atan2(R(2,3), R(1,3));
theta = atan2((R(1,3)^2 + R(2,3)^2)^(1/2), R(3,3));
psi = atan2(R(3,2), -R(3,1));

if(sin(theta)<10^-6) %singolarita' di rappresentazione
    if(abs(abs(theta)-pi)<10^-6)
        phi = atan2(-R(1,2), R(2,2));
        psi =0 ;
        theta = pi;
    else
    phi = atan2(R(2,1), R(1,1));
        psi = 0;
    end
end


% %Tutti gli angoli li si riporta in [-pi pi) ?
% 
% if(phi < -pi || phi >= pi)
%     phi = phi - sign(phi)*2*pi;
% end
% 
% % if(theta < -theta || theta >= pi)
% %     theta= psi - sign(teta)*2*pi;
% % end
% 
% if(psi < -pi || phi >= pi)
%     psi= psi - sign(psi)*2*pi;
% end
