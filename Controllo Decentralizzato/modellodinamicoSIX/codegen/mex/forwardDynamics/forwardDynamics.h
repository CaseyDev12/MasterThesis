/*
 * forwardDynamics.h
 *
 * Code generation for function 'forwardDynamics'
 *
 */

#ifndef FORWARDDYNAMICS_H
#define FORWARDDYNAMICS_H

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
extern void forwardDynamics(const emlrtStack *sp, const real_T tau[8], const
  real_T qDH[8], const real_T dqDH[8], real_T ddqDH[8]);

#endif

/* End of code generation (forwardDynamics.h) */
