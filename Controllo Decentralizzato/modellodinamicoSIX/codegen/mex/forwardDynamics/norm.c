/*
 * norm.c
 *
 * Code generation for function 'norm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "norm.h"

/* Function Definitions */
real_T norm(const real_T x[64])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  real_T s;
  int32_T i;
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 8)) {
    s = 0.0;
    for (i = 0; i < 8; i++) {
      s += muDoubleScalarAbs(x[i + (j << 3)]);
    }

    if (muDoubleScalarIsNaN(s)) {
      y = rtNaN;
      exitg1 = true;
    } else {
      if (s > y) {
        y = s;
      }

      j++;
    }
  }

  return y;
}

/* End of code generation (norm.c) */
