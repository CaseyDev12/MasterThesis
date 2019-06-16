/*
 * CGravita2.c
 *
 * Code generation for function 'CGravita2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CGravita2.h"

/* Function Definitions */
void CGravita2(const emlrtStack *sp, const real_T qDH[8], real_T Gravita[8])
{
  real_T a[6];
  int32_T i0;
  int32_T i1;
  static const int8_T b_a[36] = { -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, -1 };

  (void)sp;

  /* Calcola le coppie di Gravit� */
  /*  Ingressi: */
  /*        qDH : vettori 6x1 secondo convenzioni DH in rad */
  /*   */
  /*  Uscite: */
  /*        Gravit�: Coppie di Gravit� g(qDH) in convenzione DH */
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
  /*  addpath('../modello SIX/') */
  memset(&Gravita[0], 0, sizeof(real_T) << 3);
  Gravita[0] = 0.0;
  Gravita[1] = ((((((((((((((((((((((((((((41.831982838746633 *
    muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1]) + 41.831982838746633 *
    muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) - 40.888143981693084 *
    muDoubleScalarCos(qDH[2]) * muDoubleScalarCos(qDH[1])) + 40.888143981693084 *
    muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) + 0.51801607185471 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[2]) * muDoubleScalarCos(qDH[1])) - 0.084385585145070025 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[2]) * muDoubleScalarSin(qDH[1])) + 0.084385585145070025 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[2]) * muDoubleScalarCos(qDH[1])) + 0.00079253287965000007 *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) -
    0.00079253287965000007 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarCos
    (qDH[1])) - 0.51801607185471 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) +
    8.043617286E-5 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin
    (qDH[1])) - 8.043617286E-5 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2]) *
    muDoubleScalarCos(qDH[1])) - 2.39661163881369 * muDoubleScalarSin(qDH[1])) -
    294.63271669184564 * muDoubleScalarCos(qDH[1])) - 0.00079253287965000007 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[2]) * muDoubleScalarSin(qDH[1])) + 0.71102308856895 * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarCos(qDH[1])) -
    0.71102308856895 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) *
    muDoubleScalarSin(qDH[1])) + 0.51801607185471 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) -
    0.084385585145070025 * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2])
    * muDoubleScalarSin(qDH[1])) - 0.084385585145070025 * muDoubleScalarSin(qDH
    [4]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) +
                        0.51801607185471 * muDoubleScalarCos(qDH[4]) *
                        muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) +
                       0.00079253287965000007 * muDoubleScalarSin(qDH[3]) *
                       muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[2]) *
                       muDoubleScalarCos(qDH[1])) + 8.043617286E-5 *
                      muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) *
                      muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) -
                     8.043617286E-5 * muDoubleScalarSin(qDH[3]) *
                     muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[2]) *
                     muDoubleScalarCos(qDH[1])) + 0.00079253287965000007 *
                    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[5]) *
                    muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) +
                   8.043617286E-5 * muDoubleScalarSin(qDH[4]) *
                   muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[2]) *
                   muDoubleScalarSin(qDH[1])) + 8.043617286E-5 *
                  muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[5]) *
                  muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) +
                 0.00079253287965000007 * muDoubleScalarSin(qDH[4]) *
                 muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[2]) *
                 muDoubleScalarCos(qDH[1])) + 2.45893649432049 *
                muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) *
                muDoubleScalarCos(qDH[1])) - 2.45893649432049 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin
    (qDH[1]);
  Gravita[2] = ((((((((((((((((((((((((((-41.831982838746633 * muDoubleScalarSin
    (qDH[2]) * muDoubleScalarCos(qDH[1]) - 41.831982838746633 *
    muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) + 40.888143981693084 *
    muDoubleScalarCos(qDH[2]) * muDoubleScalarCos(qDH[1])) - 40.888143981693084 *
    muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) - 0.51801607185471 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[2]) * muDoubleScalarCos(qDH[1])) + 0.084385585145070025 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[2]) * muDoubleScalarSin(qDH[1])) - 0.084385585145070025 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[2]) * muDoubleScalarCos(qDH[1])) - 0.00079253287965000007 *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) +
    0.00079253287965000007 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarCos
    (qDH[1])) + 0.51801607185471 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) -
    8.043617286E-5 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin
    (qDH[1])) + 8.043617286E-5 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2]) *
    muDoubleScalarCos(qDH[1])) + 0.00079253287965000007 * muDoubleScalarSin(qDH
    [3]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[2]) *
    muDoubleScalarSin(qDH[1])) - 0.71102308856895 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[2]) * muDoubleScalarCos(qDH[1])) + 0.71102308856895 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin
    (qDH[1])) - 0.51801607185471 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[2]) * muDoubleScalarSin(qDH[1])) + 0.084385585145070025 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarSin
    (qDH[1])) + 0.084385585145070025 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) - 0.51801607185471 *
                        muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2]) *
                        muDoubleScalarCos(qDH[1])) - 0.00079253287965000007 *
                       muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[5]) *
                       muDoubleScalarCos(qDH[2]) * muDoubleScalarCos(qDH[1])) -
                      8.043617286E-5 * muDoubleScalarSin(qDH[3]) *
                      muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[2]) *
                      muDoubleScalarSin(qDH[1])) + 8.043617286E-5 *
                     muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) *
                     muDoubleScalarCos(qDH[2]) * muDoubleScalarCos(qDH[1])) -
                    0.00079253287965000007 * muDoubleScalarSin(qDH[4]) *
                    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[2]) *
                    muDoubleScalarSin(qDH[1])) - 8.043617286E-5 *
                   muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[5]) *
                   muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) -
                  8.043617286E-5 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
                  (qDH[5]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1]))
                 - 0.00079253287965000007 * muDoubleScalarSin(qDH[4]) *
                 muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[2]) *
                 muDoubleScalarCos(qDH[1])) - 2.45893649432049 *
                muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) *
                muDoubleScalarCos(qDH[1])) + 2.45893649432049 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin
    (qDH[1]);
  Gravita[3] = ((((((((((((((-0.00079253287965000007 * muDoubleScalarCos(qDH[4])
    * muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[2]) * muDoubleScalarSin(qDH[1]) - 0.00079253287965000007 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[5]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) +
    2.45893649432049 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) *
    muDoubleScalarSin(qDH[1])) + 0.51801607185471 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos
    (qDH[1])) + 0.51801607185471 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) +
    0.084385585145070025 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[4])
    * muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) +
                        0.084385585145070025 * muDoubleScalarSin(qDH[3]) *
                        muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2]) *
                        muDoubleScalarCos(qDH[1])) - 0.71102308856895 *
                       muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) *
                       muDoubleScalarSin(qDH[1])) - 0.71102308856895 *
                      muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) *
                      muDoubleScalarCos(qDH[1])) + 8.043617286E-5 *
                     muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3]) *
                     muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) -
                    0.00079253287965000007 * muDoubleScalarSin(qDH[5]) *
                    muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) *
                    muDoubleScalarSin(qDH[1])) - 0.00079253287965000007 *
                   muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]) *
                   muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) +
                  8.043617286E-5 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
                  (qDH[3]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1]))
                 + 2.45893649432049 * muDoubleScalarSin(qDH[3]) *
                 muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) -
                8.043617286E-5 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
                (qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2])
                * muDoubleScalarSin(qDH[1])) - 8.043617286E-5 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1]);
  Gravita[4] = ((((((((((((((((((((((((((8.043617286E-5 * muDoubleScalarSin(qDH
    [5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2]) *
    muDoubleScalarSin(qDH[1]) - 8.043617286E-5 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarCos
    (qDH[1])) + 0.00079253287965000007 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin
    (qDH[1])) - 0.00079253287965000007 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarCos
    (qDH[1])) - 0.084385585145070025 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarSin
    (qDH[1])) - 0.084385585145070025 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) + 0.51801607185471 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarCos
    (qDH[1])) - 0.51801607185471 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[2]) * muDoubleScalarSin(qDH[1])) + 0.084385585145070025 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarCos
    (qDH[1])) - 1.5850657593E-5 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) *
    muDoubleScalarSin(qDH[1])) - 1.5850657593E-5 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2]) * muDoubleScalarCos(qDH[1])) + 1.6087234572E-6 * muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) + 1.6087234572E-6 *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) +
    0.00079253287965000007 * muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4])
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarSin
    (qDH[1])) + 0.00079253287965000007 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2]) * muDoubleScalarCos(qDH[1])) + 8.043617286E-5 * muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) + 8.043617286E-5 *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) -
    0.084385585145070025 * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3])
    * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) + 0.51801607185471 *
                        muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
                        muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) +
                       0.51801607185471 * muDoubleScalarCos(qDH[4]) *
                       muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) *
                       muDoubleScalarSin(qDH[1])) - 1.6087234572E-6 *
                      muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]) *
                      muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) -
                     1.6087234572E-6 * muDoubleScalarSin(qDH[5]) *
                     muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) *
                     muDoubleScalarCos(qDH[1])) - 1.6087234572E-6 *
                    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
                    muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) +
                   1.6087234572E-6 * muDoubleScalarCos(qDH[5]) *
                   muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2]) *
                   muDoubleScalarCos(qDH[1])) - 1.5850657593E-5 *
                  muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) *
                  muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) -
                 1.5850657593E-5 * muDoubleScalarCos(qDH[5]) * muDoubleScalarSin
                 (qDH[3]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1]))
                - 1.5850657593E-5 * muDoubleScalarSin(qDH[5]) *
                muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2]) *
                muDoubleScalarCos(qDH[1])) + 1.5850657593E-5 * muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[2]) *
    muDoubleScalarSin(qDH[1]);
  Gravita[5] = ((((((((((-8.043617286E-5 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarSin
    (qDH[1]) - 8.043617286E-5 * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) -
                        0.00079253287965000007 * muDoubleScalarSin(qDH[5]) *
                        muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
                        muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) -
                       0.00079253287965000007 * muDoubleScalarSin(qDH[5]) *
                       muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
                       muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) +
                      0.00079253287965000007 * muDoubleScalarSin(qDH[5]) *
                      muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[2]) *
                      muDoubleScalarSin(qDH[1])) - 0.00079253287965000007 *
                     muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
                     muDoubleScalarCos(qDH[2]) * muDoubleScalarCos(qDH[1])) -
                    0.00079253287965000007 * muDoubleScalarCos(qDH[5]) *
                    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) *
                    muDoubleScalarSin(qDH[1])) - 0.00079253287965000007 *
                   muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) *
                   muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) +
                  8.043617286E-5 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
                  (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2])
                  * muDoubleScalarSin(qDH[1])) + 8.043617286E-5 *
                 muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                 muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) *
                 muDoubleScalarCos(qDH[1])) - 8.043617286E-5 * muDoubleScalarCos
                (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[2])
                * muDoubleScalarSin(qDH[1])) + 8.043617286E-5 *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[2]) * muDoubleScalarCos(qDH[1]);
  for (i0 = 0; i0 < 6; i0++) {
    a[i0] = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      a[i0] += (real_T)b_a[i0 + 6 * i1] * Gravita[i1];
    }
  }

  for (i0 = 0; i0 < 6; i0++) {
    Gravita[i0] = a[i0];
  }
}

/* End of code generation (CGravita2.c) */
