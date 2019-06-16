function disegna_manipolatori(robot, decim, RotazioneAngle,  varargin)


%C:\Program Files (x86)\MPlayer\mencoder.exe" mf://Image*  -mf w=400:h=300:fps=62.5130:type=jpg  -ovc lavc -lavcopts vcodec=mpeg4:mbd=2:trell:vbitrate=200 -oac copy -o ../Video.avi

%Disena la cinamtica diretta del manipolatore

%Input:
%      -Q{N}.qDH: cella di matrici (nx6) contenente le variabili di giunto
%      (rad DH)
%      -A{N}.A: cella di matrici (4x4) contenente le
%      roto-traslazione della terna base dell'i-esimo
%      manipolatore rispetto alla terna mondo

%      -decim: decimazione con cui plottare le configurazione (1:decim:end) per aumentare la velocita' 

%Output:


SAVE = 0;
Path = 'Immagini/';

if(SAVE)
   system(['rm ', Path, 'Imag*']);
end
    
    
%INIZAILIZZAZIONI INVERSIONE CINEMATICA%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%     StructConfIk.CONF_S_in =  0; %: flag di attitudine di tipo S (Shoulder)
%     StructConfIk.CONF_E_in =  1; %: flag di attitudine di tipo E (Elbow)
%     StructConfIk.CONF_W_in =  1; %: flag di attitudine di tipo W (Wrist)
%     StructConfIk.T1 =      0;   % : turn asse 4 (-8 -> +7)
%     StructConfIk.T2 =      0;   % : turn asse 6 (-8 -> +7)
%     StructConfIk.T3 =      0;   % : turn asse 3 (-1 -> +1)
%     StructConfIk.T4 =      0;   % : turn asse 5 (-1 -> +1)

    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Ts = 1;
NumMan = length(robot);
if(length(varargin)>0)
   Ts = varargin{1}; 
end



set(gcf,'Name',['Rappresentazione grafica manipolatore'],'NumberTitle','off');


%clf

%axis([-0.5 0.5 -0.5 2.5 -0.2 1.5]);, \bx_o

xlabel ('X');
ylabel ('Y');
zlabel ('Z');
%axis('equal')
%axis('square')


hold on
ind = 1:decim:length(robot(1).q(1:decim:end, 1));
PosCam = [12.0092  -17.7041   14.4513];
for j=1:length(ind)
if(SAVE) 
    clf;
end
% set(gca,'FontSize',20, 'FontName', 'Arial')
for k=1:NumMan

qDH = robot(k).q(ind(j), 1:8);
T = robot(k).A;


