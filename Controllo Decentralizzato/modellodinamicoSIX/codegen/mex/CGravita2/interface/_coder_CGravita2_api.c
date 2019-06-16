/*
 * _coder_CGravita2_api.c
 *
 * Code generation for function '_coder_CGravita2_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CGravita2.h"
#include "_coder_CGravita2_api.h"
#include "CGravita2_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *qDH, const
  char_T *identifier))[8];
static const mxArray *emlrt_marshallOut(const real_T u[8]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8]
{
  real_T (*y)[8];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8]
{
  real_T (*ret)[8];
  static const int32_T dims[2] = { 1, 8 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[8])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *qDH, const
  char_T *identifier))[8]
{
  real_T (*y)[8];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(qDH), &thisId);
  emlrtDestroyArray(&qDH);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u[8])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 0 };

  static const int32_T iv1[1] = { 8 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv1, 1);
  emlrtAssign(&y, m0);
  return y;
}

void CGravita2_api(const mxArray * const prhs[1], const mxArray *plhs[1])
{
  real_T (*Gravita)[8];
  real_T (*qDH)[8];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  Gravita = (real_T (*)[8])mxMalloc(sizeof(real_T [8]));

  /* Marshall function inputs */
  qDH = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "qDH");

  /* Invoke the target function */
  CGravita2(&st, *qDH, *Gravita);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*Gravita);
}

/* End of code generation (_coder_CGravita2_api.c) */
