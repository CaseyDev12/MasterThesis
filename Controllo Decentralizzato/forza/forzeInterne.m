function [robot, G, pinvG] = forzeInterne(Ktheta, T, N, obj, robot, i)


if (obj.dynamics==1)
    
    % Calcolo la velocità stimata dell'oggetto
    for k=1:N
        robot(k).dp0(:,i) = robot(k).dp0(:,i-1) + robot(k).ddp0(:,i-1)*T;
    end
    
    % Calcolo delle forze interne
    G = [robot(1).G robot(2).G robot(3).G robot(4).G];
    pinvG = G'*(G*G')^-1;
    
    for k=1:N
%         robot(k).m(:,i) = robot(k).m(:,i-1) + robot(k).dm(:,i-1)*T;
%         robot(k).m(:,i) = obj.massa * robot(k).dp0(:,i); 
        robot(k).m(:,i) = obj.massa*obj.dp0(:,i);
        robot(k).betai(:,i) = robot(k).betai(:,i-1) + robot(k).lam(:,i-1)*T;       
        robot(k).thetai(:,i) = Ktheta*(robot(k).betai(:,i) + robot(k).m(:,i));
        robot(k).alfa(:,i) = obj.massa*obj.g0;
        robot(k).lam(:,i) = robot(k).alfa(:,i) - robot(k).G*robot(k).fi(:,i) - robot(k).thetai(:,i);
%         robot(k).dm(:,i) = robot(k).G*robot(k).fi(:,i) + robot(k).thetai(:,i) - obj.massa*obj.g0;
    end
    
    for k=1:N
        robot(k).hinti(:,i) = (eye(3) - robot(k).gam*pinvG*robot(k).G)*robot(k).fi(:,i) - ...
            robot(k).gam*pinvG*robot(k).thetai(:,i);
    end
    
    for k=1:N
        robot(k).ddp0(:,i) = obj.massa^-1 * (-obj.massa*obj.g0 + robot(k).G*robot(k).fi(:,i) + robot(k).thetai(:,i));
    end
    
else
    
    for k=1:N
        robot(k).dp0(:,i) = zeros(3,1);
    end
    
    % Calcolo delle forze interne
    G = [robot(1).G robot(2).G robot(3).G robot(4).G];
    pinvG = G'*(G*G')^-1;
    for k=1:N
%         if(i==1)
            robot(k).m(:,i) = zeros(3,1);
%         else
%             robot(k).m(:,i) = robot(k).m(:,i-1) + robot(k).dm(:,i-1)*T;
%         end
        robot(k).betai(:,i) = zeros(3,1);
        robot(k).thetai(:,i) = zeros(3,1);
        robot(k).alfa(:,i) = obj.massa*obj.g0;
        robot(k).lam(:,i) = robot(k).alfa(:,i);
%         if(i==1)
            robot(k).dm(:,i) = zeros(3,1);
%         else
%             robot(k).dm(:,i) = -obj.massa*obj.g0;
%         end
%         robot(k).m(:,i) = zeros(3,1);
    end
    
    for k=1:N
        robot(k).hinti(:,i) = (eye(3) - robot(k).gam*pinvG*robot(k).G)*robot(k).fi(:,i) - ...
            robot(k).gam*pinvG*robot(k).thetai(:,i);
    end
    
    for k=1:N
%         robot(k).ddp0(:,i) = obj.g0;
%         robot(k).dp0(:,i) = robot(k).ddp0(:,i)*T;
        robot(k).ddp0(:,i) = zeros(3,1);
        robot(k).dp0(:,i) = zeros(3,1);
    end
    
end




end

