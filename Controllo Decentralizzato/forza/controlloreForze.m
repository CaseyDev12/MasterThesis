function [robot] = controlloreForze(robot, kf, eps, i, pinvG, k)

if(norm(robot(k).dqtildesigma(:,i))^2 > eps)
    robot(k).ki(i) = (norm(robot(k).gamma*robot(k).u_stim - robot(k).dx(:,i)) * ...
        norm(robot(k).htilde(:,i) + kf*robot(k).ufi(:,i))) / ...
        norm(robot(k).dqtildesigma(:,i))^2;
    
    robot(k).ki(i) = robot(k).ki(i);
else
    robot(k).ki(i) = (norm(robot(k).gamma*robot(k).u_stim - robot(k).dx(:,i)) * ...
        norm(robot(k).htilde(:,i) + kf*robot(k).ufi(:,i))) / eps;
end

robot(k).deltaTau(:,i) = robot(k).Ja(1:3,:)' * (robot(k).gam * (pinvG*robot(k).G*robot(k).fi(:,i) ...
    + pinvG*robot(k).thetai(:,i)) + robot(k).hint_des + kf*robot(k).ufi(:,i)) ...
    + robot(k).ki(i) * robot(k).dqtildesigma(:,i);

end

