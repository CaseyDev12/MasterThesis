/*
 * forwardDynamics_initialize.c
 *
 * Code generation for function 'forwardDynamics_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "forwardDynamics_initialize.h"
#include "_coder_forwardDynamics_mex.h"
#include "forwardDynamics_data.h"

/* Function Definitions */
void forwardDynamics_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (forwardDynamics_initialize.c) */
