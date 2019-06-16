function DirectGPlot(MyGraph)
%%%%%%%%%%
% DirectGPlot(MyGraph)
% 
% This function attempts to plot a directed graph. The graph displayed will
% not necessarily be readable since this depends a lot on the location of
% the states and the number of arcs. Each arc/label pair has a different
% (randomly chosen) color so that they will be easier to match. 
%
% A graph is a structure with the following compulsory fields
%   A - a V by V adjacency matrix where V is the number of states
%   (vertices) in the graph. An adjacency matrix row i column j entry
%   contains the number of edges directed from state i to state j
%
%   EdgeLabels - a V by V cell. An entry in the cell is empty if the
%   corresponding entry in A is 0. Otherwise it is a character array in
%   which each row is the label of the corresponding edge. The labels are
%   arranged in rows. Note that this means that all the edges from state i
%   to state j must have names of the same length (or padded by spaces so
%   that they will be so).
%
%   StateLabels - a V by 1 cell. Each entry contains the string which is
%   the state name.
%
%   X,Y - V by 1 vectors containing the graphical coordinates for
%    displaying the states.
%%%%%%%%%%%%%%%%%%%%%%%
% By Roee Lahav 2009  %
% roeela@bgu.ac.il    %
%%%%%%%%%%%%%%%%%%%%%%%


X=MyGraph.X;
Y=MyGraph.Y;
%find maximum distance

[XX,YY]=meshgrid(X,Y);
DY=YY-YY';
DX=XX-XX';
DY=DY.^2;
DX=DX.^2;
D=sqrt(DX+DY);
D=D(:);
D=D(D>0);
MinD=min(D);
MaxD=max(D);
clear XX YY DX DY D;

R=MinD/5;

B=MyGraph.A;
NEdges=size(MyGraph.A,1);

ArrowSize=R*0.5;
for k=1:NEdges
    for m=1:NEdges
        if(B(k,m))
            MyColor=[0 0 0]; rand(1,3)*0.7;
            if(k==m)
                %                 Teta=300*pi/180;
                %                 text(X(k)+1.5*R,Y(k)+1.5*R,MyGraph.EdgeLabels{k,k});
                %                 hold on;
                ArcR=R+ArrowSize*0.5;
                Teta=rand*2*pi;
                for t=1:B(k,m)
                    SelfArcArrow(X(k),Y(k),...
                        Teta,ArrowSize,ArcR,R,...
                        MyGraph.EdgeLabels{k,k}(t,:),'Color',MyColor);
                    ArcR=ArcR+ArrowSize;
                    hold on;
                    
                end;
            else
                Teta=50*pi/180;
                for t=1:B(k,m)
                    if(k<m)
                        TwoPointArcArrow(X([k m]),Y([k m]),Teta,ArrowSize,R,...
                            MyGraph.EdgeLabels{k,m}(t,:),'Color',MyColor);
                    else
                        TwoPointArcArrow(X([k m]),Y([k m]),-Teta,ArrowSize,R,...
                            MyGraph.EdgeLabels{k,m}(t,:),'Color',MyColor);
                    end;

                    Teta=Teta+20*pi/180;
                    hold on;
                end;
            end;
        end;
    end;
end;

for k=1:NEdges
    rectangle('Position',[X(k)-R Y(k)-R R*2 R*2],...
        'Curvature',[1 1],'FaceColor',[1 1 1]);
    text(X(k),Y(k),MyGraph.StateLabels{k});
end;
axis equal;
axis([min(X)-R*3 max(X)+R*3 min(Y)-R*3 max(Y)+R*3]);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function SelfArcArrow(X,Y,teta,ArrowSize,RArc,RState,Label,varargin)


Angles=SolveTriangle([RArc RArc RState]);

ArcStart=Angles(3)-pi/2;
ArcEnd=pi+(pi/2-Angles(3));

ArcT=linspace(ArcStart,ArcEnd,30);

ArrowAngles=SolveTriangle([RArc RArc ArrowSize]);

ArrowEndAngle=ArcStart;
ArrowStartAngle=ArrowEndAngle+ArrowAngles(3);



%%%%%%%%%%%%%% create rotation matrix %%%%%%%%%
A=[cos(teta) sin(teta); -sin(teta) cos(teta)];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%% canonical - center of arc at (0,0)
CanonicalX=RArc*cos(ArcT);
CanonicalY=RArc*sin(ArcT);
CanonicalArrowX=[RArc*cos(ArrowStartAngle) RArc*cos(ArrowEndAngle)];
CanonicalArrowY=[RArc*sin(ArrowStartAngle) RArc*sin(ArrowEndAngle)];
CanonicalTextX=0;
CanonicalTextY=RArc+ArrowSize/2;
%%%% X1,Y1 - left point of arc at (0,0)
X1=CanonicalX;
Y1=CanonicalY+RArc;
ArrowX1=CanonicalArrowX;
ArrowY1=CanonicalArrowY+RArc;
TextX1=CanonicalTextX;
TextY1=CanonicalTextY+RArc;
%%%% Rot - Rotated to the correct angle
C=[X1;Y1];
Rot=A*C;
CArrow=[ArrowX1;ArrowY1];
RotArrow=A*CArrow;
CText=[TextX1;TextY1];
RotText=A*CText;
%%%% X2,Y2 - final coordinates after translation
X2=Rot(1,:)+X(1);
Y2=Rot(2,:)+Y(1);
ArrowX2=RotArrow(1,:)+X(1);
ArrowY2=RotArrow(2,:)+Y(1);
TextX2=RotText(1,:)+X(1);
TextY2=RotText(2,:)+Y(1);