X0 = cindir((robot(k).q(1, :)), eye(4)); 
temp = robot(k).A*[X0(1:3)'; 1]; X0(1:3) = temp(1:3);
Xf = cindir((robot(k).q(end, :)), eye(4)); 
temp = robot(k).A*[Xf(1:3)'; 1]; Xf(1:3) = temp(1:3);

T = eye(4);
% T(1,4) = T(1,4) +  qDH(7);
% T(2,4) = T(2,4) +  qDH(8);
% qDH(j, :) = comau2DH(qCo(j, :))*pi/180;
% tabella d-h prima catena
[a,d,alpha] = dh_table;% a(1) = 0;
ctheta = cos(qDH);
stheta = sin(qDH);

calpha = cos(alpha);
salpha = sin(alpha);


% calcola le posizioni dei giunti
p = [T(1:3,4)'];
temp = T*([0 0 0.45 1]');
p = [p; temp(1:3)'];



for i=1:size(alpha)
    T =T*[ctheta(i) -stheta(i)*calpha(i) stheta(i)*salpha(i) a(i)*ctheta(i);
          stheta(i)  ctheta(i)*calpha(i) -ctheta(i)*salpha(i) a(i)*stheta(i);
             0           salpha(i)             calpha(i)            d(i);
             0                0                  0                    1];
  p = [p; T(1:3, 4)'];        
end


%disp(['posizione organo terminale ' num2str(p7')])

%keyboard

Tv =[0.7009    0.7133         0   -0.7071
   -0.3566    0.3504    0.8660   -0.4299
   -0.6177    0.6070   -0.5000    8.9156
         0         0         0    1.0000];

view([16.6359 9.79928 17.8845]);

if(k>=5)
Color = 'g';
else
    Color = 'b';
end
p(:,1) = p(:,1) + qDH(7);
p(:,2) = p(:,2) + qDH(8);

for r=1:size(p,1)
    temp = robot(k).A*[p(r,:) 1]';
    p(r,:) = temp(1:3);
end


plot3([p(1, 1) p(2, 1) p(3, 1) p(4, 1) p(5, 1) p(6, 1) p(7, 1) p(8, 1)],...
      [p(1, 2) p(2, 2) p(3, 2) p(4, 2) p(5, 2) p(6, 2) p(7, 2) p(8, 2)],...
      [p(1, 3) p(2, 3) p(3, 3) p(4, 3) p(5, 3) p(6, 3) p(7, 3) p(8, 3)], Color, 'LineWidth', 3)
grid

%disp terna base

% rx = T*[0.3 0 0 1]';
% ry = T*[0 0.3 0 1]'; rz = T*[0 0 0.3 1]';
% vectarrow(T(1:3, 4), rx(1:3)); text(rx(1), rx(2), rx(3), ['X', num2str(k)])
% vectarrow(T(1:3, 4), ry(1:3));  text(ry(1), ry(2), ry(3), ['Y', num2str(k)])
% vectarrow(T(1:3, 4), rz(1:3)); text(rz(1), rz(2), rz(3), ['Z', num2str(k)])
% 

%disp terna utente
T = robot(k).A*T;
p1 = p(end, :) + 0.15*T(1:3, 1)';
p2 = p(end, :) + 0.15*T(1:3, 2)'; 
p3 = p(end, :) + 0.15*T(1:3, 3)'; 

vectarrow(p(end, :), p1); %text(p1(1), p1(2), p1(3), 'X')
vectarrow(p(end, :), p2); %text(p2(1), p2(2), p2(3), 'Y')
vectarrow(p(end, :), p3); %text(p3(1), p3(2), p3(3), 'Z')


x{k}.x(j) = p(end, 1);
y{k}.y(j) = p(end, 2);
z{k}.z(j) = p(end, 3);

[phi(j), theta(j), psi(j)] = R2ZYZ(T(1:3,1:3));

         
%pause(0.2);


%plot3(X0(1), X0(2), X0(3), '*r', 'LineWidth',5.5)
%text(X0(1), X0(2), X0(3)+0.1, 'Partenza');




%plot3(x{k}.x, y{k}.y, z{k}.z, 'g', 'LineWidth',2.5, 'Color', [0.8 0.1 0.2]*k/NumMan)


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

end

text(0, 2.5, 2.5, ['time: ',  num2str(j*Ts*decim), 's'], 'fontsize', 20)

set(gca, 'CameraPosition', PosCam)

set(gca, 'xticklabel', []);
set(gca, 'yticklabel', []);
set(gca, 'zticklabel', []);



if(SAVE)
    camorbit(90-RotazioneAngle(j*decim),0);
    iter = j;
     if iter<10
                name = ['Image-0000', num2str(iter)];
            elseif iter<100
                name = ['Image-000', num2str(iter)];
            elseif iter<1000
                name = ['Image-00', num2str(iter)];
            elseif iter<10000
                name = ['Image-0', num2str(iter)];
            else
                name = ['Image-', num2str(iter)];
     end
     
     print(gcf, [Path, name], '-dbmp', '-r150')
    
else


    pause(0.1)

end




end



% for k=1:NumMan
% 
% qDH = robot(k).q(1:decim:end, 1:6);
% T = robot(k).A;
% 
% 
% X0 = cindir((robot(k).q(1, :)), eye(4));   temp = robot(k).A*[X0(1:3)'; 1]; X0(1:3) = temp(1:3);
% Xf = cindir((robot(k).q(end, :)), eye(4)); temp = robot(k).A*[Xf(1:3)'; 1]; Xf(1:3) = temp(1:3);
% 
% plot3(Xf(1), Xf(2), Xf(3), '*c', 'LineWidth',5.5)
% %text(Xf(1), Xf(2), Xf(3)+0.1, 'Arrivo');
% 
% 
% 
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% end









%close(gcf)