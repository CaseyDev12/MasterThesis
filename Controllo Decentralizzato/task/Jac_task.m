function J = Jac_task(N)

J1 = repmat(eye(6)/N,1,N);

J2 = zeros(6*(N-1),6*N);

for i=0:N-2
    J2(1+i*6:6+i*6,1+i*6:12+i*6) = [-eye(6) eye(6)];
end

J = vertcat(J1, J2);

end