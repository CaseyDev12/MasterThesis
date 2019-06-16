function [err]=SendPoseToVRep(robot, step)
%Invia a vrep la posizione ai giunti del manipolatore.
%Da usare in simulink. Il vettore "in" è costituito da [time JointDH] (dimensione [8,1])

global vrep client  Mode

err(1:7) = 0;
for i=1:6
    %err(i) = vrep.simxSetJointPosition(client, robot.JointHandle(i), robot.q(step, i), Mode);
    err(i) = vrep.simxSetJointPosition(client, robot.JointHandle(i), step(i), Mode);
end

%base = robot.A*[robot.q(step, 7:8) 0 1]';
base = robot.A*[step(7:8) 0 1]';
vrep.simxSetObjectPosition(client, robot.OmniPlatformHandle,-1, [base(1:2)' robot.OmniPlatformPosition(3)], Mode);
R=(angle2dcm(robot.OmniPlatformOrientation(1), robot.OmniPlatformOrientation(2), robot.OmniPlatformOrientation(3), 'XYZ'))';
 

[or(1) or(2) or(3)]=dcm2angle((robot.A(1:3,1:3)*R)', 'XYZ');
vrep.simxSetObjectOrientation(client, robot.OmniPlatformHandle,-1, or, Mode);