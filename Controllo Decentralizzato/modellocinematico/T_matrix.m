function T=T_matrix(zyz)

sphi = sin(zyz(1));
cphi = cos(zyz(1));
stheta = sin(zyz(2));
ctheta = cos(zyz(2));

T = [0 -sphi cphi*stheta; 0 cphi sphi*stheta; 1 0 ctheta];