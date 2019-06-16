function ddqsigma = InverseKinematicsSecondOrder(k, i, ddsig_des, dsig_des, dqsigma, contr_hint, obj)

global Jsig robot ksigma invJsig T


if(obj.dynamics==0)
    
    dsigma = Jsig*robot(k).dx_stim(:,i);
    dgamma = ddsig_des + ksigma*(dsig_des - dsigma);
    dustim = invJsig*dgamma;

    ddq0 = (robot(k).nullo - robot(k).nulloPrec)/T;

    % Calcolo ddqsigmai
    if(contr_hint==1)
        if(i==1)
            dufi = zeros(3,1);
        else
            dufi = (robot(k).ufi(:,i) - robot(k).ufi(:,i-1))/T;
        end
        ddqsigma = robot(k).pinvJa*(robot(k).gamma*dustim + [dufi; zeros(3,1)])...
            + robot(k).dpinvJa*robot(k).Ja*dqsigma' + ddq0';
    else
        ddqsigma = robot(k).pinvJa*(robot(k).gamma*dustim) + robot(k).dpinvJa*robot(k).Ja*dqsigma' + ddq0';
    end

else
    
    dsigma = Jsig(1:6,:)*robot(k).dx_stim(:,i);
    dgamma = ddsig_des(1:6) + ksigma*(dsig_des(1:6) - dsigma);
    dustim = invJsig(:,1:6)*dgamma;

    ddq0 = (robot(k).nullo - robot(k).nulloPrec)/T;

    % Calcolo ddqsigmai
    if(contr_hint==1)
        if(i==1)
            dufi = zeros(3,1);
        else
            dufi = (robot(k).ufi(:,i) - robot(k).ufi(:,i-1))/T;
        end
        ddqsigma = robot(k).pinvJa*(robot(k).gamma*dustim + [dufi; zeros(3,1)])...
            + robot(k).dpinvJa*robot(k).Ja*dqsigma' + ddq0';
    else
        ddqsigma = robot(k).pinvJa*(robot(k).gamma*dustim) + robot(k).dpinvJa*robot(k).Ja*dqsigma' + ddq0';
    end
    
end

end
