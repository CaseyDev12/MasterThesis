InitConnectionWithSimulator;

% for i=1:size(robot(1).q,1)
% for i=1:3000
for i=2600:size(robot(1).q,1)
    for k=1:N
        SendPoseToVRep(robot(k), robot(k).q(i,:));
    end
    pobj = obj.pos(:,i)';
    vrep.simxSetObjectPosition(client, Object.Handle,-1, pobj, Mode);
    pause(0.0003);
end

%StopVrepSimulation;