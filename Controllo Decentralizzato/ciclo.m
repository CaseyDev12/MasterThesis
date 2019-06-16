while(time < tf_task + t_regime)
    
    i = i + 1;
    
    t(i) = (i-1)*T;
    
    if(mod(i,1000)==0)
        disp(i*T)
    end
    
    % Calcolo il prossimo campione del task desiderato
    if(time <= tf_task)
        sig_des(:,i) = ComputeTask(sig_des(:,i-1));
        dsig_des(:,i) = (sig_des(:,i) - sig_des(:,i-1)) / T;
        ddsig_des(:,i) = (dsig_des(:,i) - dsig_des(:,i-1)) / T;
        i_fin = i;
        time = time + T;
    else
        sig_des(:,i) = sig_des(:,i_fin);
        dsig_des(:,i) = zeros(size(sig_des(:,i),1),1);
        ddsig_des(:,i) = zeros(size(sig_des(:,i),1),1);
        time = time + T;
    end
    
    
    KN1 = -4*kn1max*(time^2)/(tf_task + t_regime)^2 +  4*kn1max*time/(tf_task + t_regime);
    KN2 = -4*kn2max*(time^2)/(tf_task + t_regime)^2 +  4*kn2max*time/(tf_task + t_regime);
    KN3 = -4*kn3max*(time^2)/(tf_task + t_regime)^2 +  4*kn3max*time/(tf_task + t_regime);
    KN4 = -4*kn4max*(time^2)/(tf_task + t_regime)^2 +  4*kn4max*time/(tf_task + t_regime);
    KN = [KN1 KN2 KN3 KN4 0 0 0 0]';
    
    for k=1:N
        % Aggiorno posizioni e velocità effettive ai giunti
        robot(k).dq(i,:) = robot(k).dq(i-1,:) + robot(k).ddq(i-1,:)*T;
        robot(k).q(i,:) = robot(k).q(i-1,:) + robot(k).dq(i-1,:)*T;
        % Aggiorno la stima sullo stato complessivo, fatta dal robot
        % i-esimo
        robot(k).x_stim(:,i) = robot(k).x_stim(:,i-1) + robot(k).dx_stim(:,i-1)*T; 
    end
    
    for k=1:N
        % Calcolo la nuova dx stimata dall'i-esimo robot
        robot(k).eulAngle = robot(k).x(4:6,i-1);
        robot(k).x(:,i) = cindir_mex(robot(k).q(i,:), robot(k).A, robot(k).Ane);
        robot(k).x(4:6,i) = AngleCorrectionTask(robot(k).eulAngle, robot(k).x(4:6,i));
        robot(k).u_stim = compute_u_Stim(sig_des(:,i), dsig_des(:,i), robot(k).x_stim(:,i), obj, contr_hint);
        sommatoria = zeros(6*N,1);
        for ll=1:length(robot(k).Ni)
            sommatoria = sommatoria + (robot(robot(k).Ni(ll)).x_stim(:,i) - robot(k).x_stim(:,i));
        end
        robot(k).dx_stim(:,i) = ko*(sommatoria + [zeros(6*(k-1),1); (robot(k).x(:,i) - robot(k).x_stim(1+6*(k-1):6+6*(k-1),i)); zeros(6*(N-k),1)]) + robot(k).u_stim;
    end
    
    %%%%%%%%%%%%%Oggetto%%%%%%%%%%%%%
    [robot, obj] = dinamicaOggetto(KP, KD, T, N, obj, i, robot);
    
    [robot, G, pinvG] = forzeInterne(Ktheta, T, N, obj, robot, i);
    
    
    
    
    % forze interne calcolate con le fi
    
    for k=1:N
        robot(k).forze_altri_robot(:,i) = [0 0 0]';
        for jj=1:N
            if(jj~=k)
                robot(k).forze_altri_robot(:,i) = robot(k).forze_altri_robot(:,i) + robot(jj).G*robot(jj).fi(:,i);
            end
        end
    end
    
    for k=1:N
        robot(k).hint_vera(i,:) = (eye(3)-robot(k).gam*pinvG*robot(k).G) * ...
            robot(k).fi(:,i) - robot(k).gam*pinvG * robot(k).forze_altri_robot(:,i);
    end

    
