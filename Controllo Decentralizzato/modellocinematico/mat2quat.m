function q = mat2quat(Mat)

q = zeros(1,4);
q(1) = 1/2*sqrt(trace(Mat)+1);

q(2) = signum(Mat(3,2)-Mat(2,3))*sqrt(max([Mat(1,1)-Mat(2,2)-Mat(3,3)+1,0]));
q(3) = signum(Mat(1,3)-Mat(3,1))*sqrt(max([Mat(2,2)-Mat(3,3)-Mat(1,1)+1,0]));
q(4) = signum(Mat(2,1)-Mat(1,2))*sqrt(max([Mat(3,3)-Mat(1,1)-Mat(2,2)+1, 0]));

q(2:end) = q(2:end)/2;