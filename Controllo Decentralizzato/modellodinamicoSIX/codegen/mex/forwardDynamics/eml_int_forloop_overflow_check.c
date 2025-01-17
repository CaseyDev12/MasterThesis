/*
 * eml_int_forloop_overflow_check.c
 *
 * Code generation for function 'eml_int_forloop_overflow_check'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "eml_int_forloop_overflow_check.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 86,  /* lineNo */
  15,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

/* Function Definitions */
void check_forloop_overflow_error(const emlrtStack *sp, boolean_T overflow)
{
  if (overflow) {
    emlrtErrorWithMessageIdR2012b(sp, &emlrtRTEI,
      "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
  }
}

/* End of code generation (eml_int_forloop_overflow_check.c) */
