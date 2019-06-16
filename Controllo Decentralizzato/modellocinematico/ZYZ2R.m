function [R] = ZYZ2R(in)

cos_phi = cos(in(1));
sin_phi = sin(in(1));

cos_teta = cos(in(2));
sin_teta = sin(in(2));

cos_psi = cos(in(3));
sin_psi = sin(in(3));


R = [cos_phi*cos_teta*cos_psi-sin_phi*sin_psi  -cos_phi*cos_teta*sin_psi-sin_phi*cos_psi         cos_phi*sin_teta;
     sin_phi*cos_teta*cos_psi+cos_phi*sin_psi  -sin_phi*cos_teta*sin_psi+cos_phi*cos_psi          sin_phi*sin_teta;
     -sin_teta*cos_psi                                 sin_teta*sin_psi                                  cos_teta];