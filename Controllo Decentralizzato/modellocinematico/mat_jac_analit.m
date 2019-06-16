function [Ja] = mat_jac_analit(qDH, A0b, Ane)


[J] = mat_jac_geom(qDH, A0b, Ane);
x = cindir(qDH, A0b, Ane);
T = T_matrix(x(4:6));

Ja = blkdiag(eye(3), T)^-1*J;