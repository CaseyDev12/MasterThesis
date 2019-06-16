function [out R] = cindir(q, A0b, Ane)

%Calcola la cinematica diretta dello SmartSix
%Input:
%      qDH; variabili di giunti in convenzione DH e in rad
%Output:
%       x:     posizione x organo terminale
%       y:     posizione y organo terminale
%       z:     posizione z organo terminale
%       phi:   orientamento phi organo terminale in rad
%       theta: orientamento theta organo terminale in rad
%       psi:   orientamento psi organo terminale in rad
%varargin: previous vector for orientation euler angles correction
if(size(q, 2) ~= 8)
    qDHn = q';
else
    qDHn = q;
end

out = zeros(size(qDHn,1),6);

[a, d, alpha] = dh_table;

for i=1:size(qDHn,1)
    qDH = qDHn(i, :);
    ctheta = cos(qDH);
    stheta = sin(qDH);
    calpha = cos(alpha);
    salpha = sin(alpha);
    
    T = eye(4);
    if(length(qDH)>6)
        T(1,4) = T(1,4) +  qDH(7);
        T(2,4) = T(2,4) +  qDH(8);
        T(3,4) = 0; %0.2985;
    end
    T = A0b*T;
    for j=1:6
        T =T*[ctheta(j) -stheta(j)*calpha(j) stheta(j)*salpha(j) a(j)*ctheta(j);
            stheta(j)  ctheta(j)*calpha(j) -ctheta(j)*salpha(j) a(j)*stheta(j);
            0           salpha(j)             calpha(j)            d(j);
            0                0                  0                    1];
    end
    T = T*Ane;
    x = T(1, 4);
    y = T(2, 4);
    z = T(3, 4);
    [phi, theta, psi] = R2ZYZ(T(1:3, 1:3));
    R = T(1:3, 1:3);
    out(i, :) = [x y z phi theta psi]';
    
    
    %
    if i>1
        for k=4:6
            if abs(out(i, k)-out(i-1, k))>0.5
                out(i,k) = out(i, k)+sign(out(i-1, k)-out(i, k))*round(abs(out(i, k)-out(i-1, k))/(pi))*(pi);
            end
        end
    end
end