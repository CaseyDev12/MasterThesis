/*
 * mpower.c
 *
 * Code generation for function 'mpower'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "mpower.h"
#include "warning.h"
#include "norm.h"
#include "xgetrf.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 41,  /* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 13,  /* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 63,  /* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo dj_emlrtRSI = { 75, /* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo ej_emlrtRSI = { 21, /* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo fj_emlrtRSI = { 22, /* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo gj_emlrtRSI = { 172,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo hj_emlrtRSI = { 179,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo ij_emlrtRSI = { 182,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo jj_emlrtRSI = { 189,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo yj_emlrtRSI = { 70, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo ak_emlrtRSI = { 72, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo bk_emlrtRSI = { 73, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo ck_emlrtRSI = { 68, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo dk_emlrtRSI = { 42, /* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo ek_emlrtRSI = { 46, /* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtMCInfo c_emlrtMCI = { 52,  /* lineNo */
  19,                                  /* colNo */
  "flt2str",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"/* pName */
};

static emlrtRSInfo gk_emlrtRSI = { 52, /* lineNo */
  "flt2str",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"/* pathName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m5;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m5, 2, pArrays, "sprintf", true, location);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(c_sprintf), &thisId, y);
  emlrtDestroyArray(&c_sprintf);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, ret, 14);
  emlrtDestroyArray(&src);
}

real_T b_mpower(real_T a)
{
  return a * a;
}

void c_mpower(const emlrtStack *sp, const real_T a[64], real_T c[64])
{
  real_T x[64];
  int32_T b_c;
  int32_T ipiv[8];
  int8_T p[8];
  int32_T k;
  int32_T j;
  int32_T i;
  real_T n1x;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  real_T n1xinv;
  real_T rc;
  const mxArray *y;
  char_T rfmt[6];
  static const char_T cv3[6] = { '%', '1', '4', '.', '6', 'e' };

  const mxArray *m1;
  static const int32_T iv3[2] = { 1, 6 };

  const mxArray *b_y;
  char_T cv4[14];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
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
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  c_st.site = &dj_emlrtRSI;
  d_st.site = &ej_emlrtRSI;
  for (b_c = 0; b_c < 64; b_c++) {
    c[b_c] = 0.0;
    x[b_c] = a[b_c];
  }

  e_st.site = &gj_emlrtRSI;
  xgetrf(&e_st, x, ipiv);
  for (b_c = 0; b_c < 8; b_c++) {
    p[b_c] = (int8_T)(1 + b_c);
  }

  for (k = 0; k < 7; k++) {
    if (ipiv[k] > 1 + k) {
      b_c = p[ipiv[k] - 1];
      p[ipiv[k] - 1] = p[k];
      p[k] = (int8_T)b_c;
    }
  }

  for (k = 0; k < 8; k++) {
    b_c = p[k] - 1;
    c[k + ((p[k] - 1) << 3)] = 1.0;
    e_st.site = &hj_emlrtRSI;
    for (j = k; j + 1 < 9; j++) {
      if (c[j + (b_c << 3)] != 0.0) {
        e_st.site = &ij_emlrtRSI;
        for (i = j + 1; i + 1 < 9; i++) {
          c[i + (b_c << 3)] -= c[j + (b_c << 3)] * x[i + (j << 3)];
        }
      }
    }
  }

  e_st.site = &jj_emlrtRSI;
  f_st.site = &yj_emlrtRSI;
  f_st.site = &yj_emlrtRSI;
  f_st.site = &ak_emlrtRSI;
  f_st.site = &bk_emlrtRSI;
  f_st.site = &ck_emlrtRSI;
  n1x = 1.0;
  DIAGA = 'N';
  TRANSA = 'N';
  UPLO = 'U';
  SIDE = 'L';
  m_t = (ptrdiff_t)8;
  n_t = (ptrdiff_t)8;
  lda_t = (ptrdiff_t)8;
  ldb_t = (ptrdiff_t)8;
  dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &n1x, &x[0], &lda_t, &c[0],
        &ldb_t);
  d_st.site = &fj_emlrtRSI;
  n1x = norm(a);
  n1xinv = norm(c);
  rc = 1.0 / (n1x * n1xinv);
  if ((n1x == 0.0) || (n1xinv == 0.0) || (rc == 0.0)) {
    e_st.site = &dk_emlrtRSI;
    warning(&e_st);
  } else {
    if (muDoubleScalarIsNaN(rc) || (rc < 2.2204460492503131E-16)) {
      e_st.site = &ek_emlrtRSI;
      for (b_c = 0; b_c < 6; b_c++) {
        rfmt[b_c] = cv3[b_c];
      }

      y = NULL;
      m1 = emlrtCreateCharArray(2, iv3);
      emlrtInitCharArrayR2013a(&e_st, 6, m1, &rfmt[0]);
      emlrtAssign(&y, m1);
      b_y = NULL;
      m1 = emlrtCreateDoubleScalar(rc);
      emlrtAssign(&b_y, m1);
      f_st.site = &gk_emlrtRSI;
      emlrt_marshallIn(&f_st, b_sprintf(&f_st, y, b_y, &c_emlrtMCI), "sprintf",
                       cv4);
      e_st.site = &ek_emlrtRSI;
      b_warning(&e_st, cv4);
    }
  }
}

void mpower(void)
{
}

/* End of code generation (mpower.c) */
