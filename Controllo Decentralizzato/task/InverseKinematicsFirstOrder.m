function [dqsigma] = InverseKinematicsFirstOrder(k, KN, i, contr_hint)

global robot

robot(k).nullo(1,:) = NulloFirstOrder(robot(k).qActual, robot(k).pinvJa, robot(k).Ja, KN);

if(contr_hint == 1)
    dqsigma = robot(k).pinvJa*(robot(k).gamma*robot(k).u_stim + ...
        [robot(k).ufi(:,i); zeros(3,1)]) + robot(k).nullo';
else
    dqsigma = robot(k).pinvJa*(robot(k).gamma*robot(k).u_stim) + robot(k).nullo';
end

end



