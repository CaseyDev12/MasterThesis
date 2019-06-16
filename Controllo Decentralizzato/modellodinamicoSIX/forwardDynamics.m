function [ddqDH]=forwardDynamics(tau, qDH, dqDH, JTh)

         B_q = zeros(8,8);  
         Centrifugo = zeros(8,1);
     Attr_Viscoso = zeros(8,1);
     Gravita =  zeros(8,1);
   
     
      B_q = MatriceInerzia2(qDH(1:8)); 
     % if(length(qDH)>6) B_q(7,7) = 150; B_q(8,8) = 150; end
      
        
      

     Centrifugo = CCentrifugo3(qDH, dqDH);
      
      Attr_Viscoso = CAViscoso(dqDH); 
      %Attr_Statico = 0*CAStatico(dqDH);  if(length(qDH)>6) Attr_Statico(7:8) = 0; end
      Gravita= CGravita2(qDH);
     %q = dh2comau(qDH);
     % JTh = (H')^-1*(mat_jac(q))'*h;
      ddqDH = B_q^-1*(tau-Centrifugo-Attr_Viscoso-Gravita-JTh);