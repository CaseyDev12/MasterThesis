function [a,d,alpha] = dh_table
%
% SIX - Gennaio 2005
%
% [a,d,alpha] = dh_table
% 
% Carica i valori numerici delle costanti di denavit-hartenberg
%
% Uscite:
%   a     : vettore 6x1 dei termini ai
%   d     : vettore 6x1 dei termini di
%   alpha : vettore 6x1 dei termini alphai
% Note:
%   le distanze sono in metri, gli angoli in radianti


% ***********************************************************************************************************************
% Caricamento dei dati che definiscono le costanti del robot
% ***********************************************************************************************************************

%SIX_INIT_XX001;

a     = [   0.1500
    0.5900
    0.1300
         0
         0
         0];% TabellaDH.a;
d     = [    0.4500
         0
         0
    0.6471
         0
    0.0950];

alpha = [ -1.5708
         0
   -1.5708
    1.5708
   -1.5708
         0]; %TabellaDH.alpha;