%     for k=1:N
%         robot(k).thetai(:,i) = robot(k).forze_altri_robot(:,i);
%         robot(k).hinti(:,i) = robot(k).hint_vera(i,:)';
%     end
    
    
    for k=1:N
        
        % Calcolo dqsigma e ddqsigma per ciascun robot
        preInver(i, k);
        
        robot(k).htilde(:,i) = robot(k).hint_des - robot(k).hinti(:,i);
        robot(k).v(:,i) = robot(k).v(:,i-1) + robot(k).htilde(:,i-1)*T;
        robot(k).ufi(:,i) = kf*robot(k).v(:,i);
        robot(k).dx(:,i) = (robot(k).x(:,i) - robot(k).x(:,i-1))/T;
        
        
        robot(k).dqsigma(i,:) = InverseKinematicsFirstOrder(k, KN, i, contr_hint);
%         robot(k).ddqsigma(i,:) = (robot(k).dqsigma(i,:) - robot(k).dqsigma(i-1,:))/T;
        robot(k).ddqsigma(i,:) = InverseKinematicsSecondOrder(k, i, ddsig_des(:,i), dsig_des(:,i), robot(k).dqsigma(i,:), contr_hint, obj);
        robot(k).nulloPrec = robot(k).nullo;
        
        %%%%%%%%%%%%Controllo forze interne%%%%%%%%%%%
        robot(k).dqtildesigma(:,i) = robot(k).dqsigma(i,:)' - robot(k).dqActual';
        robot = controlloreForze(robot, kf, eps, i, pinvG, k);
        
        % Controllo adattativo
        [robot(k).pigreco, robot(k).dpigreco, robot(k).ddq(i,:)] = AdaptiveControl(k, i, contr_hint);
        
    end
    
    
    
    
%     nn1(i,:) = norm(robot(1).gam*pinvG*(robot(1).thetai(:,i) - ...
%         (robot(2).G*robot(2).fi(:,i) + robot(3).G*robot(3).fi(:,i) + ...
%         robot(4).G*robot(4).fi(:,i))));
%     
%     nn2(i,:) = norm(robot(2).gam*pinvG*(robot(2).thetai(:,i) - ...
%         (robot(1).G*robot(1).fi(:,i) + robot(3).G*robot(3).fi(:,i) + ...
%         robot(4).G*robot(4).fi(:,i))));
%     
%     nn3(i,:) = norm(robot(3).gam*pinvG*(robot(3).thetai(:,i) - ...
%         (robot(1).G*robot(1).fi(:,i) + robot(2).G*robot(2).fi(:,i) + ...
%         robot(4).G*robot(4).fi(:,i))));
%     
%     nn4(i,:) = norm(robot(4).gam*pinvG*(robot(4).thetai(:,i) - ...
%         (robot(1).G*robot(1).fi(:,i) + robot(2).G*robot(2).fi(:,i) + ...
%         robot(3).G*robot(3).fi(:,i))));
%     
    
    
    
    %     diff21(i,:) = robot(1).gam*(pinvG*robot(1).G*robot(1).fi(:,i) + pinvG*robot(1).thetai(:,i));
    %     diff22(i,:) = robot(2).gam*(pinvG*robot(2).G*robot(1).fi(:,i) + pinvG*robot(2).thetai(:,i));
    %     diff23(i,:) = robot(3).gam*(pinvG*robot(3).G*robot(1).fi(:,i) + pinvG*robot(3).thetai(:,i));
    %     diff24(i,:) = robot(4).gam*(pinvG*robot(4).G*robot(1).fi(:,i) + pinvG*robot(4).thetai(:,i));
    
    
    
    
end
