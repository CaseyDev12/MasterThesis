 function [phi, theta, psi] = R2XYZ(R, varargin)
%Coverte la Matrice R in ingresso in angoli di Eulero ZYZ
%varargin:

theta = asin(R(1,3));

if(abs(cos(theta))>10^-10)
phi = atan2(-R(2,3)/cos(theta), R(3,3)/cos(theta));
psi = atan2(-R(1,2)/cos(theta), R(1,1)/cos(theta));

else %singolarita' di rappresentazione
    if(abs(theta-pi/2)<10^-5)
        phi = atan2(R(2,1), -R(3,1));
        psi =0 ;
        theta = pi/2;
    else
        phi = atan2(-R(2,1), R(3,1));
        psi =0 ;
        theta = -pi/2;
        
        
        
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
