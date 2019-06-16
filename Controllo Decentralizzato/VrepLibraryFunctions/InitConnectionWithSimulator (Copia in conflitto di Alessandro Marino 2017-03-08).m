%StopVrepSimulation()

global client vrep Mode
IP = '127.0.0.1';
Port = 19998;
Timeout = 5000; %timeout for response (ms)
SampleTimeComm =  50; %ms
 %addpath('C:\Program Files (x86)\V-REP3\V-REP_PRO_EDU\programming\remoteApiBindings\matlab\matlab');
 %addpath('C:\Program Files (x86)\V-REP3\V-REP_PRO_EDU\programming\remoteApi');
 %addpath('C:\Program Files (x86)\V-REP3\V-REP_PRO_EDU\programming\remoteApiBindings\lib\lib\64Bit')
 addpath(genpath('/usr/local/src/vrep/'));
 addpath('/usr/local/src/vrep/programming/remoteApi');
 addpath('/usr/local/src/vrep/programming/remoteApiBindings/lib/lib/64Bit')


vrep=remApi('remoteApi','extApi.h');
client = vrep.simxStart(IP, Port, true, true, Timeout, SampleTimeComm);
Mode = vrep.simx_opmode_oneshot; %communication mode (see manual remote API)


%Read from simulator the pointers to joints
pause(0.2);


for Manip = 1:4;
    for ii=1:6
        [err, robot(Manip).JointHandle(ii)] = vrep.simxGetObjectHandle(client, ['Joint', num2str(6*(Manip-1)+ii)],  vrep.simx_opmode_oneshot_wait);
        if(err)
            error(['Err reading pointer to revolute joint ', num2str(2)]);
        end
    end

    [err, robot(Manip).OmniPlatformHandle] = vrep.simxGetObjectHandle(client, ['OmniPlatform', num2str(Manip)],  vrep.simx_opmode_oneshot_wait);
    if(err)
        error(['Err reading pointer to Base ', num2str(2)]);
    end
    
            [err, robot(Manip).OmniPlatformPosition]=vrep.simxGetObjectPosition(client, robot(Manip).OmniPlatformHandle, -1,  vrep.simx_opmode_oneshot_wait);
    if(err)
        error(['Err reading pointer to Base ', num2str(2)]);
    end
    
    [err, robot(Manip).OmniPlatformOrientation]=vrep.simxGetObjectOrientation(client, robot(Manip).OmniPlatformHandle, -1,  vrep.simx_opmode_oneshot_wait);
    robot(Manip).OmniPlatformOrientation = [-pi/2 0 -pi/2];
    if(err)
        error(['Err reading pointer to Base ', num2str(2)]);
    end


end

if(1)
 [err, Object.Handle] = vrep.simxGetObjectHandle(client, 'Object',  vrep.simx_opmode_oneshot_wait);
    if(err)
        error(['Err reading pointer to Base ', num2str(2)]);
    end

                [err, Object.Position]=vrep.simxGetObjectPosition(client, Object.Handle, -1,  vrep.simx_opmode_oneshot_wait);
    if(err)
        error(['Err reading pointer to Base ', num2str(2)]);
    end
    
    [err, Object.Orientation]=vrep.simxGetObjectOrientation(client, Object.Handle, -1,  vrep.simx_opmode_oneshot_wait);
    if(err)
        error(['Err reading pointer to Base ', num2str(2)]);
    end
end
%[temp, ForceSensorId] = vrep.simxGetObjectHandle(['ForceSensor'],  vrep.simx_opmode_oneshot_wait);
%[temp, EndEffectorId] = vrep.simxGetObjectHandle(client, ['EESx'],  vrep.simx_opmode_oneshot_wait);



 err=vrep.simxStartSimulation(client, vrep.simx_opmode_oneshot_wait);
 if(err>1)
     error(['Err starting simulation']);
 end

