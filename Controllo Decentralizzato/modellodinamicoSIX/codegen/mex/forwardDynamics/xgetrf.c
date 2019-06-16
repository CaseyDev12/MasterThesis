/*
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "xgetrf.h"
#include "eml_int_forloop_overflow_check.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo o_emlrtRSI = { 20,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 10,  /* lineNo */
  "int",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\int.m"/* pathName */
};

static emlrtRSInfo kj_emlrtRSI = { 28, /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo lj_emlrtRSI = { 36, /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo mj_emlrtRSI = { 50, /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo nj_emlrtRSI = { 58, /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo oj_emlrtRSI = { 23, /* lineNo */
  "ixamax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\ixamax.m"/* pathName */
};

static emlrtRSInfo pj_emlrtRSI = { 24, /* lineNo */
  "ixamax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\ixamax.m"/* pathName */
};

static emlrtRSInfo qj_emlrtRSI = { 45, /* lineNo */
  "xgeru",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru.m"/* pathName */
};

static emlrtRSInfo rj_emlrtRSI = { 44, /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo sj_emlrtRSI = { 45, /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo tj_emlrtRSI = { 81, /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo uj_emlrtRSI = { 96, /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo vj_emlrtRSI = { 15, /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

static emlrtRSInfo wj_emlrtRSI = { 41, /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo xj_emlrtRSI = { 54, /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

/* Function Definitions */
void xgetrf(const emlrtStack *sp, real_T A[64], int32_T ipiv[8])
{
  int32_T iy;
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T smax;
  int32_T jy;
  real_T s;
  int32_T b;
  int32_T b_j;
  int32_T ijA;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kj_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  for (iy = 0; iy < 8; iy++) {
    ipiv[iy] = 1 + iy;
  }

  for (j = 0; j < 7; j++) {
    c = j * 9;
    b_st.site = &lj_emlrtRSI;
    c_st.site = &oj_emlrtRSI;
    iy = 0;
    ix = c;
    smax = muDoubleScalarAbs(A[c]);
    d_st.site = &pj_emlrtRSI;
    for (jy = 2; jy <= 8 - j; jy++) {
      ix++;
      s = muDoubleScalarAbs(A[ix]);
      if (s > smax) {
        iy = jy - 1;
        smax = s;
      }
    }

    if (A[c + iy] != 0.0) {
      if (iy != 0) {
        ipiv[j] = (j + iy) + 1;
        ix = j;
        iy += j;
        for (jy = 0; jy < 8; jy++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 8;
          iy += 8;
        }
      }

      b = (c - j) + 8;
      b_st.site = &mj_emlrtRSI;
      for (iy = c + 1; iy + 1 <= b; iy++) {
        A[iy] /= A[c];
      }
    }

    b_st.site = &nj_emlrtRSI;
    c_st.site = &qj_emlrtRSI;
    d_st.site = &rj_emlrtRSI;
    e_st.site = &tj_emlrtRSI;
    f_st.site = &p_emlrtRSI;
    e_st.site = &uj_emlrtRSI;
    f_st.site = &p_emlrtRSI;
    d_st.site = &sj_emlrtRSI;
    e_st.site = &vj_emlrtRSI;
    iy = c;
    jy = c + 8;
    f_st.site = &wj_emlrtRSI;
    for (b_j = 1; b_j <= 7 - j; b_j++) {
      smax = A[jy];
      if (A[jy] != 0.0) {
        ix = c + 1;
        b = (iy - j) + 16;
        f_st.site = &xj_emlrtRSI;
        if ((!(iy + 10 > b)) && (b > 2147483646)) {
          g_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&g_st, true);
        }

        for (ijA = iy + 9; ijA + 1 <= b; ijA++) {
          A[ijA] += A[ix] * -smax;
          ix++;
        }
      }

      jy += 8;
      iy += 8;
    }
  }
}

/* End of code generation (xgetrf.c) */
