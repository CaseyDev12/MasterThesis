/*
 * _coder_forwardDynamics_api.c
 *
 * Code generation for function '_coder_forwardDynamics_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "_coder_forwardDynamics_api.h"
#include "forwardDynamics_data.h"

/* Function Declarations */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tau,
  const char_T *identifier))[8];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *qDH,
  const char_T *identifier))[8];
static const mxArray *emlrt_marshallOut(const real_T u[8]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8];
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8];
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8];

/* Function Definitions */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tau,
  const char_T *identifier))[8]
{
  real_T (*y)[8];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(tau), &thisId);
  emlrtDestroyArray(&tau);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[8]
{
  real_T (*y)[8];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *qDH,
  const char_T *identifier))[8]
{
  real_T (*y)[8];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(qDH), &thisId);
  emlrtDestroyArray(&qDH);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u[8])
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv8[1] = { 0 };

  static const int32_T iv9[1] = { 8 };

  y = NULL;
  m3 = emlrtCreateNumericArray(1, iv8, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m3, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m3, iv9, 1);
  emlrtAssign(&y, m3);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8]
{
  real_T (*y)[8];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8]
{
  real_T (*ret)[8];
  static const int32_T dims[1] = { 8 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[8])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8]
{
  real_T (*ret)[8];
  static const int32_T dims[2] = { 1, 8 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[8])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  void forwardDynamics_api(const mxArray * const prhs[3], const mxArray *plhs[1])
{
  real_T (*ddqDH)[8];
  real_T (*tau)[8];
  real_T (*qDH)[8];
  real_T (*dqDH)[8];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  ddqDH = (real_T (*)[8])mxMalloc(sizeof(real_T [8]));

  /* Marshall function inputs */
  tau = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "tau");
  qDH = e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "qDH");
  dqDH = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "dqDH");

  /* Invoke the target function */
  forwardDynamics(&st, *tau, *qDH, *dqDH, *ddqDH);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*ddqDH);
}

/* End of code generation (_coder_forwardDynamics_api.c) */
