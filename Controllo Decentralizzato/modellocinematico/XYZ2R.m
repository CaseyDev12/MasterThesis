function [R] = XYZ2R(in)
%Bryant angles
cos_phi = cos(in(1));
sin_phi = sin(in(1));

cos_teta = cos(in(2));
sin_teta = sin(in(2));

cos_psi = cos(in(3));
sin_psi = sin(in(3));




R1 = [1 0 0; 
    0 cos_phi -sin_phi; 
    0 sin_phi cos_phi];

R2 = [cos_teta 0 sin_teta; 
    0 1 0; 
    -sin_teta 0 cos_teta];

R3 = [cos_psi -sin_psi 0; 
      sin_psi cos_psi 0;
       0 0 1];

R = R1*R2*R3;