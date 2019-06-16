/*
 * forwardDynamics.c
 *
 * Code generation for function 'forwardDynamics'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "MatriceInerzia2.h"
#include "CCentrifugo3.h"
#include "CGravita2.h"
#include "mpower.h"
#include "forwardDynamics_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 10,    /* lineNo */
  "forwardDynamics",                   /* fcnName */
  "C:\\Users\\Ines\\Google Drive\\Tesi\\Campionati\\modellodinamicoSIX\\forwardDynamics.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 16,  /* lineNo */
  "forwardDynamics",                   /* fcnName */
  "C:\\Users\\Ines\\Google Drive\\Tesi\\Campionati\\modellodinamicoSIX\\forwardDynamics.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 18,  /* lineNo */
  "forwardDynamics",                   /* fcnName */
  "C:\\Users\\Ines\\Google Drive\\Tesi\\Campionati\\modellodinamicoSIX\\forwardDynamics.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 20,  /* lineNo */
  "forwardDynamics",                   /* fcnName */
  "C:\\Users\\Ines\\Google Drive\\Tesi\\Campionati\\modellodinamicoSIX\\forwardDynamics.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 24,  /* lineNo */
  "forwardDynamics",                   /* fcnName */
  "C:\\Users\\Ines\\Google Drive\\Tesi\\Campionati\\modellodinamicoSIX\\forwardDynamics.m"/* pathName */
};

/* Function Definitions */
void forwardDynamics(const emlrtStack *sp, const real_T tau[8], const real_T
                     qDH[8], const real_T dqDH[8], real_T ddqDH[8])
{
  real_T B_q[64];
  real_T Centrifugo[8];
  real_T Attr_Viscoso[8];
  real_T Gravita[8];
  int32_T i;
  real_T dq[6];
  real_T a[6];
  real_T dqm[6];
  real_T Phi[36];
  int32_T i0;
  static const real_T b_a[36] = { -147.8019, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 153.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 141.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -51.417,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 81.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0 };

  real_T c_a[36];
  int32_T i1;
  static const real_T b[6] = { -0.226577007285678, 0.307912520564962,
    0.300193611250022, -0.034429350797965, 0.06335854029274, 0.022725708748977 };

  static const int8_T d_a[36] = { -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, -1 };

  real_T A[64];
  real_T b_tau[8];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /* function [ddqDH]=forwardDynamics(tau, qDH, dqDH, JTh) */
  st.site = &emlrtRSI;
  MatriceInerzia2(qDH, B_q);

  /*  if(length(qDH)>6) B_q(7,7) = 150; B_q(8,8) = 150; end */
  st.site = &b_emlrtRSI;
  CCentrifugo3(qDH, dqDH, Centrifugo);
  st.site = &c_emlrtRSI;

  /*  Ingressi: */
  /*         dqDH : vettori 6x1 secondo convenzioni DH in rad/s */
  /*   */
  /*  Uscite: */
  /*        Attr_Viscoso: Coppie di Attrito Viscoso F*dqDH in convenzione DH */
  /*  */
  /*  Note: */
  /*    le coppie in uscita sono in convenzione DH e sono quelle richieste agli attuatori (a valle dei riduttori) */
  /*  */
  /*  File letti: */
  /*             costanti.m : definizione delle costanti dinamiche utilizzate */
  /*  DUBBI:  */
  /*             non sono sicuro sulla conversione da cioppie COMAU a coppie DH */
  /*             e sul fatto che siano presenti le velocit� dei motori */
  /*  ********************************************************************************************************************** */
  /*  Costanti */
  /*  ********************************************************************************************************************** */
  /*  Lettura dei dati registrati in "costanti.m" */
  /*  addpath('../modello SIX/') */
  /* costanti; */
  /* vettore dei parametri di attrito viscoso */
  /* fv = DYN.MODEL(42:2:52);  */
  /* fv = theta(42:2:52);  */
  for (i = 0; i < 8; i++) {
    Attr_Viscoso[i] = 0.0;
    Gravita[i] = dqDH[i] * 180.0 / 3.1415926535897931;
  }

  /*  Converte le velocit�/accelerazioni dei giunti dalla convenzione COMAU alla convenzione DH */
  /*  */
  /*  Ingressi:  */
  /*    dqdh   : vettore 6x1 delle velocit� (o accelerazioni) in convenzione DH */
  /*  Uscite: */
  /*    dqcomau: vettore 6x1 delle velocit� (o accelerazioni) in convenzione */
  /*    COMAU */
  /*  Note: */
  /*    le unit� di misura sono ininfluenti */
  /*    IL FILE E' STATO CREATO DA MARINO */
  dq[0] = -Gravita[0];
  dq[1] = Gravita[1];
  dq[2] = -Gravita[2];
  dq[3] = -Gravita[3];
  dq[4] = Gravita[4];
  dq[5] = -Gravita[5];

  /*  dqdh(1) = -dqcomau(1); */
  /*  dqdh(2) =  dqcomau(2); */
  /*  dqdh(3) = -dqcomau(3); */
  /*  dqdh(4) = -dqcomau(4); */
  /*  dqdh(5) =  dqcomau(5); */
  /*  dqdh(6) = -dqcomau(6); */
  /*  Velocit� dei motori */
  for (i = 0; i < 6; i++) {
    a[i] = 0.0;
    for (i0 = 0; i0 < 6; i0++) {
      a[i] += b_a[i + 6 * i0] * dq[i0];
    }

    dqm[i] = a[i] * 0.017453292519943295;
  }

  /*  in convenzione COMAU in rad/sec */
  memset(&Phi[0], 0, 36U * sizeof(real_T));
  i = 0;
  while (i < 6) {
    Phi[i + 6 * i] = dqm[i];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Attr_Viscoso =  zeros(6,1); */
  for (i = 0; i < 6; i++) {
    a[i] = 0.0;
    for (i0 = 0; i0 < 6; i0++) {
      c_a[i + 6 * i0] = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        c_a[i + 6 * i0] += (real_T)d_a[i + 6 * i1] * Phi[i1 + 6 * i0];
      }

      a[i] += c_a[i + 6 * i0] * b[i0];
    }

    Attr_Viscoso[i] = a[i];
  }

  for (i = 0; i < 2; i++) {
    Attr_Viscoso[6 + i] = 10.0 * dqDH[6 + i];
  }

  /* Attr_Statico = 0*CAStatico(dqDH);  if(length(qDH)>6) Attr_Statico(7:8) = 0; end */
  st.site = &d_emlrtRSI;
  CGravita2(qDH, Gravita);

  /* q = dh2comau(qDH); */
  /*  JTh = (H')^-1*(mat_jac(q))'*h; */
  /* ddqDH = B_q^-1*(tau-Centrifugo-Attr_Viscoso-Gravita-JTh); */
  st.site = &e_emlrtRSI;
  c_mpower(&st, B_q, A);
  for (i = 0; i < 8; i++) {
    b_tau[i] = ((tau[i] - Centrifugo[i]) - Attr_Viscoso[i]) - Gravita[i];
  }

  for (i = 0; i < 8; i++) {
    ddqDH[i] = 0.0;
    for (i0 = 0; i0 < 8; i0++) {
      ddqDH[i] += A[i + (i0 << 3)] * b_tau[i0];
    }
  }
}

/* End of code generation (forwardDynamics.c) */
