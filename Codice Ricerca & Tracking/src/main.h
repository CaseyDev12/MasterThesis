//
// File: main.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 08-Jun-2017 13:39:02
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
#ifndef MAIN_H
#define MAIN_H

// Include Files
#include <cmath>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "../TrajPlanningIK_UR10/rt_defines.h"
#include "../TrajPlanningIK_UR10/rt_nonfinite.h"
#include "../TrajPlanningIK_UR10/rtwtypes.h"
#include "../TrajPlanningIK_UR10/TrajPlanningIK_UR10_types.h"
#include  <iostream>

using namespace std;

// Function Declarations
extern double* main_control(float qActual[6],int &size);

#endif

//
// File trailer for main.h
//
// [EOF]
//
