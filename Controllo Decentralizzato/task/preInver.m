function preInver(i, k)

global robot T

if i==1
    robot(k).qActual = robot(k).q0;
    robot(k).dqActual = robot(k).dq0;
    robot(k).Ja = mat_jac_analit_mex(robot(k).qActual, robot(k).A, robot(k).Ane);
    robot(k).pinvJa = robot(k).Ja'*(robot(k).Ja*robot(k).Ja')^(-1);
    robot(k).dpinvJa = zeros(8,6);
else
    robot(k).qActual = robot(k).q(i,:);
    robot(k).dqActual = robot(k).dq(i,:);
    robot(k).pinvJaPrec = robot(k).pinvJa;
    robot(k).Ja = mat_jac_analit_mex(robot(k).qActual, robot(k).A, robot(k).Ane);
    robot(k).pinvJa = robot(k).Ja'*(robot(k).Ja*robot(k).Ja')^(-1);
    robot(k).dpinvJa = (robot(k).pinvJa - robot(k).pinvJaPrec) / T;
end

end

