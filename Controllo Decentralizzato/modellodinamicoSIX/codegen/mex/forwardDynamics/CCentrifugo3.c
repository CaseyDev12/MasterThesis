/*
 * CCentrifugo3.c
 *
 * Code generation for function 'CCentrifugo3'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "CCentrifugo3.h"
#include "ricforw.h"
#include "mpower.h"
#include "CGravita2.h"
#include "comau2dh_vel.h"
#include "comau2dh.h"
#include "dh2comau_vel.h"
#include "dh2comau.h"
#include "blas.h"

/* Function Definitions */
void CCentrifugo3(const real_T qDH[8], const real_T dqDH[8], real_T Centrifugo1
                  [8])
{
  real_T temp[8];
  int32_T i;
  real_T q[6];
  real_T ddq[6];
  real_T dv0[6];
  real_T w[18];
  real_T dw[18];
  real_T ddp[18];
  real_T qdh[6];
  real_T Phi[240];
  real_T alpha1;
  real_T beta1;
  char_T TRANSB;
  char_T TRANSA;
  real_T y[240];
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  static const real_T a[36] = { -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0 };

  int32_T i6;
  static const real_T b[40] = { -0.244302919349, 0.072866, -0.047671, -0.008851,
    -0.002462, 9.2645460000000011, -0.250656115629, 0.000725, -0.005893,
    0.111035748823944, -0.008601996447, 4.0E-6, 0.000714, -6.0E-6, 0.2688,
    8.0788265E-5, -8.199406E-6, 0.0, -7.0E-6, 1.0E-6, 0.000118, 0.105,
    31.29460847701786, 30.033916074602, -16.7938007456, 0.75791928520612,
    29.2441747456, 4.168006522089, 4.264218434123, 2.002822066414367,
    -0.55075098311033, 3.1667594978143669, -0.072479417795, -0.022739, 0.090513,
    0.014738636656691, 0.052804900291, 0.002706, 0.005561, 6.0E-6 };

  /* Calcola i contributi di Coriolis e centrifughi */
  /*  Ingressi: */
  /*        qDH,ddqDH : vettori 6x1 secondo convenzioni DH in rad */
  /*   */
  /*  Uscite: */
  /*        Inerzia: Coppie di inerzia B(qDH)*ddqDH in convenzione DH */
  /*  */
  /*  Note: */
  /*    le coppie in uscita sono in convenzione DH e sono quelle richieste agli attuatori (a valle dei riduttori) */
  /*  */
  /*  File letti: */
  /*             costanti.m : definizione delle costanti dinamiche utilizzate */
  /*  DUBBI:  */
  /*             non sono sicuro sulla conversione da cioppie COMAU a coppie DH */
  /*  ********************************************************************************************************************** */
  /*  Costanti */
  /*  ********************************************************************************************************************** */
  /*  Lettura dei dati registrati in "costanti.m" */
  /* addpath('../modello SIX/') */
  /* costanti; */
  /* ************************************************************************************************************************ */
  /*  Cinematica diretta */
  /* ************************************************************************************************************************ */
  /*  Calcola, in numerico, le velocita' e le accelerazioni delle terne */
  for (i = 0; i < 8; i++) {
    Centrifugo1[i] = 0.0;
    temp[i] = qDH[i] * 180.0 / 3.1415926535897931;
  }

  dh2comau(temp, q);
  for (i = 0; i < 8; i++) {
    temp[i] = dqDH[i] * 180.0 / 3.1415926535897931;
  }

  for (i = 0; i < 6; i++) {
    ddq[i] = 0.0;
  }

  dh2comau_vel(temp, dv0);
  ricforw(q, dv0, ddq, w, dw, ddp);

  /*  ********************************************************************************************************************** */
  /*  Riorganizzazione dei vettori */
  /*  ********************************************************************************************************************** */
  /*  Riorganizza i vettori velocita' */
  /*  Riorganizza i vettori accelerazioni */
  /*  Riorganizza i vettori accelerazioni lineari */
  /*  ********************************************************************************************************************** */
  /*  Conversione delle grandezze */
  /*  ********************************************************************************************************************** */
  /*  Posizioni */
  /*  Converte posizioni Comau in gradi in posizioni DH in radianti */
  comau2dh(q, qdh);

  /*  Riorganizzazione delle posizioni */
  /*  Velocit� */
  /*  Converte velocita' Comau in gradi/sec in velocita' DH in rad/sec */
  /*  Riorganizzazione delle velocita' */
  /*  Accelerazioni */
  /*  Converte accelerazioni Comau in gradi/sec^2 in accelerazioni DH in rad/sec^2 */
  comau2dh_vel(ddq, q);
  for (i = 0; i < 6; i++) {
    qdh[i] *= 0.017453292519943295;
    q[i] *= 0.017453292519943295;
  }

  /*  Riorganizzazione delle accelerazioni */
  /*  Velocit� dei motori */
  /*  in convenzione COMAU in rad/sec */
  /*  Regressore ridotto  in simbolico del robot 26-Jan-2005        */
  /*  Coppia: 1 */
  Phi[0] = ddp[2] * muDoubleScalarSin(qdh[1]) - 0.15 * (dw[3] + w[4] * w[5]);
  Phi[6] = (dw[4] - w[3] * w[5]) * muDoubleScalarSin(qdh[1]) + (dw[3] + w[4] *
    w[5]) * muDoubleScalarCos(qdh[1]);
  Phi[12] = (b_mpower(w[4]) - b_mpower(w[5])) * muDoubleScalarSin(qdh[1]) + (dw
    [5] - w[4] * w[3]) * muDoubleScalarCos(qdh[1]);
  Phi[18] = ((dw[7] * muDoubleScalarSin(qdh[2] + qdh[1]) - w[8] * w[6] *
              muDoubleScalarSin(qdh[2] + qdh[1])) + b_mpower(w[6]) *
             muDoubleScalarCos(qdh[2] + qdh[1])) - b_mpower(w[7]) *
    muDoubleScalarCos(qdh[2] + qdh[1]);
  Phi[24] = ((b_mpower(w[7]) * muDoubleScalarSin(qdh[2] + qdh[1]) - b_mpower(w[8])
              * muDoubleScalarSin(qdh[2] + qdh[1])) + dw[7] * muDoubleScalarCos
             (qdh[2] + qdh[1])) + w[8] * w[6] * muDoubleScalarCos(qdh[2] + qdh[1]);
  Phi[30] = 0.0;
  Phi[36] = ((ddp[8] * muDoubleScalarSin(qdh[3]) * muDoubleScalarCos(qdh[2]) -
              ((-muDoubleScalarSin(qdh[3]) * ddp[6] + muDoubleScalarCos(qdh[3]) *
                ddp[7]) + 0.13 * (muDoubleScalarSin(qdh[3]) * (-b_mpower(w[10])
    - b_mpower(w[11])) - muDoubleScalarCos(qdh[3]) * (-dw[10] + w[9] * w[11]))) *
              muDoubleScalarSin(qdh[2])) * muDoubleScalarSin(qdh[1]) + ((ddp[8] *
    muDoubleScalarSin(qdh[3]) * muDoubleScalarSin(qdh[2]) + ((-muDoubleScalarSin
    (qdh[3]) * ddp[6] + muDoubleScalarCos(qdh[3]) * ddp[7]) + 0.13 *
    (muDoubleScalarSin(qdh[3]) * (-b_mpower(w[10]) - b_mpower(w[11])) -
     muDoubleScalarCos(qdh[3]) * (-dw[10] + w[9] * w[11]))) * muDoubleScalarCos
    (qdh[2])) - 0.59 * (-muDoubleScalarSin(qdh[3]) * (-b_mpower(w[10]) -
    b_mpower(w[11])) + muDoubleScalarCos(qdh[3]) * (-dw[10] + w[9] * w[11]))) *
             muDoubleScalarCos(qdh[1])) - 0.15 * (-muDoubleScalarSin(qdh[3]) * (
    -b_mpower(w[10]) - b_mpower(w[11])) + muDoubleScalarCos(qdh[3]) * (-dw[10] +
    w[9] * w[11]));
  Phi[42] = (((dw[10] - w[9] * w[11]) * muDoubleScalarCos(qdh[3]) + (b_mpower(w
    [9]) - b_mpower(w[10])) * muDoubleScalarSin(qdh[3])) * muDoubleScalarCos
             (qdh[2]) - (dw[9] + w[10] * w[11]) * muDoubleScalarSin(qdh[2])) *
    muDoubleScalarSin(qdh[1]) + (((dw[10] - w[9] * w[11]) * muDoubleScalarCos
    (qdh[3]) + (b_mpower(w[9]) - b_mpower(w[10])) * muDoubleScalarSin(qdh[3])) *
    muDoubleScalarSin(qdh[2]) + (dw[9] + w[10] * w[11]) * muDoubleScalarCos(qdh
    [2])) * muDoubleScalarCos(qdh[1]);
  Phi[48] = (((dw[11] + w[10] * w[9]) * muDoubleScalarCos(qdh[3]) + (dw[9] - w
    [10] * w[11]) * muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2]) -
             (b_mpower(w[11]) - b_mpower(w[9])) * muDoubleScalarSin(qdh[2])) *
    muDoubleScalarSin(qdh[1]) + (((dw[11] + w[10] * w[9]) * muDoubleScalarCos
    (qdh[3]) + (dw[9] - w[10] * w[11]) * muDoubleScalarSin(qdh[3])) *
    muDoubleScalarSin(qdh[2]) + (b_mpower(w[11]) - b_mpower(w[9])) *
    muDoubleScalarCos(qdh[2])) * muDoubleScalarCos(qdh[1]);
  Phi[54] = 0.0;
  Phi[60] = ((((ddp[11] * muDoubleScalarSin(qdh[4]) + 0.64707 * (-dw[14] - w[12]
    * w[13])) * muDoubleScalarCos(qdh[3]) + ((-muDoubleScalarSin(qdh[4]) * ddp[9]
    + muDoubleScalarCos(qdh[4]) * ddp[10]) - 0.64707 * (muDoubleScalarCos(qdh[4])
    * (-b_mpower(w[13]) - b_mpower(w[14])) - muDoubleScalarSin(qdh[4]) * (-dw[13]
    + w[12] * w[14]))) * muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2])
              - (-ddp[11] * muDoubleScalarCos(qdh[4]) + 0.13 *
                 (muDoubleScalarSin(qdh[3]) * (muDoubleScalarCos(qdh[4]) *
    (-b_mpower(w[13]) - b_mpower(w[14])) - muDoubleScalarSin(qdh[4]) * (-dw[13]
    + w[12] * w[14])) - muDoubleScalarCos(qdh[3]) * (-dw[14] - w[12] * w[13]))) *
              muDoubleScalarSin(qdh[2])) * muDoubleScalarSin(qdh[1]) + ((((ddp
    [11] * muDoubleScalarSin(qdh[4]) + 0.64707 * (-dw[14] - w[12] * w[13])) *
    muDoubleScalarCos(qdh[3]) + ((-muDoubleScalarSin(qdh[4]) * ddp[9] +
    muDoubleScalarCos(qdh[4]) * ddp[10]) - 0.64707 * (muDoubleScalarCos(qdh[4]) *
    (-b_mpower(w[13]) - b_mpower(w[14])) - muDoubleScalarSin(qdh[4]) * (-dw[13]
    + w[12] * w[14]))) * muDoubleScalarSin(qdh[3])) * muDoubleScalarSin(qdh[2])
    + (-ddp[11] * muDoubleScalarCos(qdh[4]) + 0.13 * (muDoubleScalarSin(qdh[3]) *
    (muDoubleScalarCos(qdh[4]) * (-b_mpower(w[13]) - b_mpower(w[14])) -
     muDoubleScalarSin(qdh[4]) * (-dw[13] + w[12] * w[14])) - muDoubleScalarCos
    (qdh[3]) * (-dw[14] - w[12] * w[13]))) * muDoubleScalarCos(qdh[2])) - 0.59 *
              (-muDoubleScalarSin(qdh[3]) * (muDoubleScalarCos(qdh[4]) *
    (-b_mpower(w[13]) - b_mpower(w[14])) - muDoubleScalarSin(qdh[4]) * (-dw[13]
    + w[12] * w[14])) + muDoubleScalarCos(qdh[3]) * (-dw[14] - w[12] * w[13]))) *
             muDoubleScalarCos(qdh[1])) - 0.15 * (-muDoubleScalarSin(qdh[3]) *
    (muDoubleScalarCos(qdh[4]) * (-b_mpower(w[13]) - b_mpower(w[14])) -
     muDoubleScalarSin(qdh[4]) * (-dw[13] + w[12] * w[14])) + muDoubleScalarCos
    (qdh[3]) * (-dw[14] - w[12] * w[13]));
  Phi[66] = ((((dw[13] - w[12] * w[14]) * muDoubleScalarCos(qdh[4]) - (b_mpower
    (w[12]) - b_mpower(w[13])) * muDoubleScalarSin(qdh[4])) * muDoubleScalarCos
              (qdh[3]) + (-dw[12] - w[13] * w[14]) * muDoubleScalarSin(qdh[3])) *
             muDoubleScalarCos(qdh[2]) - ((dw[13] - w[12] * w[14]) *
              muDoubleScalarSin(qdh[4]) + (b_mpower(w[12]) - b_mpower(w[13])) *
              muDoubleScalarCos(qdh[4])) * muDoubleScalarSin(qdh[2])) *
    muDoubleScalarSin(qdh[1]) + ((((dw[13] - w[12] * w[14]) * muDoubleScalarCos
    (qdh[4]) - (b_mpower(w[12]) - b_mpower(w[13])) * muDoubleScalarSin(qdh[4])) *
    muDoubleScalarCos(qdh[3]) + (-dw[12] - w[13] * w[14]) * muDoubleScalarSin
    (qdh[3])) * muDoubleScalarSin(qdh[2]) + ((dw[13] - w[12] * w[14]) *
    muDoubleScalarSin(qdh[4]) + (b_mpower(w[12]) - b_mpower(w[13])) *
    muDoubleScalarCos(qdh[4])) * muDoubleScalarCos(qdh[2])) * muDoubleScalarCos
    (qdh[1]);
  Phi[72] = ((((dw[14] + w[12] * w[13]) * muDoubleScalarCos(qdh[4]) - (dw[12] -
    w[13] * w[14]) * muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) +
              (-b_mpower(w[14]) + b_mpower(w[12])) * muDoubleScalarSin(qdh[3])) *
             muDoubleScalarCos(qdh[2]) - ((dw[14] + w[12] * w[13]) *
              muDoubleScalarSin(qdh[4]) + (dw[12] - w[13] * w[14]) *
              muDoubleScalarCos(qdh[4])) * muDoubleScalarSin(qdh[2])) *
    muDoubleScalarSin(qdh[1]) + ((((dw[14] + w[12] * w[13]) * muDoubleScalarCos
    (qdh[4]) - (dw[12] - w[13] * w[14]) * muDoubleScalarSin(qdh[4])) *
    muDoubleScalarCos(qdh[3]) + (-b_mpower(w[14]) + b_mpower(w[12])) *
    muDoubleScalarSin(qdh[3])) * muDoubleScalarSin(qdh[2]) + ((dw[14] + w[12] *
    w[13]) * muDoubleScalarSin(qdh[4]) + (dw[12] - w[13] * w[14]) *
    muDoubleScalarCos(qdh[4])) * muDoubleScalarCos(qdh[2])) * muDoubleScalarCos
    (qdh[1]);
  Phi[78] = ((((b_mpower(w[13]) - b_mpower(w[14])) * muDoubleScalarCos(qdh[4]) -
               (dw[13] + w[12] * w[14]) * muDoubleScalarSin(qdh[4])) *
              muDoubleScalarCos(qdh[3]) + (-dw[14] + w[12] * w[13]) *
              muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2]) -
             ((b_mpower(w[13]) - b_mpower(w[14])) * muDoubleScalarSin(qdh[4]) +
              muDoubleScalarCos(qdh[4]) * (dw[13] + w[12] * w[14])) *
             muDoubleScalarSin(qdh[2])) * muDoubleScalarSin(qdh[1]) +
    ((((b_mpower(w[13]) - b_mpower(w[14])) * muDoubleScalarCos(qdh[4]) - (dw[13]
        + w[12] * w[14]) * muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3])
      + (-dw[14] + w[12] * w[13]) * muDoubleScalarSin(qdh[3])) *
     muDoubleScalarSin(qdh[2]) + ((b_mpower(w[13]) - b_mpower(w[14])) *
      muDoubleScalarSin(qdh[4]) + muDoubleScalarCos(qdh[4]) * (dw[13] + w[12] *
       w[14])) * muDoubleScalarCos(qdh[2])) * muDoubleScalarCos(qdh[1]);
  Phi[84] = 0.0;
  Phi[90] = (((((ddp[14] * muDoubleScalarSin(qdh[5]) * muDoubleScalarCos(qdh[4])
                 - (-muDoubleScalarSin(qdh[5]) * ddp[12] + muDoubleScalarCos
                    (qdh[5]) * ddp[13]) * muDoubleScalarSin(qdh[4])) + 0.64707 *
                (-muDoubleScalarSin(qdh[5]) * (-b_mpower(w[16]) - b_mpower(w[17]))
                 - muDoubleScalarCos(qdh[5]) * (dw[17] + w[16] * w[15]))) *
               muDoubleScalarCos(qdh[3]) + (ddp[14] * muDoubleScalarCos(qdh[5])
    - 0.64707 * (muDoubleScalarCos(qdh[4]) * (muDoubleScalarCos(qdh[5]) *
    (-b_mpower(w[16]) - b_mpower(w[17])) - (dw[17] + w[16] * w[15]) *
    muDoubleScalarSin(qdh[5])) - muDoubleScalarSin(qdh[4]) * (-dw[16] + w[17] *
    w[15]))) * muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2]) - ((ddp[14]
    * muDoubleScalarSin(qdh[5]) * muDoubleScalarSin(qdh[4]) +
    (-muDoubleScalarSin(qdh[5]) * ddp[12] + muDoubleScalarCos(qdh[5]) * ddp[13])
    * muDoubleScalarCos(qdh[4])) + 0.13 * (muDoubleScalarSin(qdh[3]) *
    (muDoubleScalarCos(qdh[4]) * (muDoubleScalarCos(qdh[5]) * (-b_mpower(w[16])
    - b_mpower(w[17])) - (dw[17] + w[16] * w[15]) * muDoubleScalarSin(qdh[5])) -
     muDoubleScalarSin(qdh[4]) * (-dw[16] + w[17] * w[15])) - muDoubleScalarCos
    (qdh[3]) * (-muDoubleScalarSin(qdh[5]) * (-b_mpower(w[16]) - b_mpower(w[17]))
                - muDoubleScalarCos(qdh[5]) * (dw[17] + w[16] * w[15])))) *
              muDoubleScalarSin(qdh[2])) * muDoubleScalarSin(qdh[1]) + (((((ddp
    [14] * muDoubleScalarSin(qdh[5]) * muDoubleScalarCos(qdh[4]) -
    (-muDoubleScalarSin(qdh[5]) * ddp[12] + muDoubleScalarCos(qdh[5]) * ddp[13])
    * muDoubleScalarSin(qdh[4])) + 0.64707 * (-muDoubleScalarSin(qdh[5]) *
    (-b_mpower(w[16]) - b_mpower(w[17])) - muDoubleScalarCos(qdh[5]) * (dw[17] +
    w[16] * w[15]))) * muDoubleScalarCos(qdh[3]) + (ddp[14] * muDoubleScalarCos
    (qdh[5]) - 0.64707 * (muDoubleScalarCos(qdh[4]) * (muDoubleScalarCos(qdh[5])
    * (-b_mpower(w[16]) - b_mpower(w[17])) - (dw[17] + w[16] * w[15]) *
    muDoubleScalarSin(qdh[5])) - muDoubleScalarSin(qdh[4]) * (-dw[16] + w[17] *
    w[15]))) * muDoubleScalarSin(qdh[3])) * muDoubleScalarSin(qdh[2]) + ((ddp[14]
    * muDoubleScalarSin(qdh[5]) * muDoubleScalarSin(qdh[4]) +
    (-muDoubleScalarSin(qdh[5]) * ddp[12] + muDoubleScalarCos(qdh[5]) * ddp[13])
    * muDoubleScalarCos(qdh[4])) + 0.13 * (muDoubleScalarSin(qdh[3]) *
    (muDoubleScalarCos(qdh[4]) * (muDoubleScalarCos(qdh[5]) * (-b_mpower(w[16])
    - b_mpower(w[17])) - (dw[17] + w[16] * w[15]) * muDoubleScalarSin(qdh[5])) -
     muDoubleScalarSin(qdh[4]) * (-dw[16] + w[17] * w[15])) - muDoubleScalarCos
    (qdh[3]) * (-muDoubleScalarSin(qdh[5]) * (-b_mpower(w[16]) - b_mpower(w[17]))
                - muDoubleScalarCos(qdh[5]) * (dw[17] + w[16] * w[15])))) *
    muDoubleScalarCos(qdh[2])) - 0.59 * (-muDoubleScalarSin(qdh[3]) *
    (muDoubleScalarCos(qdh[4]) * (muDoubleScalarCos(qdh[5]) * (-b_mpower(w[16])
    - b_mpower(w[17])) - (dw[17] + w[16] * w[15]) * muDoubleScalarSin(qdh[5])) -
     muDoubleScalarSin(qdh[4]) * (-dw[16] + w[17] * w[15])) + muDoubleScalarCos
    (qdh[3]) * (-muDoubleScalarSin(qdh[5]) * (-b_mpower(w[16]) - b_mpower(w[17]))
                - muDoubleScalarCos(qdh[5]) * (dw[17] + w[16] * w[15])))) *
             muDoubleScalarCos(qdh[1])) - 0.15 * (-muDoubleScalarSin(qdh[3]) *
    (muDoubleScalarCos(qdh[4]) * (muDoubleScalarCos(qdh[5]) * (-b_mpower(w[16])
    - b_mpower(w[17])) - (dw[17] + w[16] * w[15]) * muDoubleScalarSin(qdh[5])) -
     muDoubleScalarSin(qdh[4]) * (-dw[16] + w[17] * w[15])) + muDoubleScalarCos
    (qdh[3]) * (-muDoubleScalarSin(qdh[5]) * (-b_mpower(w[16]) - b_mpower(w[17]))
                - muDoubleScalarCos(qdh[5]) * (dw[17] + w[16] * w[15])));
  Phi[96] = (((((ddp[14] * muDoubleScalarCos(qdh[5]) * muDoubleScalarCos(qdh[4])
                 - (-muDoubleScalarCos(qdh[5]) * ddp[12] - muDoubleScalarSin
                    (qdh[5]) * ddp[13]) * muDoubleScalarSin(qdh[4])) + 0.64707 *
                (-muDoubleScalarSin(qdh[5]) * (-dw[17] + w[16] * w[15]) -
                 muDoubleScalarCos(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15]))))
               * muDoubleScalarCos(qdh[3]) + (-ddp[14] * muDoubleScalarSin(qdh[5])
    - 0.64707 * (muDoubleScalarCos(qdh[4]) * ((-dw[17] + w[16] * w[15]) *
    muDoubleScalarCos(qdh[5]) - muDoubleScalarSin(qdh[5]) * (-b_mpower(w[17]) -
    b_mpower(w[15]))) - muDoubleScalarSin(qdh[4]) * (dw[15] + w[17] * w[16]))) *
               muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2]) - ((ddp[14]
    * muDoubleScalarCos(qdh[5]) * muDoubleScalarSin(qdh[4]) +
    (-muDoubleScalarCos(qdh[5]) * ddp[12] - muDoubleScalarSin(qdh[5]) * ddp[13])
    * muDoubleScalarCos(qdh[4])) + 0.13 * (muDoubleScalarSin(qdh[3]) *
    (muDoubleScalarCos(qdh[4]) * ((-dw[17] + w[16] * w[15]) * muDoubleScalarCos
    (qdh[5]) - muDoubleScalarSin(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15])))
     - muDoubleScalarSin(qdh[4]) * (dw[15] + w[17] * w[16])) - muDoubleScalarCos
    (qdh[3]) * (-muDoubleScalarSin(qdh[5]) * (-dw[17] + w[16] * w[15]) -
                muDoubleScalarCos(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15])))))
              * muDoubleScalarSin(qdh[2])) * muDoubleScalarSin(qdh[1]) +
             (((((ddp[14] * muDoubleScalarCos(qdh[5]) * muDoubleScalarCos(qdh[4])
                  - (-muDoubleScalarCos(qdh[5]) * ddp[12] - muDoubleScalarSin
                     (qdh[5]) * ddp[13]) * muDoubleScalarSin(qdh[4])) + 0.64707 *
                 (-muDoubleScalarSin(qdh[5]) * (-dw[17] + w[16] * w[15]) -
                  muDoubleScalarCos(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15]))))
                * muDoubleScalarCos(qdh[3]) + (-ddp[14] * muDoubleScalarSin(qdh
    [5]) - 0.64707 * (muDoubleScalarCos(qdh[4]) * ((-dw[17] + w[16] * w[15]) *
    muDoubleScalarCos(qdh[5]) - muDoubleScalarSin(qdh[5]) * (-b_mpower(w[17]) -
    b_mpower(w[15]))) - muDoubleScalarSin(qdh[4]) * (dw[15] + w[17] * w[16]))) *
                muDoubleScalarSin(qdh[3])) * muDoubleScalarSin(qdh[2]) + ((ddp
    [14] * muDoubleScalarCos(qdh[5]) * muDoubleScalarSin(qdh[4]) +
    (-muDoubleScalarCos(qdh[5]) * ddp[12] - muDoubleScalarSin(qdh[5]) * ddp[13])
    * muDoubleScalarCos(qdh[4])) + 0.13 * (muDoubleScalarSin(qdh[3]) *
    (muDoubleScalarCos(qdh[4]) * ((-dw[17] + w[16] * w[15]) * muDoubleScalarCos
    (qdh[5]) - muDoubleScalarSin(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15])))
     - muDoubleScalarSin(qdh[4]) * (dw[15] + w[17] * w[16])) - muDoubleScalarCos
    (qdh[3]) * (-muDoubleScalarSin(qdh[5]) * (-dw[17] + w[16] * w[15]) -
                muDoubleScalarCos(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15])))))
               * muDoubleScalarCos(qdh[2])) - 0.59 * (-muDoubleScalarSin(qdh[3])
    * (muDoubleScalarCos(qdh[4]) * ((-dw[17] + w[16] * w[15]) *
    muDoubleScalarCos(qdh[5]) - muDoubleScalarSin(qdh[5]) * (-b_mpower(w[17]) -
    b_mpower(w[15]))) - muDoubleScalarSin(qdh[4]) * (dw[15] + w[17] * w[16])) +
    muDoubleScalarCos(qdh[3]) * (-muDoubleScalarSin(qdh[5]) * (-dw[17] + w[16] *
    w[15]) - muDoubleScalarCos(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15])))))
             * muDoubleScalarCos(qdh[1])) - 0.15 * (-muDoubleScalarSin(qdh[3]) *
    (muDoubleScalarCos(qdh[4]) * ((-dw[17] + w[16] * w[15]) * muDoubleScalarCos
    (qdh[5]) - muDoubleScalarSin(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15])))
     - muDoubleScalarSin(qdh[4]) * (dw[15] + w[17] * w[16])) + muDoubleScalarCos
    (qdh[3]) * (-muDoubleScalarSin(qdh[5]) * (-dw[17] + w[16] * w[15]) -
                muDoubleScalarCos(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15]))));
  Phi[102] = (((((dw[16] - w[17] * w[15]) * muDoubleScalarCos(qdh[5]) - (dw[15]
    + w[17] * w[16]) * muDoubleScalarSin(qdh[5])) * muDoubleScalarCos(qdh[4]) -
                (b_mpower(w[15]) - b_mpower(w[16])) * muDoubleScalarSin(qdh[4]))
               * muDoubleScalarCos(qdh[3]) + (-(dw[16] - w[17] * w[15]) *
    muDoubleScalarSin(qdh[5]) - (dw[15] + w[17] * w[16]) * muDoubleScalarCos
    (qdh[5])) * muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2]) - (((dw
    [16] - w[17] * w[15]) * muDoubleScalarCos(qdh[5]) - (dw[15] + w[17] * w[16])
    * muDoubleScalarSin(qdh[5])) * muDoubleScalarSin(qdh[4]) + (b_mpower(w[15])
    - b_mpower(w[16])) * muDoubleScalarCos(qdh[4])) * muDoubleScalarSin(qdh[2]))
    * muDoubleScalarSin(qdh[1]) + (((((dw[16] - w[17] * w[15]) *
    muDoubleScalarCos(qdh[5]) - (dw[15] + w[17] * w[16]) * muDoubleScalarSin
    (qdh[5])) * muDoubleScalarCos(qdh[4]) - (b_mpower(w[15]) - b_mpower(w[16])) *
    muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) + (-(dw[16] - w[17] *
    w[15]) * muDoubleScalarSin(qdh[5]) - (dw[15] + w[17] * w[16]) *
    muDoubleScalarCos(qdh[5])) * muDoubleScalarSin(qdh[3])) * muDoubleScalarSin
    (qdh[2]) + (((dw[16] - w[17] * w[15]) * muDoubleScalarCos(qdh[5]) - (dw[15]
    + w[17] * w[16]) * muDoubleScalarSin(qdh[5])) * muDoubleScalarSin(qdh[4]) +
                (b_mpower(w[15]) - b_mpower(w[16])) * muDoubleScalarCos(qdh[4]))
    * muDoubleScalarCos(qdh[2])) * muDoubleScalarCos(qdh[1]);
  Phi[108] = ((((muDoubleScalarCos(qdh[5]) * (dw[17] + w[16] * w[15]) -
                 (b_mpower(w[17]) - b_mpower(w[15])) * muDoubleScalarSin(qdh[5]))
                * muDoubleScalarCos(qdh[4]) - (dw[15] - w[17] * w[16]) *
                muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) + (-(dw
    [17] + w[16] * w[15]) * muDoubleScalarSin(qdh[5]) - (b_mpower(w[17]) -
    b_mpower(w[15])) * muDoubleScalarCos(qdh[5])) * muDoubleScalarSin(qdh[3])) *
              muDoubleScalarCos(qdh[2]) - ((muDoubleScalarCos(qdh[5]) * (dw[17]
    + w[16] * w[15]) - (b_mpower(w[17]) - b_mpower(w[15])) * muDoubleScalarSin
    (qdh[5])) * muDoubleScalarSin(qdh[4]) + (dw[15] - w[17] * w[16]) *
    muDoubleScalarCos(qdh[4])) * muDoubleScalarSin(qdh[2])) * muDoubleScalarSin
    (qdh[1]) + ((((muDoubleScalarCos(qdh[5]) * (dw[17] + w[16] * w[15]) -
                   (b_mpower(w[17]) - b_mpower(w[15])) * muDoubleScalarSin(qdh[5]))
                  * muDoubleScalarCos(qdh[4]) - (dw[15] - w[17] * w[16]) *
                  muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) +
                 (-(dw[17] + w[16] * w[15]) * muDoubleScalarSin(qdh[5]) -
                  (b_mpower(w[17]) - b_mpower(w[15])) * muDoubleScalarCos(qdh[5]))
                 * muDoubleScalarSin(qdh[3])) * muDoubleScalarSin(qdh[2]) +
                ((muDoubleScalarCos(qdh[5]) * (dw[17] + w[16] * w[15]) -
                  (b_mpower(w[17]) - b_mpower(w[15])) * muDoubleScalarSin(qdh[5]))
                 * muDoubleScalarSin(qdh[4]) + (dw[15] - w[17] * w[16]) *
                 muDoubleScalarCos(qdh[4])) * muDoubleScalarCos(qdh[2])) *
    muDoubleScalarCos(qdh[1]);
  Phi[114] = (((((b_mpower(w[16]) - b_mpower(w[17])) * muDoubleScalarCos(qdh[5])
                 - (dw[17] - w[16] * w[15]) * muDoubleScalarSin(qdh[5])) *
                muDoubleScalarCos(qdh[4]) - (dw[16] + w[17] * w[15]) *
                muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) +
               (-(b_mpower(w[16]) - b_mpower(w[17])) * muDoubleScalarSin(qdh[5])
                - (dw[17] - w[16] * w[15]) * muDoubleScalarCos(qdh[5])) *
               muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2]) -
              (((b_mpower(w[16]) - b_mpower(w[17])) * muDoubleScalarCos(qdh[5])
                - (dw[17] - w[16] * w[15]) * muDoubleScalarSin(qdh[5])) *
               muDoubleScalarSin(qdh[4]) + (dw[16] + w[17] * w[15]) *
               muDoubleScalarCos(qdh[4])) * muDoubleScalarSin(qdh[2])) *
    muDoubleScalarSin(qdh[1]) + (((((b_mpower(w[16]) - b_mpower(w[17])) *
    muDoubleScalarCos(qdh[5]) - (dw[17] - w[16] * w[15]) * muDoubleScalarSin
    (qdh[5])) * muDoubleScalarCos(qdh[4]) - (dw[16] + w[17] * w[15]) *
    muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) + (-(b_mpower(w[16])
    - b_mpower(w[17])) * muDoubleScalarSin(qdh[5]) - (dw[17] - w[16] * w[15]) *
    muDoubleScalarCos(qdh[5])) * muDoubleScalarSin(qdh[3])) * muDoubleScalarSin
    (qdh[2]) + (((b_mpower(w[16]) - b_mpower(w[17])) * muDoubleScalarCos(qdh[5])
                 - (dw[17] - w[16] * w[15]) * muDoubleScalarSin(qdh[5])) *
                muDoubleScalarSin(qdh[4]) + (dw[16] + w[17] * w[15]) *
                muDoubleScalarCos(qdh[4])) * muDoubleScalarCos(qdh[2])) *
    muDoubleScalarCos(qdh[1]);
  Phi[120] = ((((muDoubleScalarCos(qdh[5]) * w[17] * w[16] + muDoubleScalarSin
                 (qdh[5]) * w[17] * w[15]) * muDoubleScalarCos(qdh[4]) - dw[17] *
                muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) + (-w[17]
    * w[16] * muDoubleScalarSin(qdh[5]) + w[17] * w[15] * muDoubleScalarCos(qdh
    [5])) * muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2]) -
              ((muDoubleScalarCos(qdh[5]) * w[17] * w[16] + muDoubleScalarSin
                (qdh[5]) * w[17] * w[15]) * muDoubleScalarSin(qdh[4]) + dw[17] *
               muDoubleScalarCos(qdh[4])) * muDoubleScalarSin(qdh[2])) *
    muDoubleScalarSin(qdh[1]) + ((((muDoubleScalarCos(qdh[5]) * w[17] * w[16] +
    muDoubleScalarSin(qdh[5]) * w[17] * w[15]) * muDoubleScalarCos(qdh[4]) - dw
    [17] * muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) + (-w[17] * w
    [16] * muDoubleScalarSin(qdh[5]) + w[17] * w[15] * muDoubleScalarCos(qdh[5]))
    * muDoubleScalarSin(qdh[3])) * muDoubleScalarSin(qdh[2]) +
    ((muDoubleScalarCos(qdh[5]) * w[17] * w[16] + muDoubleScalarSin(qdh[5]) * w
      [17] * w[15]) * muDoubleScalarSin(qdh[4]) + dw[17] * muDoubleScalarCos
     (qdh[4])) * muDoubleScalarCos(qdh[2])) * muDoubleScalarCos(qdh[1]);
  Phi[126] = 0.0;
  Phi[132] = dw[1];
  Phi[138] = -ddp[2] * muDoubleScalarCos(qdh[1]) - 0.15 * (-dw[4] + w[3] * w[5]);
  Phi[144] = dw[3] * muDoubleScalarSin(qdh[1]) + w[3] * w[5] * muDoubleScalarCos
    (qdh[1]);
  Phi[150] = (dw[5] + w[4] * w[3]) * muDoubleScalarSin(qdh[1]) + (b_mpower(w[5])
    - b_mpower(w[3])) * muDoubleScalarCos(qdh[1]);
  Phi[156] = w[5] * (w[4] * muDoubleScalarSin(qdh[1]) - w[3] * muDoubleScalarCos
                     (qdh[1]));
  Phi[162] = (((-ddp[5] * muDoubleScalarCos(qdh[2] + qdh[1]) + muDoubleScalarCos
                (qdh[1]) * 0.59 * dw[8]) + muDoubleScalarCos(qdh[1]) * 0.59 * w
               [6] * w[7]) + 0.15 * dw[8]) + 0.15 * w[6] * w[7];
  Phi[168] = (((ddp[5] * muDoubleScalarSin(qdh[2] + qdh[1]) - muDoubleScalarCos
                (qdh[1]) * 0.59 * dw[6]) + muDoubleScalarCos(qdh[1]) * 0.59 * w
               [8] * w[7]) - 0.15 * dw[6]) + 0.15 * w[8] * w[7];
  Phi[174] = dw[6] * muDoubleScalarSin(qdh[2] + qdh[1]) - w[6] * w[7] *
    muDoubleScalarCos(qdh[2] + qdh[1]);
  Phi[180] = ((dw[8] * muDoubleScalarSin(qdh[2] + qdh[1]) + w[7] * w[6] *
               muDoubleScalarSin(qdh[2] + qdh[1])) + dw[6] * muDoubleScalarCos
              (qdh[2] + qdh[1])) - w[7] * w[8] * muDoubleScalarCos(qdh[2] + qdh
    [1]);
  Phi[186] = -w[7] * w[8] * muDoubleScalarSin(qdh[2] + qdh[1]) + w[6] * w[7] *
    muDoubleScalarCos(qdh[2] + qdh[1]);
  Phi[192] = ((-ddp[8] * muDoubleScalarCos(qdh[3]) * muDoubleScalarCos(qdh[2]) -
               ((muDoubleScalarCos(qdh[3]) * ddp[6] + muDoubleScalarSin(qdh[3]) *
                 ddp[7]) + 0.13 * (muDoubleScalarSin(qdh[3]) * (dw[10] + w[9] *
    w[11]) - muDoubleScalarCos(qdh[3]) * (-b_mpower(w[9]) - b_mpower(w[10])))) *
               muDoubleScalarSin(qdh[2])) * muDoubleScalarSin(qdh[1]) + ((-ddp[8]
    * muDoubleScalarCos(qdh[3]) * muDoubleScalarSin(qdh[2]) +
    ((muDoubleScalarCos(qdh[3]) * ddp[6] + muDoubleScalarSin(qdh[3]) * ddp[7]) +
     0.13 * (muDoubleScalarSin(qdh[3]) * (dw[10] + w[9] * w[11]) -
             muDoubleScalarCos(qdh[3]) * (-b_mpower(w[9]) - b_mpower(w[10])))) *
    muDoubleScalarCos(qdh[2])) - 0.59 * (-muDoubleScalarSin(qdh[3]) * (dw[10] +
    w[9] * w[11]) + muDoubleScalarCos(qdh[3]) * (-b_mpower(w[9]) - b_mpower(w[10]))))
              * muDoubleScalarCos(qdh[1])) - 0.15 * (-muDoubleScalarSin(qdh[3]) *
    (dw[10] + w[9] * w[11]) + muDoubleScalarCos(qdh[3]) * (-b_mpower(w[9]) -
    b_mpower(w[10])));
  Phi[198] = (((0.5 * dw[9] * muDoubleScalarSin((qdh[1] - qdh[3]) + qdh[2]) +
                0.5 * dw[9] * muDoubleScalarSin((qdh[1] + qdh[3]) + qdh[2])) +
               0.5 * w[10] * w[9] * muDoubleScalarCos((qdh[1] + qdh[3]) + qdh[2]))
              - 0.5 * w[10] * w[9] * muDoubleScalarCos((qdh[1] - qdh[3]) + qdh[2]))
    + w[11] * w[9] * muDoubleScalarCos(qdh[2] + qdh[1]);
  Phi[204] = (((-0.5 * w[11] * w[10] * muDoubleScalarSin((qdh[1] - qdh[3]) +
    qdh[2]) - 0.5 * w[11] * w[10] * muDoubleScalarSin((qdh[1] + qdh[3]) + qdh[2]))
               - 0.5 * w[10] * w[9] * muDoubleScalarCos((qdh[1] + qdh[3]) + qdh
    [2])) + 0.5 * w[10] * w[9] * muDoubleScalarCos((qdh[1] - qdh[3]) + qdh[2]))
    + dw[10] * muDoubleScalarCos(qdh[2] + qdh[1]);
  Phi[210] = (((b_mpower(w[10]) - b_mpower(w[11])) * muDoubleScalarCos(qdh[3]) +
               muDoubleScalarSin(qdh[3]) * (dw[10] + w[9] * w[11])) *
              muDoubleScalarCos(qdh[2]) - (dw[11] - w[10] * w[9]) *
              muDoubleScalarSin(qdh[2])) * muDoubleScalarSin(qdh[1]) +
    (((b_mpower(w[10]) - b_mpower(w[11])) * muDoubleScalarCos(qdh[3]) +
      muDoubleScalarSin(qdh[3]) * (dw[10] + w[9] * w[11])) * muDoubleScalarSin
     (qdh[2]) + (dw[11] - w[10] * w[9]) * muDoubleScalarCos(qdh[2])) *
    muDoubleScalarCos(qdh[1]);
  Phi[216] = ((((ddp[11] * muDoubleScalarCos(qdh[4]) + 0.64707 * (dw[12] - w[13]
    * w[14])) * muDoubleScalarCos(qdh[3]) + ((-muDoubleScalarCos(qdh[4]) * ddp[9]
    - muDoubleScalarSin(qdh[4]) * ddp[10]) - 0.64707 * (muDoubleScalarCos(qdh[4])
    * (dw[13] + w[12] * w[14]) - muDoubleScalarSin(qdh[4]) * (-b_mpower(w[12]) -
    b_mpower(w[13])))) * muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2])
               - (ddp[11] * muDoubleScalarSin(qdh[4]) + 0.13 *
                  (muDoubleScalarSin(qdh[3]) * (muDoubleScalarCos(qdh[4]) * (dw
    [13] + w[12] * w[14]) - muDoubleScalarSin(qdh[4]) * (-b_mpower(w[12]) -
    b_mpower(w[13]))) - muDoubleScalarCos(qdh[3]) * (dw[12] - w[13] * w[14]))) *
               muDoubleScalarSin(qdh[2])) * muDoubleScalarSin(qdh[1]) + ((((ddp
    [11] * muDoubleScalarCos(qdh[4]) + 0.64707 * (dw[12] - w[13] * w[14])) *
    muDoubleScalarCos(qdh[3]) + ((-muDoubleScalarCos(qdh[4]) * ddp[9] -
    muDoubleScalarSin(qdh[4]) * ddp[10]) - 0.64707 * (muDoubleScalarCos(qdh[4]) *
    (dw[13] + w[12] * w[14]) - muDoubleScalarSin(qdh[4]) * (-b_mpower(w[12]) -
    b_mpower(w[13])))) * muDoubleScalarSin(qdh[3])) * muDoubleScalarSin(qdh[2])
    + (ddp[11] * muDoubleScalarSin(qdh[4]) + 0.13 * (muDoubleScalarSin(qdh[3]) *
    (muDoubleScalarCos(qdh[4]) * (dw[13] + w[12] * w[14]) - muDoubleScalarSin
     (qdh[4]) * (-b_mpower(w[12]) - b_mpower(w[13]))) - muDoubleScalarCos(qdh[3])
    * (dw[12] - w[13] * w[14]))) * muDoubleScalarCos(qdh[2])) - 0.59 *
    (-muDoubleScalarSin(qdh[3]) * (muDoubleScalarCos(qdh[4]) * (dw[13] + w[12] *
    w[14]) - muDoubleScalarSin(qdh[4]) * (-b_mpower(w[12]) - b_mpower(w[13]))) +
     muDoubleScalarCos(qdh[3]) * (dw[12] - w[13] * w[14]))) * muDoubleScalarCos
              (qdh[1])) - 0.15 * (-muDoubleScalarSin(qdh[3]) *
    (muDoubleScalarCos(qdh[4]) * (dw[13] + w[12] * w[14]) - muDoubleScalarSin
     (qdh[4]) * (-b_mpower(w[12]) - b_mpower(w[13]))) + muDoubleScalarCos(qdh[3])
    * (dw[12] - w[13] * w[14]));
  Phi[222] = (((dw[12] * muDoubleScalarCos(qdh[4]) + w[13] * w[12] *
                muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) - w[14] *
               w[12] * muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2]) -
              (dw[12] * muDoubleScalarSin(qdh[4]) - w[13] * w[12] *
               muDoubleScalarCos(qdh[4])) * muDoubleScalarSin(qdh[2])) *
    muDoubleScalarSin(qdh[1]) + (((dw[12] * muDoubleScalarCos(qdh[4]) + w[13] *
    w[12] * muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) - w[14] * w
    [12] * muDoubleScalarSin(qdh[3])) * muDoubleScalarSin(qdh[2]) + (dw[12] *
    muDoubleScalarSin(qdh[4]) - w[13] * w[12] * muDoubleScalarCos(qdh[4])) *
    muDoubleScalarCos(qdh[2])) * muDoubleScalarCos(qdh[1]);
  Phi[228] = (((-w[13] * w[14] * muDoubleScalarCos(qdh[4]) - w[13] * w[12] *
                muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) - dw[13] *
               muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2]) - (-w[13] *
    w[14] * muDoubleScalarSin(qdh[4]) + w[13] * w[12] * muDoubleScalarCos(qdh[4]))
              * muDoubleScalarSin(qdh[2])) * muDoubleScalarSin(qdh[1]) + (((-w
    [13] * w[14] * muDoubleScalarCos(qdh[4]) - w[13] * w[12] * muDoubleScalarSin
    (qdh[4])) * muDoubleScalarCos(qdh[3]) - dw[13] * muDoubleScalarSin(qdh[3])) *
    muDoubleScalarSin(qdh[2]) + (-w[13] * w[14] * muDoubleScalarSin(qdh[4]) + w
    [13] * w[12] * muDoubleScalarCos(qdh[4])) * muDoubleScalarCos(qdh[2])) *
    muDoubleScalarCos(qdh[1]);
  Phi[234] = ((((muDoubleScalarCos(qdh[5]) * dw[15] - muDoubleScalarSin(qdh[5]) *
                 w[17] * w[15]) * muDoubleScalarCos(qdh[4]) + w[16] * w[15] *
                muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) + (-dw[15]
    * muDoubleScalarSin(qdh[5]) - w[17] * w[15] * muDoubleScalarCos(qdh[5])) *
               muDoubleScalarSin(qdh[3])) * muDoubleScalarCos(qdh[2]) -
              ((muDoubleScalarCos(qdh[5]) * dw[15] - muDoubleScalarSin(qdh[5]) *
                w[17] * w[15]) * muDoubleScalarSin(qdh[4]) - w[16] * w[15] *
               muDoubleScalarCos(qdh[4])) * muDoubleScalarSin(qdh[2])) *
    muDoubleScalarSin(qdh[1]) + ((((muDoubleScalarCos(qdh[5]) * dw[15] -
    muDoubleScalarSin(qdh[5]) * w[17] * w[15]) * muDoubleScalarCos(qdh[4]) + w
    [16] * w[15] * muDoubleScalarSin(qdh[4])) * muDoubleScalarCos(qdh[3]) +
    (-dw[15] * muDoubleScalarSin(qdh[5]) - w[17] * w[15] * muDoubleScalarCos
     (qdh[5])) * muDoubleScalarSin(qdh[3])) * muDoubleScalarSin(qdh[2]) +
    ((muDoubleScalarCos(qdh[5]) * dw[15] - muDoubleScalarSin(qdh[5]) * w[17] *
      w[15]) * muDoubleScalarSin(qdh[4]) - w[16] * w[15] * muDoubleScalarCos
     (qdh[4])) * muDoubleScalarCos(qdh[2])) * muDoubleScalarCos(qdh[1]);

  /*  Coppia: 2 */
  Phi[1] = -muDoubleScalarCos(qdh[1]) * ddp[0] - muDoubleScalarSin(qdh[1]) *
    ddp[1];
  Phi[7] = b_mpower(w[3]) - b_mpower(w[4]);
  Phi[13] = dw[4] + w[3] * w[5];
  Phi[19] = -dw[6] - w[7] * w[8];
  Phi[25] = -dw[8] + w[7] * w[6];
  Phi[31] = 0.0;
  Phi[37] = (ddp[8] * muDoubleScalarCos(qdh[3]) + 0.13 * (dw[11] + w[9] * w[10]))
    + 0.59 * (muDoubleScalarSin(qdh[2]) * (muDoubleScalarCos(qdh[3]) *
    (-b_mpower(w[10]) - b_mpower(w[11])) + muDoubleScalarSin(qdh[3]) * (-dw[10]
    + w[9] * w[11])) + muDoubleScalarCos(qdh[2]) * (dw[11] + w[9] * w[10]));
  Phi[43] = -muDoubleScalarSin(qdh[3]) * (dw[10] - w[9] * w[11]) + (b_mpower(w[9])
    - b_mpower(w[10])) * muDoubleScalarCos(qdh[3]);
  Phi[49] = -(dw[11] + w[10] * w[9]) * muDoubleScalarSin(qdh[3]) + (dw[9] - w[10]
    * w[11]) * muDoubleScalarCos(qdh[3]);
  Phi[55] = 0.0;
  Phi[61] = ((-(ddp[11] * muDoubleScalarSin(qdh[4]) + 0.64707 * (-dw[14] - w[12]
    * w[13])) * muDoubleScalarSin(qdh[3]) + ((-muDoubleScalarSin(qdh[4]) * ddp[9]
    + muDoubleScalarCos(qdh[4]) * ddp[10]) - 0.64707 * (muDoubleScalarCos(qdh[4])
    * (-b_mpower(w[13]) - b_mpower(w[14])) - muDoubleScalarSin(qdh[4]) * (-dw[13]
    + w[12] * w[14]))) * muDoubleScalarCos(qdh[3])) + 0.13 * (muDoubleScalarSin
              (qdh[4]) * (-b_mpower(w[13]) - b_mpower(w[14])) +
              muDoubleScalarCos(qdh[4]) * (-dw[13] + w[12] * w[14]))) + 0.59 *
    (muDoubleScalarSin(qdh[2]) * (muDoubleScalarCos(qdh[3]) * (muDoubleScalarCos
       (qdh[4]) * (-b_mpower(w[13]) - b_mpower(w[14])) - muDoubleScalarSin(qdh[4])
       * (-dw[13] + w[12] * w[14])) + muDoubleScalarSin(qdh[3]) * (-dw[14] - w
       [12] * w[13])) + muDoubleScalarCos(qdh[2]) * (muDoubleScalarSin(qdh[4]) *
      (-b_mpower(w[13]) - b_mpower(w[14])) + muDoubleScalarCos(qdh[4]) * (-dw[13]
       + w[12] * w[14])));
  Phi[67] = -((dw[13] - w[14] * w[12]) * muDoubleScalarCos(qdh[4]) - (b_mpower
    (w[12]) - b_mpower(w[13])) * muDoubleScalarSin(qdh[4])) * muDoubleScalarSin
    (qdh[3]) + (-dw[12] - w[13] * w[14]) * muDoubleScalarCos(qdh[3]);
  Phi[73] = -((dw[14] + w[13] * w[12]) * muDoubleScalarCos(qdh[4]) - (dw[12] -
    w[13] * w[14]) * muDoubleScalarSin(qdh[4])) * muDoubleScalarSin(qdh[3]) +
    (-b_mpower(w[14]) + b_mpower(w[12])) * muDoubleScalarCos(qdh[3]);
  Phi[79] = -((b_mpower(w[13]) - b_mpower(w[14])) * muDoubleScalarCos(qdh[4]) -
              (dw[13] + w[14] * w[12]) * muDoubleScalarSin(qdh[4])) *
    muDoubleScalarSin(qdh[3]) + (-dw[14] + w[13] * w[12]) * muDoubleScalarCos
    (qdh[3]);
  Phi[85] = 0.0;
  Phi[91] = ((-((ddp[14] * muDoubleScalarSin(qdh[5]) * muDoubleScalarCos(qdh[4])
                 - (-muDoubleScalarSin(qdh[5]) * ddp[12] + muDoubleScalarCos
                    (qdh[5]) * ddp[13]) * muDoubleScalarSin(qdh[4])) + 0.64707 *
                (-muDoubleScalarSin(qdh[5]) * (-b_mpower(w[16]) - b_mpower(w[17]))
                 - muDoubleScalarCos(qdh[5]) * (dw[17] + w[15] * w[16]))) *
              muDoubleScalarSin(qdh[3]) + (ddp[14] * muDoubleScalarCos(qdh[5]) -
    0.64707 * (muDoubleScalarCos(qdh[4]) * (muDoubleScalarCos(qdh[5]) *
    (-b_mpower(w[16]) - b_mpower(w[17])) - muDoubleScalarSin(qdh[5]) * (dw[17] +
    w[15] * w[16])) - muDoubleScalarSin(qdh[4]) * (-dw[16] + w[15] * w[17]))) *
              muDoubleScalarCos(qdh[3])) + 0.13 * (muDoubleScalarSin(qdh[4]) *
              (muDoubleScalarCos(qdh[5]) * (-b_mpower(w[16]) - b_mpower(w[17]))
               - muDoubleScalarSin(qdh[5]) * (dw[17] + w[15] * w[16])) +
              muDoubleScalarCos(qdh[4]) * (-dw[16] + w[15] * w[17]))) + 0.59 *
    (muDoubleScalarSin(qdh[2]) * (muDoubleScalarCos(qdh[3]) * (muDoubleScalarCos
       (qdh[4]) * (muDoubleScalarCos(qdh[5]) * (-b_mpower(w[16]) - b_mpower(w[17]))
                   - muDoubleScalarSin(qdh[5]) * (dw[17] + w[15] * w[16])) -
       muDoubleScalarSin(qdh[4]) * (-dw[16] + w[15] * w[17])) +
      muDoubleScalarSin(qdh[3]) * (-muDoubleScalarSin(qdh[5]) * (-b_mpower(w[16])
        - b_mpower(w[17])) - muDoubleScalarCos(qdh[5]) * (dw[17] + w[15] * w[16])))
     + muDoubleScalarCos(qdh[2]) * (muDoubleScalarSin(qdh[4]) *
      (muDoubleScalarCos(qdh[5]) * (-b_mpower(w[16]) - b_mpower(w[17])) -
       muDoubleScalarSin(qdh[5]) * (dw[17] + w[15] * w[16])) + muDoubleScalarCos
      (qdh[4]) * (-dw[16] + w[15] * w[17])));
  Phi[97] = ((-((ddp[14] * muDoubleScalarCos(qdh[5]) * muDoubleScalarCos(qdh[4])
                 - (-muDoubleScalarCos(qdh[5]) * ddp[12] - muDoubleScalarSin
                    (qdh[5]) * ddp[13]) * muDoubleScalarSin(qdh[4])) + 0.64707 *
                (-muDoubleScalarSin(qdh[5]) * (-dw[17] + w[15] * w[16]) -
                 muDoubleScalarCos(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15]))))
              * muDoubleScalarSin(qdh[3]) + (-ddp[14] * muDoubleScalarSin(qdh[5])
    - 0.64707 * (muDoubleScalarCos(qdh[4]) * (muDoubleScalarCos(qdh[5]) * (-dw
    [17] + w[15] * w[16]) - muDoubleScalarSin(qdh[5]) * (-b_mpower(w[17]) -
    b_mpower(w[15]))) - muDoubleScalarSin(qdh[4]) * (dw[15] + w[16] * w[17]))) *
              muDoubleScalarCos(qdh[3])) + 0.13 * (muDoubleScalarSin(qdh[4]) *
              (muDoubleScalarCos(qdh[5]) * (-dw[17] + w[15] * w[16]) -
               muDoubleScalarSin(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15])))
              + muDoubleScalarCos(qdh[4]) * (dw[15] + w[16] * w[17]))) + 0.59 *
    (muDoubleScalarSin(qdh[2]) * (muDoubleScalarCos(qdh[3]) * (muDoubleScalarCos
       (qdh[4]) * (muDoubleScalarCos(qdh[5]) * (-dw[17] + w[15] * w[16]) -
                   muDoubleScalarSin(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15])))
       - muDoubleScalarSin(qdh[4]) * (dw[15] + w[16] * w[17])) +
      muDoubleScalarSin(qdh[3]) * (-muDoubleScalarSin(qdh[5]) * (-dw[17] + w[15]
        * w[16]) - muDoubleScalarCos(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15]))))
     + muDoubleScalarCos(qdh[2]) * (muDoubleScalarSin(qdh[4]) *
      (muDoubleScalarCos(qdh[5]) * (-dw[17] + w[15] * w[16]) - muDoubleScalarSin
       (qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15]))) + muDoubleScalarCos(qdh
       [4]) * (dw[15] + w[16] * w[17])));
  Phi[103] = -(((dw[16] - w[17] * w[15]) * muDoubleScalarCos(qdh[5]) - (dw[15] +
    w[16] * w[17]) * muDoubleScalarSin(qdh[5])) * muDoubleScalarCos(qdh[4]) -
               (b_mpower(w[15]) - b_mpower(w[16])) * muDoubleScalarSin(qdh[4])) *
    muDoubleScalarSin(qdh[3]) + (-(dw[16] - w[17] * w[15]) * muDoubleScalarSin
    (qdh[5]) - (dw[15] + w[16] * w[17]) * muDoubleScalarCos(qdh[5])) *
    muDoubleScalarCos(qdh[3]);
  Phi[109] = -(((dw[17] + w[16] * w[15]) * muDoubleScalarCos(qdh[5]) - (b_mpower
    (w[17]) - b_mpower(w[15])) * muDoubleScalarSin(qdh[5])) * muDoubleScalarCos
               (qdh[4]) - (dw[15] - w[16] * w[17]) * muDoubleScalarSin(qdh[4])) *
    muDoubleScalarSin(qdh[3]) + (-(dw[17] + w[16] * w[15]) * muDoubleScalarSin
    (qdh[5]) - (b_mpower(w[17]) - b_mpower(w[15])) * muDoubleScalarCos(qdh[5])) *
    muDoubleScalarCos(qdh[3]);
  Phi[115] = -(((b_mpower(w[16]) - b_mpower(w[17])) * muDoubleScalarCos(qdh[5])
                - (dw[17] - w[16] * w[15]) * muDoubleScalarSin(qdh[5])) *
               muDoubleScalarCos(qdh[4]) - (dw[16] + w[15] * w[17]) *
               muDoubleScalarSin(qdh[4])) * muDoubleScalarSin(qdh[3]) +
    (-(b_mpower(w[16]) - b_mpower(w[17])) * muDoubleScalarSin(qdh[5]) - (dw[17]
      - w[16] * w[15]) * muDoubleScalarCos(qdh[5])) * muDoubleScalarCos(qdh[3]);
  Phi[121] = -((muDoubleScalarCos(qdh[5]) * w[16] * w[17] + w[15] * w[17] *
                muDoubleScalarSin(qdh[5])) * muDoubleScalarCos(qdh[4]) - dw[17] *
               muDoubleScalarSin(qdh[4])) * muDoubleScalarSin(qdh[3]) +
    (-muDoubleScalarSin(qdh[5]) * w[16] * w[17] + w[15] * w[17] *
     muDoubleScalarCos(qdh[5])) * muDoubleScalarCos(qdh[3]);
  Phi[127] = 0.0;
  Phi[133] = 0.0;
  Phi[139] = -muDoubleScalarSin(qdh[1]) * ddp[0] + muDoubleScalarCos(qdh[1]) *
    ddp[1];
  Phi[145] = -w[4] * w[3];
  Phi[151] = dw[3] - w[4] * w[5];
  Phi[157] = dw[5];
  Phi[163] = (-muDoubleScalarSin(qdh[2]) * ddp[3] + muDoubleScalarCos(qdh[2]) *
              ddp[4]) + 0.59 * (muDoubleScalarSin(qdh[2]) * (-b_mpower(w[7]) -
    b_mpower(w[8])) + muDoubleScalarCos(qdh[2]) * (-dw[7] + w[6] * w[8]));
  Phi[169] = (-muDoubleScalarCos(qdh[2]) * ddp[3] - muDoubleScalarSin(qdh[2]) *
              ddp[4]) + 0.59 * (muDoubleScalarSin(qdh[2]) * (dw[7] + w[6] * w[8])
    + muDoubleScalarCos(qdh[2]) * (-b_mpower(w[6]) - b_mpower(w[7])));
  Phi[175] = -w[6] * w[8];
  Phi[181] = -b_mpower(w[8]) + b_mpower(w[6]);
  Phi[187] = -dw[7];
  Phi[193] = (ddp[8] * muDoubleScalarSin(qdh[3]) + 0.13 * (-dw[9] + w[10] * w[11]))
    + 0.59 * (muDoubleScalarSin(qdh[2]) * (muDoubleScalarCos(qdh[3]) * (dw[10] +
    w[9] * w[11]) + muDoubleScalarSin(qdh[3]) * (-b_mpower(w[9]) - b_mpower(w[10])))
              + muDoubleScalarCos(qdh[2]) * (-dw[9] + w[10] * w[11]));
  Phi[199] = -muDoubleScalarSin(qdh[3]) * dw[9] - muDoubleScalarCos(qdh[3]) * w
    [9] * w[10];
  Phi[205] = w[10] * (muDoubleScalarSin(qdh[3]) * w[11] + w[9] *
                      muDoubleScalarCos(qdh[3]));
  Phi[211] = -(b_mpower(w[10]) - b_mpower(w[11])) * muDoubleScalarSin(qdh[3]) +
    (dw[10] + w[9] * w[11]) * muDoubleScalarCos(qdh[3]);
  Phi[217] = ((-(ddp[11] * muDoubleScalarCos(qdh[4]) + 0.64707 * (dw[12] - w[13]
    * w[14])) * muDoubleScalarSin(qdh[3]) + ((-muDoubleScalarCos(qdh[4]) * ddp[9]
    - muDoubleScalarSin(qdh[4]) * ddp[10]) - 0.64707 * (muDoubleScalarCos(qdh[4])
    * (dw[13] + w[14] * w[12]) - muDoubleScalarSin(qdh[4]) * (-b_mpower(w[12]) -
    b_mpower(w[13])))) * muDoubleScalarCos(qdh[3])) + 0.13 * (muDoubleScalarSin
    (qdh[4]) * (dw[13] + w[14] * w[12]) + muDoubleScalarCos(qdh[4]) * (-b_mpower
    (w[12]) - b_mpower(w[13])))) + 0.59 * (muDoubleScalarSin(qdh[2]) *
    (muDoubleScalarCos(qdh[3]) * (muDoubleScalarCos(qdh[4]) * (dw[13] + w[14] *
    w[12]) - muDoubleScalarSin(qdh[4]) * (-b_mpower(w[12]) - b_mpower(w[13]))) +
     muDoubleScalarSin(qdh[3]) * (dw[12] - w[13] * w[14])) + muDoubleScalarCos
    (qdh[2]) * (muDoubleScalarSin(qdh[4]) * (dw[13] + w[14] * w[12]) +
                muDoubleScalarCos(qdh[4]) * (-b_mpower(w[12]) - b_mpower(w[13]))));
  Phi[223] = -(dw[12] * muDoubleScalarCos(qdh[4]) + w[13] * w[12] *
               muDoubleScalarSin(qdh[4])) * muDoubleScalarSin(qdh[3]) - w[14] *
    w[12] * muDoubleScalarCos(qdh[3]);
  Phi[229] = -(-w[13] * w[14] * muDoubleScalarCos(qdh[4]) - w[13] * w[12] *
               muDoubleScalarSin(qdh[4])) * muDoubleScalarSin(qdh[3]) - dw[13] *
    muDoubleScalarCos(qdh[3]);
  Phi[235] = -((dw[15] * muDoubleScalarCos(qdh[5]) - w[17] * w[15] *
                muDoubleScalarSin(qdh[5])) * muDoubleScalarCos(qdh[4]) + w[16] *
               w[15] * muDoubleScalarSin(qdh[4])) * muDoubleScalarSin(qdh[3]) +
    (-dw[15] * muDoubleScalarSin(qdh[5]) - w[17] * w[15] * muDoubleScalarCos
     (qdh[5])) * muDoubleScalarCos(qdh[3]);

  /*  Coppia: 3 */
  Phi[2] = 0.0;
  Phi[8] = 0.0;
  Phi[14] = 0.0;
  Phi[20] = dw[6] + w[8] * w[7];
  Phi[26] = dw[8] - w[6] * w[7];
  Phi[32] = -q[2];
  Phi[38] = -ddp[8] * muDoubleScalarCos(qdh[3]) - 0.13 * (dw[11] + w[10] * w[9]);
  Phi[44] = (dw[10] - w[9] * w[11]) * muDoubleScalarSin(qdh[3]) - (b_mpower(w[9])
    - b_mpower(w[10])) * muDoubleScalarCos(qdh[3]);
  Phi[50] = (dw[11] + w[10] * w[9]) * muDoubleScalarSin(qdh[3]) - (dw[9] - w[10]
    * w[11]) * muDoubleScalarCos(qdh[3]);
  Phi[56] = 0.0;
  Phi[62] = ((ddp[11] * muDoubleScalarSin(qdh[4]) + 0.64707 * (-dw[14] - w[12] *
    w[13])) * muDoubleScalarSin(qdh[3]) - ((-muDoubleScalarSin(qdh[4]) * ddp[9]
    + muDoubleScalarCos(qdh[4]) * ddp[10]) - 0.64707 * (muDoubleScalarCos(qdh[4])
    * (-b_mpower(w[13]) - b_mpower(w[14])) - muDoubleScalarSin(qdh[4]) * (-dw[13]
    + w[12] * w[14]))) * muDoubleScalarCos(qdh[3])) - 0.13 * (muDoubleScalarSin
    (qdh[4]) * (-b_mpower(w[13]) - b_mpower(w[14])) + muDoubleScalarCos(qdh[4]) *
    (-dw[13] + w[12] * w[14]));
  Phi[68] = ((dw[13] - w[12] * w[14]) * muDoubleScalarCos(qdh[4]) - (b_mpower(w
    [12]) - b_mpower(w[13])) * muDoubleScalarSin(qdh[4])) * muDoubleScalarSin
    (qdh[3]) - (-dw[12] - w[13] * w[14]) * muDoubleScalarCos(qdh[3]);
  Phi[74] = ((dw[14] + w[12] * w[13]) * muDoubleScalarCos(qdh[4]) - (dw[12] - w
              [13] * w[14]) * muDoubleScalarSin(qdh[4])) * muDoubleScalarSin
    (qdh[3]) - (-b_mpower(w[14]) + b_mpower(w[12])) * muDoubleScalarCos(qdh[3]);
  Phi[80] = ((b_mpower(w[13]) - b_mpower(w[14])) * muDoubleScalarCos(qdh[4]) -
             (dw[13] + w[12] * w[14]) * muDoubleScalarSin(qdh[4])) *
    muDoubleScalarSin(qdh[3]) - (-dw[14] + w[12] * w[13]) * muDoubleScalarCos
    (qdh[3]);
  Phi[86] = 0.0;
  Phi[92] = (((ddp[14] * muDoubleScalarSin(qdh[5]) * muDoubleScalarCos(qdh[4]) -
               (-muDoubleScalarSin(qdh[5]) * ddp[12] + muDoubleScalarCos(qdh[5])
                * ddp[13]) * muDoubleScalarSin(qdh[4])) + 0.64707 *
              (-muDoubleScalarSin(qdh[5]) * (-b_mpower(w[16]) - b_mpower(w[17]))
               - muDoubleScalarCos(qdh[5]) * (dw[17] + w[16] * w[15]))) *
             muDoubleScalarSin(qdh[3]) - (ddp[14] * muDoubleScalarCos(qdh[5]) -
              0.64707 * (muDoubleScalarCos(qdh[4]) * (muDoubleScalarCos(qdh[5]) *
    (-b_mpower(w[16]) - b_mpower(w[17])) - (dw[17] + w[16] * w[15]) *
    muDoubleScalarSin(qdh[5])) - muDoubleScalarSin(qdh[4]) * (-dw[16] + w[17] *
    w[15]))) * muDoubleScalarCos(qdh[3])) - 0.13 * (muDoubleScalarSin(qdh[4]) *
    (muDoubleScalarCos(qdh[5]) * (-b_mpower(w[16]) - b_mpower(w[17])) - (dw[17]
    + w[16] * w[15]) * muDoubleScalarSin(qdh[5])) + muDoubleScalarCos(qdh[4]) *
    (-dw[16] + w[17] * w[15]));
  Phi[98] = (((ddp[14] * muDoubleScalarCos(qdh[5]) * muDoubleScalarCos(qdh[4]) -
               (-muDoubleScalarCos(qdh[5]) * ddp[12] - muDoubleScalarSin(qdh[5])
                * ddp[13]) * muDoubleScalarSin(qdh[4])) + 0.64707 *
              (-muDoubleScalarSin(qdh[5]) * (-dw[17] + w[16] * w[15]) -
               muDoubleScalarCos(qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15]))))
             * muDoubleScalarSin(qdh[3]) - (-ddp[14] * muDoubleScalarSin(qdh[5])
              - 0.64707 * (muDoubleScalarCos(qdh[4]) * ((-dw[17] + w[16] * w[15])
    * muDoubleScalarCos(qdh[5]) - muDoubleScalarSin(qdh[5]) * (-b_mpower(w[17])
    - b_mpower(w[15]))) - muDoubleScalarSin(qdh[4]) * (dw[15] + w[17] * w[16])))
             * muDoubleScalarCos(qdh[3])) - 0.13 * (muDoubleScalarSin(qdh[4]) *
    ((-dw[17] + w[16] * w[15]) * muDoubleScalarCos(qdh[5]) - muDoubleScalarSin
     (qdh[5]) * (-b_mpower(w[17]) - b_mpower(w[15]))) + muDoubleScalarCos(qdh[4])
    * (dw[15] + w[17] * w[16]));
  Phi[104] = (((dw[16] - w[17] * w[15]) * muDoubleScalarCos(qdh[5]) - (dw[15] +
    w[17] * w[16]) * muDoubleScalarSin(qdh[5])) * muDoubleScalarCos(qdh[4]) -
              (b_mpower(w[15]) - b_mpower(w[16])) * muDoubleScalarSin(qdh[4])) *
    muDoubleScalarSin(qdh[3]) - (-(dw[16] - w[17] * w[15]) * muDoubleScalarSin
    (qdh[5]) - (dw[15] + w[17] * w[16]) * muDoubleScalarCos(qdh[5])) *
    muDoubleScalarCos(qdh[3]);
  Phi[110] = ((muDoubleScalarCos(qdh[5]) * (dw[17] + w[16] * w[15]) - (b_mpower
    (w[17]) - b_mpower(w[15])) * muDoubleScalarSin(qdh[5])) * muDoubleScalarCos
              (qdh[4]) - (dw[15] - w[17] * w[16]) * muDoubleScalarSin(qdh[4])) *
    muDoubleScalarSin(qdh[3]) - (-(dw[17] + w[16] * w[15]) * muDoubleScalarSin
    (qdh[5]) - (b_mpower(w[17]) - b_mpower(w[15])) * muDoubleScalarCos(qdh[5])) *
    muDoubleScalarCos(qdh[3]);
  Phi[116] = (((b_mpower(w[16]) - b_mpower(w[17])) * muDoubleScalarCos(qdh[5]) -
               (dw[17] - w[16] * w[15]) * muDoubleScalarSin(qdh[5])) *
              muDoubleScalarCos(qdh[4]) - (dw[16] + w[17] * w[15]) *
              muDoubleScalarSin(qdh[4])) * muDoubleScalarSin(qdh[3]) -
    (-(b_mpower(w[16]) - b_mpower(w[17])) * muDoubleScalarSin(qdh[5]) - (dw[17]
      - w[16] * w[15]) * muDoubleScalarCos(qdh[5])) * muDoubleScalarCos(qdh[3]);
  Phi[122] = ((muDoubleScalarCos(qdh[5]) * w[17] * w[16] + muDoubleScalarSin
               (qdh[5]) * w[17] * w[15]) * muDoubleScalarCos(qdh[4]) - dw[17] *
              muDoubleScalarSin(qdh[4])) * muDoubleScalarSin(qdh[3]) - (-w[17] *
    w[16] * muDoubleScalarSin(qdh[5]) + w[17] * w[15] * muDoubleScalarCos(qdh[5]))
    * muDoubleScalarCos(qdh[3]);
  Phi[128] = 0.0;
  Phi[134] = 0.0;
  Phi[140] = 0.0;
  Phi[146] = 0.0;
  Phi[152] = 0.0;
  Phi[158] = 0.0;
  Phi[164] = muDoubleScalarSin(qdh[2]) * ddp[3] - muDoubleScalarCos(qdh[2]) *
    ddp[4];
  Phi[170] = muDoubleScalarCos(qdh[2]) * ddp[3] + muDoubleScalarSin(qdh[2]) *
    ddp[4];
  Phi[176] = w[8] * w[6];
  Phi[182] = b_mpower(w[8]) - b_mpower(w[6]);
  Phi[188] = dw[7];
  Phi[194] = -ddp[8] * muDoubleScalarSin(qdh[3]) - 0.13 * (-dw[9] + w[10] * w[11]);
  Phi[200] = dw[9] * muDoubleScalarSin(qdh[3]) + w[9] * w[10] *
    muDoubleScalarCos(qdh[3]);
  Phi[206] = -w[10] * (muDoubleScalarSin(qdh[3]) * w[11] + w[9] *
                       muDoubleScalarCos(qdh[3]));
  Phi[212] = (b_mpower(w[10]) - b_mpower(w[11])) * muDoubleScalarSin(qdh[3]) -
    (dw[10] + w[9] * w[11]) * muDoubleScalarCos(qdh[3]);
  Phi[218] = ((ddp[11] * muDoubleScalarCos(qdh[4]) + 0.64707 * (dw[12] - w[13] *
    w[14])) * muDoubleScalarSin(qdh[3]) - ((-muDoubleScalarCos(qdh[4]) * ddp[9]
    - muDoubleScalarSin(qdh[4]) * ddp[10]) - 0.64707 * (muDoubleScalarCos(qdh[4])
    * (dw[13] + w[12] * w[14]) - muDoubleScalarSin(qdh[4]) * (-b_mpower(w[12]) -
    b_mpower(w[13])))) * muDoubleScalarCos(qdh[3])) - 0.13 * ((dw[13] + w[12] *
    w[14]) * muDoubleScalarSin(qdh[4]) + muDoubleScalarCos(qdh[4]) * (-b_mpower
    (w[12]) - b_mpower(w[13])));
  Phi[224] = (dw[12] * muDoubleScalarCos(qdh[4]) + w[13] * w[12] *
              muDoubleScalarSin(qdh[4])) * muDoubleScalarSin(qdh[3]) + w[12] *
    w[14] * muDoubleScalarCos(qdh[3]);
  Phi[230] = (-w[13] * w[14] * muDoubleScalarCos(qdh[4]) - w[13] * w[12] *
              muDoubleScalarSin(qdh[4])) * muDoubleScalarSin(qdh[3]) + dw[13] *
    muDoubleScalarCos(qdh[3]);
  Phi[236] = ((muDoubleScalarCos(qdh[5]) * dw[15] - muDoubleScalarSin(qdh[5]) *
               w[17] * w[15]) * muDoubleScalarCos(qdh[4]) + w[16] * w[15] *
              muDoubleScalarSin(qdh[4])) * muDoubleScalarSin(qdh[3]) - (-dw[15] *
    muDoubleScalarSin(qdh[5]) - w[17] * w[15] * muDoubleScalarCos(qdh[5])) *
    muDoubleScalarCos(qdh[3]);

  /*  Coppia: 4 */
  Phi[3] = 0.0;
  Phi[9] = 0.0;
  Phi[15] = 0.0;
  Phi[21] = 0.0;
  Phi[27] = 0.0;
  Phi[33] = 0.0;
  Phi[39] = muDoubleScalarSin(qdh[3]) * ddp[6] - muDoubleScalarCos(qdh[3]) *
    ddp[7];
  Phi[45] = -dw[9] - w[10] * w[11];
  Phi[51] = -b_mpower(w[11]) + b_mpower(w[9]);
  Phi[57] = -q[3];
  Phi[63] = ddp[11] * muDoubleScalarCos(qdh[4]) + 0.0 * (-muDoubleScalarSin(qdh
    [4]) * ddp[9] + muDoubleScalarCos(qdh[4]) * ddp[10]);
  Phi[69] = (-(dw[13] - w[12] * w[14]) * muDoubleScalarSin(qdh[4]) - (b_mpower
              (w[12]) - b_mpower(w[13])) * muDoubleScalarCos(qdh[4])) + 0.0 *
    (-dw[12] - w[13] * w[14]);
  Phi[75] = (-(dw[14] + w[12] * w[13]) * muDoubleScalarSin(qdh[4]) - (dw[12] -
              w[13] * w[14]) * muDoubleScalarCos(qdh[4])) + 0.0 * (-b_mpower(w
    [14]) + b_mpower(w[12]));
  Phi[81] = (-(b_mpower(w[13]) - b_mpower(w[14])) * muDoubleScalarSin(qdh[4]) -
             muDoubleScalarCos(qdh[4]) * (dw[13] + w[12] * w[14])) + 0.0 * (-dw
    [14] + w[12] * w[13]);
  Phi[87] = 0.0;
  Phi[93] = ((-ddp[14] * muDoubleScalarSin(qdh[5]) * muDoubleScalarSin(qdh[4]) -
              (-muDoubleScalarSin(qdh[5]) * ddp[12] + muDoubleScalarCos(qdh[5]) *
               ddp[13]) * muDoubleScalarCos(qdh[4])) + 0.0 * ddp[14] *
             muDoubleScalarCos(qdh[5])) - 0.0 * (-muDoubleScalarSin(qdh[5]) *
    ddp[12] + muDoubleScalarCos(qdh[5]) * ddp[13]);
  Phi[99] = ((-ddp[14] * muDoubleScalarCos(qdh[5]) * muDoubleScalarSin(qdh[4]) -
              (-muDoubleScalarCos(qdh[5]) * ddp[12] - muDoubleScalarSin(qdh[5]) *
               ddp[13]) * muDoubleScalarCos(qdh[4])) - 0.0 * ddp[14] *
             muDoubleScalarSin(qdh[5])) - 0.0 * (-muDoubleScalarCos(qdh[5]) *
    ddp[12] - muDoubleScalarSin(qdh[5]) * ddp[13]);
  Phi[105] = ((-((dw[16] - w[17] * w[15]) * muDoubleScalarCos(qdh[5]) - (dw[15]
    + w[17] * w[16]) * muDoubleScalarSin(qdh[5])) * muDoubleScalarSin(qdh[4]) -
               (b_mpower(w[15]) - b_mpower(w[16])) * muDoubleScalarCos(qdh[4]))
              + 0.0 * (-(dw[16] - w[17] * w[15]) * muDoubleScalarSin(qdh[5]) -
                       (dw[15] + w[17] * w[16]) * muDoubleScalarCos(qdh[5]))) -
    0.0 * (b_mpower(w[15]) - b_mpower(w[16]));
  Phi[111] = ((-(muDoubleScalarCos(qdh[5]) * (dw[17] + w[16] * w[15]) -
                 (b_mpower(w[17]) - b_mpower(w[15])) * muDoubleScalarSin(qdh[5]))
               * muDoubleScalarSin(qdh[4]) - (dw[15] - w[17] * w[16]) *
               muDoubleScalarCos(qdh[4])) + 0.0 * (-(dw[17] + w[16] * w[15]) *
    muDoubleScalarSin(qdh[5]) - (b_mpower(w[17]) - b_mpower(w[15])) *
    muDoubleScalarCos(qdh[5]))) - 0.0 * (dw[15] - w[17] * w[16]);
  Phi[117] = ((-((b_mpower(w[16]) - b_mpower(w[17])) * muDoubleScalarCos(qdh[5])
                 - (dw[17] - w[16] * w[15]) * muDoubleScalarSin(qdh[5])) *
               muDoubleScalarSin(qdh[4]) - (dw[16] + w[17] * w[15]) *
               muDoubleScalarCos(qdh[4])) + 0.0 * (-(b_mpower(w[16]) - b_mpower
    (w[17])) * muDoubleScalarSin(qdh[5]) - (dw[17] - w[16] * w[15]) *
    muDoubleScalarCos(qdh[5]))) - 0.0 * (dw[16] + w[17] * w[15]);
  Phi[123] = ((-(muDoubleScalarCos(qdh[5]) * w[17] * w[16] + muDoubleScalarSin
                 (qdh[5]) * w[17] * w[15]) * muDoubleScalarSin(qdh[4]) - dw[17] *
               muDoubleScalarCos(qdh[4])) + 0.0 * w[17] * (-w[16] *
    muDoubleScalarSin(qdh[5]) + w[15] * muDoubleScalarCos(qdh[5]))) - 0.0 * dw
    [17];
  Phi[129] = 0.0;
  Phi[135] = 0.0;
  Phi[141] = 0.0;
  Phi[147] = 0.0;
  Phi[153] = 0.0;
  Phi[159] = 0.0;
  Phi[165] = 0.0;
  Phi[171] = 0.0;
  Phi[177] = 0.0;
  Phi[183] = 0.0;
  Phi[189] = 0.0;
  Phi[195] = -muDoubleScalarCos(qdh[3]) * ddp[6] - muDoubleScalarSin(qdh[3]) *
    ddp[7];
  Phi[201] = -w[9] * w[11];
  Phi[207] = -dw[10];
  Phi[213] = -dw[11] + w[10] * w[9];
  Phi[219] = -ddp[11] * muDoubleScalarSin(qdh[4]) + 0.0 * (-muDoubleScalarCos
    (qdh[4]) * ddp[9] - muDoubleScalarSin(qdh[4]) * ddp[10]);
  Phi[225] = (-dw[12] * muDoubleScalarSin(qdh[4]) + w[13] * w[12] *
              muDoubleScalarCos(qdh[4])) - 0.0 * w[12] * w[14];
  Phi[231] = -w[13] * (-w[14] * muDoubleScalarSin(qdh[4]) + w[12] *
                       muDoubleScalarCos(qdh[4])) - 0.0 * dw[13];
  Phi[237] = ((-(muDoubleScalarCos(qdh[5]) * dw[15] - muDoubleScalarSin(qdh[5]) *
                 w[17] * w[15]) * muDoubleScalarSin(qdh[4]) + w[16] * w[15] *
               muDoubleScalarCos(qdh[4])) + 0.0 * (-dw[15] * muDoubleScalarSin
    (qdh[5]) - w[17] * w[15] * muDoubleScalarCos(qdh[5]))) + 0.0 * w[16] * w[15];

  /*  Coppia: 5 */
  Phi[4] = 0.0;
  Phi[10] = 0.0;
  Phi[16] = 0.0;
  Phi[22] = 0.0;
  Phi[28] = 0.0;
  Phi[34] = 0.0;
  Phi[40] = 0.0;
  Phi[46] = 0.0;
  Phi[52] = 0.0;
  Phi[58] = 0.0;
  Phi[64] = -muDoubleScalarSin(qdh[4]) * ddp[9] + muDoubleScalarCos(qdh[4]) *
    ddp[10];
  Phi[70] = -dw[12] - w[13] * w[14];
  Phi[76] = -b_mpower(w[14]) + b_mpower(w[12]);
  Phi[82] = -dw[14] + w[12] * w[13];
  Phi[88] = 0.0 * q[3] + q[4];
  Phi[94] = ddp[14] * muDoubleScalarCos(qdh[5]) - 0.02 * (-muDoubleScalarSin
    (qdh[5]) * ddp[12] + muDoubleScalarCos(qdh[5]) * ddp[13]);
  Phi[100] = -ddp[14] * muDoubleScalarSin(qdh[5]) - 0.02 * (-muDoubleScalarCos
    (qdh[5]) * ddp[12] - muDoubleScalarSin(qdh[5]) * ddp[13]);
  Phi[106] = (-(dw[16] - w[17] * w[15]) * muDoubleScalarSin(qdh[5]) - (dw[15] +
    w[17] * w[16]) * muDoubleScalarCos(qdh[5])) - 0.02 * (b_mpower(w[15]) -
    b_mpower(w[16]));
  Phi[112] = (-(dw[17] + w[16] * w[15]) * muDoubleScalarSin(qdh[5]) - (b_mpower
    (w[17]) - b_mpower(w[15])) * muDoubleScalarCos(qdh[5])) - 0.02 * (dw[15] -
    w[17] * w[16]);
  Phi[118] = (-(b_mpower(w[16]) - b_mpower(w[17])) * muDoubleScalarSin(qdh[5]) -
              (dw[17] - w[16] * w[15]) * muDoubleScalarCos(qdh[5])) - 0.02 *
    (dw[16] + w[17] * w[15]);
  Phi[124] = w[17] * (-w[16] * muDoubleScalarSin(qdh[5]) + w[15] *
                      muDoubleScalarCos(qdh[5])) - 0.02 * dw[17];
  Phi[130] = 0.0;
  Phi[136] = 0.0;
  Phi[142] = 0.0;
  Phi[148] = 0.0;
  Phi[154] = 0.0;
  Phi[160] = 0.0;
  Phi[166] = 0.0;
  Phi[172] = 0.0;
  Phi[178] = 0.0;
  Phi[184] = 0.0;
  Phi[190] = 0.0;
  Phi[196] = 0.0;
  Phi[202] = 0.0;
  Phi[208] = 0.0;
  Phi[214] = 0.0;
  Phi[220] = -muDoubleScalarCos(qdh[4]) * ddp[9] - muDoubleScalarSin(qdh[4]) *
    ddp[10];
  Phi[226] = -w[12] * w[14];
  Phi[232] = -dw[13];
  Phi[238] = (-dw[15] * muDoubleScalarSin(qdh[5]) - w[17] * w[15] *
              muDoubleScalarCos(qdh[5])) + 0.02 * w[16] * w[15];

  /*  Coppia: 6 */
  Phi[5] = 0.0;
  Phi[11] = 0.0;
  Phi[17] = 0.0;
  Phi[23] = 0.0;
  Phi[29] = 0.0;
  Phi[35] = 0.0;
  Phi[41] = 0.0;
  Phi[47] = 0.0;
  Phi[53] = 0.0;
  Phi[59] = 0.0;
  Phi[65] = 0.0;
  Phi[71] = 0.0;
  Phi[77] = 0.0;
  Phi[83] = 0.0;
  Phi[89] = 0.0;
  Phi[95] = muDoubleScalarSin(qdh[5]) * ddp[12] - muDoubleScalarCos(qdh[5]) *
    ddp[13];
  Phi[101] = muDoubleScalarCos(qdh[5]) * ddp[12] + muDoubleScalarSin(qdh[5]) *
    ddp[13];
  Phi[107] = -b_mpower(w[15]) + b_mpower(w[16]);
  Phi[113] = -dw[15] + w[17] * w[16];
  Phi[119] = -dw[16] - w[17] * w[15];
  Phi[125] = -dw[17];
  Phi[131] = (0.0 * q[3] - 0.02 * q[4]) - q[5];
  Phi[137] = 0.0;
  Phi[143] = 0.0;
  Phi[149] = 0.0;
  Phi[155] = 0.0;
  Phi[161] = 0.0;
  Phi[167] = 0.0;
  Phi[173] = 0.0;
  Phi[179] = 0.0;
  Phi[185] = 0.0;
  Phi[191] = 0.0;
  Phi[197] = 0.0;
  Phi[203] = 0.0;
  Phi[209] = 0.0;
  Phi[215] = 0.0;
  Phi[221] = 0.0;
  Phi[227] = 0.0;
  Phi[233] = 0.0;
  Phi[239] = w[16] * w[15];

  /* theta = DYN.MODEL(1:40); %parametri dinamici ridotti (senza attrito). */
  /*      Centrifugo = Ycomau2dh*Phi*theta-CGravita(qDH); %sottrae il contributo di coppia di gravit� */
  CGravita2(qDH, temp);
  mpower();
  alpha1 = 1.0;
  beta1 = 0.0;
  TRANSB = 'N';
  TRANSA = 'N';
  memset(&y[0], 0, 240U * sizeof(real_T));
  m_t = (ptrdiff_t)6;
  n_t = (ptrdiff_t)40;
  k_t = (ptrdiff_t)6;
  lda_t = (ptrdiff_t)6;
  ldb_t = (ptrdiff_t)6;
  ldc_t = (ptrdiff_t)6;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &Phi[0],
        &ldb_t, &beta1, &y[0], &ldc_t);

  /* sottrae il contributo di coppia di gravit� */
  for (i = 0; i < 6; i++) {
    alpha1 = 0.0;
    for (i6 = 0; i6 < 40; i6++) {
      alpha1 += y[i + 6 * i6] * b[i6];
    }

    Centrifugo1[i] = alpha1 - temp[i];
  }
}

/* End of code generation (CCentrifugo3.c) */
