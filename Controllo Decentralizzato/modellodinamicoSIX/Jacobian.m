function J = Jacobian(qdh)
%
% SIX - Gennaio 2005
%
% function J = mat_jac(q)
%
% Calcola, in numerico, la matrice dello Jacobiano
%
% Ingressi:
%   q : vettore 6x1 contenente le posizioni (in rad) ai giunti in convenzione DH 
% Uscite:
%   J : matrice 6x6 contenente la matrice dello Jacobinano
%       i dati che si possono ricavare da questa sono in convenzione DH ai giunti in m/sec e rad/sec


%************************************************************************************************************************
% Parametri DH
%************************************************************************************************************************

qcomau = dh2comau(qdh*180/pi);
J = mat_jac(qcomau);
% 
%   [a,d,alpha] = dh_table;
%   a1 = a(1); a2 = a(2); a3 = a(3); a4 = a(4); a5 = a(5); a6 = a(6);
%   d1 = d(1); d2 = d(2); d3 = d(3); d4 = d(4); d5 = d(5); d6 = d(6);
% 
% 
% %************************************************************************************************************************
% % Conversione delle grandezze
% %************************************************************************************************************************
% 
% 
%   % rinomina le variabili delle posizioni: le variabili qi saranno le posizioni dh in radianti
%     q1 = qdh(1); q2 = qdh(2); q3 = qdh(3); q4 = qdh(4); q5 = qdh(5); q6 = qdh(6);
% 
% 
% %************************************************************************************************************************
% % Calcolo della matrice dello Jacobiano
% %************************************************************************************************************************
% 
%     J(1,1) = -(-((1/2*sin(q3+q1+q2)+1/2*sin(-q3+q1-q2))*cos(q4)-cos(q1)*sin(q4))*sin(q5)+(1/2*...
%              cos(q3+q1+q2)-1/2*cos(-q3+q1-q2))*cos(q5))*d6-(1/2*cos(q3+q1+q2)-1/2*cos(-q3+q1-q2))*d4-1/2*a3*...
%              sin(q3+q1+q2)-1/2*a3*sin(-q3+q1-q2)-1/2*a2*sin(q1+q2)-1/2*a2*sin(q1-q2)-a1*sin(q1);
%     J(1,2) = cos(q1)*((sin(q2+q3)*cos(q4)*sin(q5)-cos(q2+q3)*cos(q5))*d6-cos(q2+q3)*d4-a3*sin(q2+q3)-a2*...
%              sin(q2));
%     J(1,3) = cos(q1)*((sin(q2+q3)*cos(q4)*sin(q5)-cos(q2+q3)*cos(q5))*d6-cos(q2+q3)*d4-a3*sin(q2+q3));
%     J(1,4) = 1/2*d6*sin(q5)*(cos(q3+q1+q2)*sin(q2+q3)*cos(q4)-cos(-q3+q1-q2)*sin(q2+q3)*cos(q4)-cos(q2+q3)*...
%              cos(q4)*sin(q3+q1+q2)-cos(q2+q3)*cos(q4)*sin(-q3+q1-q2)+2*cos(q2+q3)*cos(q1)*sin(q4));
%     J(1,5) = 1/2*d6*(-sin(q4)*sin(q3+q1+q2)*cos(q2+q3)*cos(q5)-sin(q4)*sin(-q3+q1-q2)*cos(q2+q3)*cos(q5)-2*...
%              cos(q1)*cos(q4)*cos(q2+q3)*cos(q5)+2*sin(q2+q3)*sin(q5)*cos(q1)+sin(q2+q3)*sin(q4)*cos(q5)*...
%              cos(q3+q1+q2)-sin(q2+q3)*sin(q4)*cos(q5)*cos(-q3+q1-q2));
%     J(1,6) = 0;
%  
%     J(2,1) = (-((1/2*cos(-q3+q1-q2)+1/2*cos(q3+q1+q2))*cos(q4)+sin(q1)*sin(q4))*sin(q5)+(1/2*...
%              sin(-q3+q1-q2)-1/2*sin(q3+q1+q2))*cos(q5))*d6+(1/2*sin(-q3+q1-q2)-1/2*sin(q3+q1+q2))*d4+1/2*a3*...
%              cos(-q3+q1-q2)+1/2*a3*cos(q3+q1+q2)+1/2*a2*cos(q1-q2)+1/2*a2*cos(q1+q2)+a1*cos(q1);
%     J(2,2) = sin(q1)*((sin(q2+q3)*cos(q4)*sin(q5)-cos(q2+q3)*cos(q5))*d6-cos(q2+q3)*d4-a3*sin(q2+q3)-a2*...
%              sin(q2));
%     J(2,3) = sin(q1)*((sin(q2+q3)*cos(q4)*sin(q5)-cos(q2+q3)*cos(q5))*d6-cos(q2+q3)*d4-a3*sin(q2+q3));
%     J(2,4) = 1/2*d6*sin(q5)*(cos(q2+q3)*cos(q4)*cos(-q3+q1-q2)+cos(q2+q3)*cos(q4)*cos(q3+q1+q2)+2*cos(q2+q3)*...
%              sin(q1)*sin(q4)-sin(-q3+q1-q2)*sin(q2+q3)*cos(q4)+sin(q3+q1+q2)*sin(q2+q3)*cos(q4));
%     J(2,5) = 1/2*d6*(2*sin(q2+q3)*sin(q5)*sin(q1)-sin(q2+q3)*sin(q4)*cos(q5)*sin(-q3+q1-q2)+sin(q2+q3)*...
%              sin(q4)*cos(q5)*sin(q3+q1+q2)+sin(q4)*cos(-q3+q1-q2)*cos(q2+q3)*cos(q5)+sin(q4)*cos(q3+q1+q2)*...
%              cos(q2+q3)*cos(q5)-2*sin(q1)*cos(q4)*cos(q2+q3)*cos(q5));
%     J(2,6) = 0;
%  
%     J(3,1) = 0;
%     J(3,2) = -sin(q1)*((-((1/2*sin(q3+q1+q2)+1/2*sin(-q3+q1-q2))*cos(q4)-cos(q1)*sin(q4))*sin(q5)+(1/2*...
%              cos(q3+q1+q2)-1/2*cos(-q3+q1-q2))*cos(q5))*d6+(1/2*cos(q3+q1+q2)-1/2*cos(-q3+q1-q2))*d4+1/2*a3*...
%              sin(q3+q1+q2)+1/2*a3*sin(-q3+q1-q2)+1/2*a2*sin(q1+q2)+1/2*a2*sin(q1-q2))-cos(q1)*((-((1/2*...
%              cos(-q3+q1-q2)+1/2*cos(q3+q1+q2))*cos(q4)+sin(q1)*sin(q4))*sin(q5)+(1/2*sin(-q3+q1-q2)-1/2*...
%              sin(q3+q1+q2))*cos(q5))*d6+(1/2*sin(-q3+q1-q2)-1/2*sin(q3+q1+q2))*d4+1/2*a3*cos(-q3+q1-q2)+1/2*...
%              a3*cos(q3+q1+q2)+1/2*a2*cos(q1-q2)+1/2*a2*cos(q1+q2));
%     J(3,3) = -sin(q1)*((-((1/2*sin(q3+q1+q2)+1/2*sin(-q3+q1-q2))*cos(q4)-cos(q1)*sin(q4))*sin(q5)+(1/2*...
%              cos(q3+q1+q2)-1/2*cos(-q3+q1-q2))*cos(q5))*d6+(1/2*cos(q3+q1+q2)-1/2*cos(-q3+q1-q2))*d4+1/2*a3*...
%              sin(q3+q1+q2)+1/2*a3*sin(-q3+q1-q2)+1/2*a2*sin(q1+q2)+1/2*a2*sin(q1-q2)+a1*sin(q1)-sin(q1)*(a2*...
%              cos(q2)+a1))-cos(q1)*((-((1/2*cos(-q3+q1-q2)+1/2*cos(q3+q1+q2))*cos(q4)+sin(q1)*sin(q4))*...
%              sin(q5)+(1/2*sin(-q3+q1-q2)-1/2*sin(q3+q1+q2))*cos(q5))*d6+(1/2*sin(-q3+q1-q2)-1/2*...
%              sin(q3+q1+q2))*d4+1/2*a3*cos(-q3+q1-q2)+1/2*a3*cos(q3+q1+q2)+1/2*a2*cos(q1-q2)+1/2*a2*...
%              cos(q1+q2)+a1*cos(q1)-cos(q1)*(a2*cos(q2)+a1));
%     J(3,4) = 1/2*d6*sin(q5)*sin(q4)*(cos(q1)*sin(-q3+q1-q2)-cos(q1)*sin(q3+q1+q2)+sin(q1)*...
%              cos(q3+q1+q2)-sin(q1)*cos(-q3+q1-q2));
%     J(3,5) = 1/2*d6*(cos(-q3+q1-q2)*sin(q5)*cos(q1)+cos(q3+q1+q2)*sin(q5)*cos(q1)-sin(q1)*cos(q4)*cos(q5)*...
%              cos(q3+q1+q2)+sin(q1)*cos(q4)*cos(q5)*cos(-q3+q1-q2)+sin(q3+q1+q2)*sin(q5)*...
%              sin(q1)+sin(-q3+q1-q2)*sin(q5)*sin(q1)-cos(q1)*cos(q4)*cos(q5)*sin(-q3+q1-q2)+cos(q1)*cos(q4)*...
%              cos(q5)*sin(q3+q1+q2));
%     J(3,6) = 0;
%  
%     J(4,1) = 0;
%     J(4,2) = -sin(q1);
%     J(4,3) = -sin(q1);
%     J(4,4) = 1/2*sin(-q3+q1-q2)-1/2*sin(q3+q1+q2);
%     J(4,5) = (1/2*cos(-q3+q1-q2)+1/2*cos(q3+q1+q2))*sin(q4)-sin(q1)*cos(q4);
%     J(4,6) = -((1/2*cos(-q3+q1-q2)+1/2*cos(q3+q1+q2))*cos(q4)+sin(q1)*sin(q4))*sin(q5)+(1/2*...
%              sin(-q3+q1-q2)-1/2*sin(q3+q1+q2))*cos(q5);
%  
%     J(5,1) = 0;
%     J(5,2) = cos(q1);
%     J(5,3) = cos(q1);
%     J(5,4) = 1/2*cos(q3+q1+q2)-1/2*cos(-q3+q1-q2);
%     J(5,5) = (1/2*sin(q3+q1+q2)+1/2*sin(-q3+q1-q2))*sin(q4)+cos(q1)*cos(q4);
%     J(5,6) = -((1/2*sin(q3+q1+q2)+1/2*sin(-q3+q1-q2))*cos(q4)-cos(q1)*sin(q4))*sin(q5)+(1/2*cos(q3+q1+q2)-1/2*...
%              cos(-q3+q1-q2))*cos(q5);
%  
%     J(6,1) = 1;
%     J(6,2) = 0;
%     J(6,3) = 0;
%     J(6,4) = -cos(q2+q3);
%     J(6,5) = -sin(q2+q3)*sin(q4);
%     J(6,6) = sin(q2+q3)*cos(q4)*sin(q5)-cos(q2+q3)*cos(q5);
%    