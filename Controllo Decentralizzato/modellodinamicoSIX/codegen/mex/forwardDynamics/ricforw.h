/*
 * ricforw.h
 *
 * Code generation for function 'ricforw'
 *
 */

#ifndef RICFORW_H
#define RICFORW_H

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
extern void ricforw(const real_T q[6], const real_T dq[6], const real_T ddq[6],
                    real_T w[18], real_T dw[18], real_T ddp[18]);

#endif

/* End of code generation (ricforw.h) */
