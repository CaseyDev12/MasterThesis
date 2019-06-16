function []=disegnaR(R)

p1 =  + 0.15*R(1:3, 1)';
p2 =  + 0.15*R(1:3, 2)'; 
p3 =  + 0.15*R(1:3, 3)'; 

vectarrow(zeros(1,3), p1); text(p1(1), p1(2), p1(3), 'X')
vectarrow(zeros(1,3), p2); text(p2(1), p2(2), p2(3), 'Y')
vectarrow(zeros(1,3), p3); text(p3(1), p3(2), p3(3), 'Z')

p1 =  0.25*[1 0 0];
p2 =  0.25*[0 1 0]; 
p3 =  0.25*[0 0 1];

vectarrow(zeros(1,3), p1, 'r'); text(p1(1), p1(2), p1(3), 'Xo')
vectarrow(zeros(1,3), p2, 'r'); text(p2(1), p2(2), p2(3), 'Yo')
vectarrow(zeros(1,3), p3, 'r'); text(p3(1), p3(2), p3(3), 'Zo')