h=plot(X2,Y2,varargin{:});
SaveHold=get(gca,'NextPlot');
set(gca,'NextPlot','add');
PlotArrow(ArrowX2,ArrowY2,ArrowSize,0,varargin{:});

MyColor=get(h,'Color');
if(nargin>5)
    text(TextX2,TextY2,Label,'Color',MyColor);
end;
set(gca,'NextPlot',SaveHold);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [Angles]=SolveTriangle(Edges)

[Edges,Index]=sort(Edges);
[dummy,RevIndex]=sort(Index);
a=Edges(1);
b=Edges(2);
c=Edges(3);

if((a+b)<c)
    error('The sum of the two smaller edges is less than the greatest');
end;

C=acos((a^2+b^2-c^2)/(2*a*b));
A=asin(a*sin(C)/c);
B=pi-(A+C);
Angles=[A B C];

Angles=Angles(RevIndex);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


function TwoPointArcArrow(X,Y,teta,ArrowSize,TrimSize,Label,varargin)

if(teta<0)
    Flip=-1;
    teta=-teta;
else
    Flip=1;
end;

T=sqrt(diff(X)^2+diff(Y)^2)/2;

R=T/sin(teta/2);

phi=pi/2-(teta/2);

TrimAngle=2*asin(TrimSize/2/R);

t=phi+linspace(0,teta-2*TrimAngle)+TrimAngle;

ArrowAngle=2*asin(ArrowSize/2/R);


%%%%%%%%%%%%%% create rotation matrix %%%%%%%%%
P1=[X(1) Y(1)];
P2=[X(2) Y(2)];
P=P2-P1;
OL=norm(P);
P=P./norm(P);
Pt=fliplr(P);
Pt(1)=-Pt(1);
A=[P' Pt'];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%% canonical - center of arc at (0,0)
CanonicalX=R*cos(t);
CanonicalY=R*sin(t);
CanonicalArrowX=[R*cos(TrimAngle+ArrowAngle+phi) R*cos(TrimAngle+phi) ];
CanonicalArrowY=[R*sin(TrimAngle+ArrowAngle+phi) R*sin(TrimAngle+phi) ];
CanonicalTextX=0;
CanonicalTextY=R+ArrowSize*0.5;
%%%% X1,Y1 - left point of arc at (0,0)
X1=CanonicalX+R*cos(phi);
Y1=Flip*(CanonicalY-R*sin(phi));
ArrowX1=CanonicalArrowX+R*cos(phi);
ArrowY1=Flip*(CanonicalArrowY-R*sin(phi));
TextX1=CanonicalTextX+R*cos(phi);
TextY1=Flip*(CanonicalTextY-R*sin(phi));
%%%% Rot - Rotated to the correct angle
C=[X1;Y1];
Rot=A*C;
CArrow=[ArrowX1;ArrowY1];
RotArrow=A*CArrow;
CText=[TextX1;TextY1];
RotText=A*CText;
%%%% X2,Y2 - final coordinates after translation
X2=Rot(1,:)+X(1);
Y2=Rot(2,:)+Y(1);
ArrowX2=RotArrow(1,:)+X(1);
ArrowY2=RotArrow(2,:)+Y(1);
TextX2=RotText(1,:)+X(1);
TextY2=RotText(2,:)+Y(1);

h=plot(X2,Y2,varargin{:});
SaveHold=get(gca,'NextPlot');
set(gca,'NextPlot','add');
PlotArrow(ArrowX2,ArrowY2,ArrowSize,0,varargin{:});

MyColor=get(h,'Color');
if(nargin>5)
    text(TextX2,TextY2,Label,'Color',MyColor);
end;
set(gca,'NextPlot',SaveHold);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


function PlotArrow(X,Y,Size,Trim,varargin)

P1=[X(1) Y(1)];
P2=[X(2) Y(2)];
P=P2-P1;
OL=norm(P);
P=P./norm(P);
Pt=fliplr(P);
Pt(1)=-Pt(1);
A=[Pt' P'];

NL=OL-Trim;
NV=P*NL;
X=[X(1) NV(1)+X(1)];
Y=[Y(1) NV(2)+Y(1)];
    
H=3;
ArrX=([0 2 1]-1)*Size/H;
ArrY=([0 0 H]-H)*Size/H;
h=plot(X,Y,varargin{:});
MyColor=get(h,'Color');
SaveHold=get(gca,'NextPlot');
RotXY=A*[ArrX;ArrY];
set(gca,'NextPlot','add');
p=fill(X(2)+RotXY(1,:),Y(2)+RotXY(2,:),MyColor);
set(p,'EdgeColor',MyColor);
set(gca,'NextPlot',SaveHold);