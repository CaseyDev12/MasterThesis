function x = AngleCorrectionTask(xd, x)
%Questa funzione corregge l'errore sugli angoli in quanto potrebbe
%verificarsi il caso che l'errore calcolato tra gli angoli non sia quella
%reale, ad esempio potrebbe accadere che xd sia pi e xe sia -pi e l'errore
%sarebbe 2*pi mentre in realt? ? nullo


for j=1:length(xd)
    if (xd(j) < 0 && x(j) > 0 && abs(xd(j)-x(j)) > pi+pi/2)
        x(j) = x(j)-2*pi;
    else
        if (xd(j) > 0 && x(j) < 0 && abs(xd(j)-x(j)) > pi+pi/2)
            x(j) = x(j)+2*pi;
        end
    end
    %if(abs(abs(xd(j)-x(j)) - pi) < 1e-6)
        %x(j) = xd(j);
    %end
end

end