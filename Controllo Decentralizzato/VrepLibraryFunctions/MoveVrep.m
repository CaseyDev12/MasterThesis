%load DataSimulation.mat;
%InitConnectionWithSimulator;

for kk=1:15:i
    for j=1:Nv
        [err]=SendPoseToVRep(robot(j), kk);
    end
   % if(t(kk)>(T_Reach_Grasp+Nreg*T+t_rilascioObj))
        pobj = Object.x(kk,1:3); %sigma(1).value(kk,:); robot(1).x(kk,1:3)-PosRelManip(1,:);
        vrep.simxSetObjectPosition(client, Object.Handle,-1, pobj, Mode);
        
   % else
      %  vrep.simxSetObjectPosition(client, Object.Handle,-1, [0 0 0.5] , Mode);
    
   % end
    
    
    pause(T*55);
end

%StopVrepSimulation