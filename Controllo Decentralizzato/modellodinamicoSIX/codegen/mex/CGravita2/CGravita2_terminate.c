/*
 * CGravita2_terminate.c
 *
 * Code generation for function 'CGravita2_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CGravita2.h"
#include "CGravita2_terminate.h"
#include "_coder_CGravita2_mex.h"
#include "CGravita2_data.h"

/* Function Definitions */
void CGravita2_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void CGravita2_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (CGravita2_terminate.c) */
