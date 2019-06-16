/*
 * xgetrf.h
 *
 * Code generation for function 'xgetrf'
 *
 */

#ifndef XGETRF_H
#define XGETRF_H

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
extern void xgetrf(const emlrtStack *sp, real_T A[64], int32_T ipiv[8]);

#endif

/* End of code generation (xgetrf.h) */
