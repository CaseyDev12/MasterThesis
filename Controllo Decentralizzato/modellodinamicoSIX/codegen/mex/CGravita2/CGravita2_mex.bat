@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=CGravita2_mex
set MEX_NAME=CGravita2_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for CGravita2 > CGravita2_mex.mki
echo COMPILER=%COMPILER%>> CGravita2_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> CGravita2_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> CGravita2_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> CGravita2_mex.mki
echo LINKER=%LINKER%>> CGravita2_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> CGravita2_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> CGravita2_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> CGravita2_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> CGravita2_mex.mki
echo BORLAND=%BORLAND%>> CGravita2_mex.mki
echo OMPFLAGS= >> CGravita2_mex.mki
echo OMPLINKFLAGS= >> CGravita2_mex.mki
echo EMC_COMPILER=msvcsdk>> CGravita2_mex.mki
echo EMC_CONFIG=optim>> CGravita2_mex.mki
"C:\Program Files\MATLAB\R2016b\bin\win64\gmake" -B -f CGravita2_mex.mk
