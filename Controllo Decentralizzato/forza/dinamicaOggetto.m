function [robot, obj] = dinamicaOggetto(KP, KD, T, N, obj, i, robot)

if (obj.dynamics==1)
    
    % Calcolo la posizione e la velocità dell'oggetto
    obj.dp0(:,i) = obj.dp0(:,i-1) + obj.ddp0(:,i-1)*T;
    obj.pos(:,i) = obj.pos(:,i-1) + obj.dp0(:,i-1)*T;
    
    obj = puntiContatto(obj, i);
    
    % Calcolo le hi
    for k=1:N
        pos_i(:,1) = robot(k).x(1:3,i);
        p0i(:,1) = obj.extr(k,:);
        dpi(:,1) = (robot(k).x(1:3,i) - robot(k).x(1:3,i-1))/T;
        dp0i(:,1) = (obj.extr(k,:) - obj.extrPrec(k,:))/T;
        robot(k).fi(:,i) = KP*(pos_i - p0i) + KD*(dpi - dp0i);
        robot(k).mui(:,i) = zeros(3,1);
        robot(k).hi(:,i) = vertcat(robot(k).fi(:,i), robot(k).mui(:,i));
    end
    
%     % Calcolo ho
%     obj.f0(:,i) = zeros(3,1);
%     obj.mu0(:,i) = zeros(3,1);
%     for k=1:N
%         obj.f0(:,i) = obj.f0(:,i) + robot(k).fi(:,i);
%         %ri(:,k) = obj.pos(:,i) - p0i;
%         ri(:,k) = obj.pos(:,i) - robot(k).x(1:3,i);
%         Sr = [0 -ri(3,k) ri(2,k); ri(3,k) 0 -ri(1,k); -ri(2,k) ri(1,k) 0];
%         obj.mu0(:,i) = obj.mu0(:,i) - Sr*robot(k).fi(:,i);
%         robot(k).G = eye(3);
%     end
%     obj.h0(:,i) = [obj.f0(:,i); obj.mu0(:,i)];


    for k=1:N
        %center_obj = [obj.pos(1:2,i); obj.extr(k,3)];
        center_obj = obj.pos(1:3,i);
        ri(:,k) = (center_obj - robot(k).x(1:3,i));
        Sri(:,:,k) = [0 -ri(3,k) ri(2,k); ri(3,k) 0 -ri(1,k); -ri(2,k) ri(1,k) 0];
        Gri(:,:,k) = [eye(3) zeros(3,3); Sri(:,:,k) eye(3)];
    end
    
    obj.h0(:,i) = zeros(6,1);
    for k=1:N
        obj.h0(:,i) = obj.h0(:,i) + Gri(:,:,k)*robot(k).hi(:,i);
    end
    obj.h0(4:6,i) = zeros(3,1);
    obj.f0(:,i) = obj.h0(1:3,i);
    obj.mu0(:,i) = obj.h0(4:6,i);
    
    obj.ddp0(:,i) = obj.massa^(-1)*(-obj.massa*obj.g0 + obj.f0(:,i));
    
else
    
    obj.pos(:,i) = obj.pos(:,i-1);
    
    obj = puntiContatto(obj, i);
    
    for k=1:N
        robot(k).fi(:,i) = zeros(3,1);
        robot(k).mui(:,i) = zeros(3,1);
        robot(k).hi(:,i) = zeros(6,1);
    end
    
    obj.f0(:,i) = zeros(3,1);
    obj.mu0(:,i) = zeros(3,1);
    obj.h0(:,i) = zeros(6,1);
    
    obj.ddp0(:,i) = zeros(3,1);
    obj.dp0(:,i) = zeros(3,1);
    
end

end

