function [J] = mat_jac_geom(q, A0b, Ane)
%Calcola lo Jacobiano geometrico dello Smart Six non in simbolico
%Input:
%      qDH; variabili di giunti in convenzione DH e in rad
%Output:
%       J: jacobiano geometrico

%Marino: 09/03/2010


if(size(q, 2) ~= 8)
    qDH = q';
else
    qDH = q;
end
    

[a, d, alpha] = dh_table;


%seni e coseni degli angoli
ctheta = cos(qDH);
stheta = sin(qDH);
calpha = cos(alpha);
salpha = sin(alpha);


     T = eye(4);
     if(length(qDH)>6)
     T(1,4) = T(1,4) +  0*qDH(7);
     T(2,4) = T(2,4) +  0*qDH(8);
     T(3,4) = 0; %0.2985;
     end
     %T = A0b*T; 
% T = eye(4); %qDH(7:8) = 0;
temp = qDH;
temp(7:8) = 0;
p = zeros(6,1);
p(:, 1) = cindir(temp,  eye(4), Ane); %cinematica diretta

% zi = T(1:3, 3); pi = T(1:3, 4);
% J = [cross(zi, (p-pi); zi];
J = zeros(6,length(qDH));
for j=1:6
    zi = T(1:3, 3); pi = T(1:3, 4);
    a_ = zi;
    b_ = (p(1:3)-pi);
    prodvett = [a_(2,:).*b_(3,:)-a_(3,:).*b_(2,:)
     a_(3,:).*b_(1,:)-a_(1,:).*b_(3,:)
     a_(1,:).*b_(2,:)-a_(2,:).*b_(1,:)];
 %cross(zi, (p(1:3)-pi))
    J(:,j) = [prodvett; zi];
    
    T =T*[ctheta(j) -stheta(j)*calpha(j) stheta(j)*salpha(j) a(j)*ctheta(j);
          stheta(j)  ctheta(j)*calpha(j) -ctheta(j)*salpha(j) a(j)*stheta(j);
             0           salpha(j)             calpha(j)            d(j);
             0                0                  0                    1];

end

% temp(:,1) = [;
%J(1:2, 7) = A0b(1:2,1); J(1:2, 8) = A0b(1:2,2);
 if(length(qDH)>6)
 J(1,7) = 1;
 J(2,8) = 1;
 end
 R0b = A0b(1:3, 1:3);
 J = blkdiag(R0b, R0b)*J;