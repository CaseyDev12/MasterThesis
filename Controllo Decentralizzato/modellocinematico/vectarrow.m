function vectarrow(p0,p1,varargin)
%Arrowline 3-D vector plot.
%   vectarrow(p0,p1) plots a line vector with arrow pointing from point p0
%   to point p1. The function can plot both 2D and 3D vector with arrow
%   depending on the dimension of the input
%
%   Example:
%       3D vector
%       p0 = [1 2 3];   % Coordinate of the first point p0
%       p1 = [4 5 6];   % Coordinate of the second point p1
%       vectarrow(p0,p1)
%
%       2D vector
%       p0 = [1 2];     % Coordinate of the first point p0
%       p1 = [4 5];     % Coordinate of the second point p1
%       vectarrow(p0,p1)
%
%   See also Vectline

%   Rentian Xiong 4-18-05
%   $Revision: 1.0

color = 'b';
if(isempty(varargin)==0)
    color=varargin{1};
end

  if max(size(p0))==3
      if max(size(p1))==3
              
          x0 = p0(1);
          y0 = p0(2);
          z0 = p0(3);
          x1 = p1(1);
          y1 = p1(2);
          z1 = p1(3);
          
          temp = p0; p0 = []; p0(1, :) = temp;
          temp = p1; p1 = []; p1(1, :) = temp;
          
          p = p1-p0;
          alpha = 0.1;  % Size of arrow head relative to the length of the vector
          beta = 0.1;  % Width of the base of the arrow head relative to the length
          ang = pi/6;
          
          vect = (p0-p1);
          vect_length = (sum(vect.*vect)^0.5);
          vect_norm = vect/(sum(vect.*vect)^0.5); %vettore di modulo unitario
     
          
%           hu = [x1-alpha*(p(1)+beta*(p(2)+eps)); x1; x1-alpha*(p(1)-beta*(p(2)+eps))];
%           hv = [y1-alpha*(p(2)-beta*(p(1)+eps)); y1; y1-alpha*(p(2)+beta*(p(1)+eps))];
%           hw = [z1-alpha*(p(3)+beta*(p(2)+eps));z1;z1-alpha*(p(3)-beta*(p(2)+eps))];
            a = vect(1); b = vect(2); c = vect(3);
            ort_vect = [0 -c b] + [-b a 0] + [-c 0 a];
            ort_vect = ort_vect/(sum(ort_vect.*ort_vect)^(1/2)); %vettore ortogonale di modulo unitario
            
            p_base = p1 + vect*alpha;
            displ = sum((vect*alpha).*(vect*alpha))^(1/2);
            p_head1 = p_base + ort_vect*displ/tan(pi/2-ang);
            p_head2 = p_base - ort_vect*displ/tan(pi/2-ang);
            
            hu = [p_head1(1) p1(1) p_head2(1)];
            hv = [p_head1(2) p1(2) p_head2(2)];
            hw = [p_head1(3) p1(3) p_head2(3)];

          hold on
          plot3([x0; x1],[y0; y1],[z0; z1], color);   % Draw a line between p0 and p1
          plot3(hu(:),hv(:),hw(:), color)  % Plot arrow head
          grid on
          xlabel('x')
          ylabel('y')
          zlabel('z')
    
      else
          error('p0 and p1 must have the same dimension')
      end
  elseif max(size(p0))==2
      if max(size(p1))==2
          x0 = p0(1);
          y0 = p0(2);
          x1 = p1(1);
          y1 = p1(2);
          plot([x0;x1],[y0;y1], color);   % Draw a line between p0 and p1
          
          p = p1-p0;
          alpha = 0.1;  % Size of arrow head relative to the length of the vector
          beta = 0.1;  % Width of the base of the arrow head relative to the length
          
          hu = [x1-alpha*(p(1)+beta*(p(2)+eps)); x1; x1-alpha*(p(1)-beta*(p(2)+eps))];
          hv = [y1-alpha*(p(2)-beta*(p(1)+eps)); y1; y1-alpha*(p(2)+beta*(p(1)+eps))];
          
          hold on
          plot(hu(:),hv(:), color)  % Plot arrow head
          grid on
          xlabel('x')
          ylabel('y')
      
      else
          error('p0 and p1 must have the same dimension')
      end
  else
      error('this function only accepts 2D or 3D vector')
  end