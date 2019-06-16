function sig = ComputeTask(sig_prec)

global tf_task sig_in time N s_pp_pos s_pp_or tc_pos tc_or L_pos L_or
global sub_pos sub_or

sf_pos = L_pos;
sf_or = L_or;

si = 0;

sig_pos = zeros(3,N);
s_pos = zeros(N,1);
for i=1:N
    if(time <= tc_pos(i))
        s_pos(i) = si + (1/2) * (s_pp_pos(i)) * time^2;
    else
        if(time <= (tf_task - tc_pos(i)))
            s_pos(i) = si + (s_pp_pos(i)) * tc_pos(i) * (time - tc_pos(i)/2);
        else
            s_pos(i) = sf_pos(i) - (1/2) * (s_pp_pos(i))*(tf_task - time)^2;
        end
    end
    sig_pos(:,i) = sig_in(1+(i-1)*6:3+(i-1)*6) + (sub_pos(:,i))*(s_pos(i)/(sf_pos(i)));
    if(isnan(sig_pos(1,i)) && isnan(sig_pos(2,i)) && isnan(sig_pos(3,i)))
        sig_pos(:,i) = sig_prec(1+(i-1)*6:3+(i-1)*6,1);
    end
end

sig_or = zeros(3,N);
s_or = zeros(1,N);
for i=1:N
    if(time <= tc_or(i))
        s_or(i) = si + (1/2) * (s_pp_or(i)) * time^2;
    else
        if(time <= (tf_task - tc_or(i)))
            s_or(i) = si + (s_pp_or(i)) * tc_or(i) * (time - tc_or(i)/2);
        else
            s_or(i) = sf_or(i) - (1/2) * (s_pp_or(i))*(tf_task - time)^2;
        end
    end
    sig_or(:,i) = sig_in(4+(i-1)*6:6+(i-1)*6) + (sub_or(:,i))*(s_or(i)/(sf_or(i)));
    if(isnan(sig_or(1,i)) && isnan(sig_or(2,i)) && isnan(sig_or(3,i)))
        sig_or(:,i) = sig_prec(4+(i-1)*6:6+(i-1)*6,1);
    end
end


sig = zeros(6*N,1);
for i=0:N-1
    sig(1+i*6:3+i*6,1) = sig_pos(:,i+1);
    sig(4+i*6:6+i*6,1) = sig_or(:,i+1);
end



end




