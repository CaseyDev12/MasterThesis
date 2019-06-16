@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=forwardDynamics_mex
set MEX_NAME=forwardDynamics_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for forwardDynamics > forwardDynamics_mex.mki
echo COMPILER=%COMPILER%>> forwardDynamics_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> forwardDynamics_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> forwardDynamics_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> forwardDynamics_mex.mki
echo LINKER=%LINKER%>> forwardDynamics_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> forwardDynamics_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> forwardDynamics_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> forwardDynamics_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> forwardDynamics_mex.mki
echo BORLAND=%BORLAND%>> forwardDynamics_mex.mki
echo OMPFLAGS= >> forwardDynamics_mex.mki
echo OMPLINKFLAGS= >> forwardDynamics_mex.mki
echo EMC_COMPILER=msvcsdk>> forwardDynamics_mex.mki
echo EMC_CONFIG=optim>> forwardDynamics_mex.mki
"C:\Program Files\MATLAB\R2016b\bin\win64\gmake" -B -f forwardDynamics_mex.mk
