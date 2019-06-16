function [dJa] = mat_djac_analit(qDH, dqDH,  A0b)


J = mat_jac_geom(qDH, A0b);
dJ = mat_djac_geom(qDH, dqDH, A0b(1:3, 1:3));
dJ(1,7) = 0;
dJ(2,8) = 0;
Ja = mat_jac_analit(qDH, A0b);
x = cindir(qDH, A0b);
dx = Ja*dqDH;
T = T_matrix(x(4:6));
dT=dT_matrix(x(4:6), dx(4:6));


dJa = blkdiag(eye(3), T)^-1*(dJ-blkdiag(zeros(3), dT)*Ja); 