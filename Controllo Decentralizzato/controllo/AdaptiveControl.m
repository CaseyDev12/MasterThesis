function [pigreco, dpigreco, ddq] = AdaptiveControl(k, i, contr_hint)

global T Kpi kq robot 

Y = Yqdqdqrddqr_mex(robot(k).qActual, robot(k).dqActual, robot(k).dqsigma(i,:), robot(k).ddqsigma(i,:));

dpigreco = (Kpi^(-1)) * Y' * robot(k).dqtildesigma(:,i);

pigreco = robot(k).pigreco + robot(k).dpigreco*T;
%pigreco = carico(0);


JTh = robot(k).Ja'*robot(k).hi(:,i);

if(contr_hint == 1)
    tau = Y*pigreco + kq*robot(k).dqtildesigma(:,i) + robot(k).deltaTau(:,i);% + JTh;
else 
    tau = Y*pigreco + kq*robot(k).dqtildesigma(:,i) + JTh;
end

robot(k).tau(:,i) = tau;

ddq = forwardDynamics(tau, robot(k).qActual, robot(k).dqActual, JTh);

end

