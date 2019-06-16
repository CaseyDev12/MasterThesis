/*
 * CGravita2_initialize.c
 *
 * Code generation for function 'CGravita2_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CGravita2.h"
#include "CGravita2_initialize.h"
#include "_coder_CGravita2_mex.h"
#include "CGravita2_data.h"

/* Function Definitions */
void CGravita2_initialize(void)
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

/* End of code generation (CGravita2_initialize.c) */
