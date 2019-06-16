function [u_stim] = compute_u_Stim(sig_des, dsig_des, x_stim, obj, contr_hint)

global Jsig ksigma invJsig

% sigma calcolata in x stimata dall'i-esimo robot
if(obj.dynamics==0 || contr_hint==0)
    sig_stim = Jsig*x_stim;

    % gamma stimato dall'i-esimo robot
    gamma_stim = dsig_des + ksigma*(sig_des - sig_stim);

    % u stimato dall'i-esimo robot
    u_stim = invJsig*gamma_stim;
else
    sig_stim = Jsig(1:6,:)*x_stim;

    % gamma stimato dall'i-esimo robot
    gamma_stim = dsig_des(1:6) + ksigma*(sig_des(1:6) - sig_stim);

    % u stimato dall'i-esimo robot
    u_stim = invJsig(:,1:6)*gamma_stim;
end

end

