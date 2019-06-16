function [obj] = puntiContatto(obj, i)

obj.extrPrec = obj.extr;

if(obj.dynamics==1)
    
    % Calcolo gli estremi dell'oggetto, ovvero i punti estremi che
    % devono essere quelli di presa da parte degli end-effector
    %obj.extr = [];
    obj.extr(1,:) = [obj.pos(1,i) - 0.49,     obj.pos(2,i),     obj.pos(3,i) + 0.2333];
    obj.extr(2,:) = [obj.pos(1,i),    obj.pos(2,i) + 0.49,     obj.pos(3,i) + 0.2333];
    obj.extr(3,:) = [obj.pos(1,i) + 0.49,     obj.pos(2,i),     obj.pos(3,i) + 0.2333];
    obj.extr(4,:) = [obj.pos(1,i),       obj.pos(2,i) - 0.49,      obj.pos(3,i) + 0.2333];
    
else
    
    %obj.extr = [];
    obj.extr(1,:) = [obj.pos(1,i) - 0.49,     obj.pos(2,i),       0.4958];
    obj.extr(2,:) = [obj.pos(1,i),          obj.pos(2,i) + 0.49,     0.4958];
    obj.extr(3,:) = [obj.pos(1,i) + 0.49,       obj.pos(2,i),     0.4958];
    obj.extr(4,:) = [obj.pos(1,i),       obj.pos(2,i) - 0.49,       0.4958];
    
end

end

