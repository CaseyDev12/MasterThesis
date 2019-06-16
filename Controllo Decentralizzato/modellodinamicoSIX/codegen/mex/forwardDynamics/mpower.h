/*
 * mpower.h
 *
 * Code generation for function 'mpower'
 *
 */

#ifndef MPOWER_H
#define MPOWER_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "forwardDynamics_types.h"

/* Function Declarations */
extern real_T b_mpower(real_T a);

#ifdef __WATCOMC__

#pragma aux b_mpower value [8087];

#endif

extern void c_mpower(const emlrtStack *sp, const real_T a[64], real_T c[64]);
extern void mpower(void);

#endif

/* End of code generation (mpower.h) */
