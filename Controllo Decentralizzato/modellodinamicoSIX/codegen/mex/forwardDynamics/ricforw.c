/*
 * ricforw.c
 *
 * Code generation for function 'ricforw'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "ricforw.h"
#include "mpower.h"

/* Function Definitions */
void ricforw(const real_T q[6], const real_T dq[6], const real_T ddq[6], real_T
             w[18], real_T dw[18], real_T ddp[18])
{
  real_T qdh_deg[6];
  real_T dqdh_deg[6];
  real_T ddqdh_deg[6];
  int32_T i7;
  real_T w2x;
  real_T w2y;
  real_T w3x;
  real_T w3y;
  real_T w3z;
  real_T w4x;
  real_T w4y;
  real_T w4z;
  real_T w5x;
  real_T w5y;
  real_T w6x;
  real_T w6y;
  real_T w6z;
  real_T dw2y;
  real_T dw3y;
  real_T dw3z;
  real_T dw4x;
  real_T dw4z;
  real_T dw6x;
  real_T dw6y;
  real_T ddp1x;
  real_T ddp2x;
  real_T ddp2y;
  real_T ddp3x;
  real_T ddp3z;
  real_T ddp4x;
  real_T ddp4y;
  real_T ddp4z;
  real_T ddp5x;
  real_T ddp5y;
  real_T ddp5z;
  real_T ddp6x;
  real_T ddp6y;
  real_T ddp6z;

  /*  */
  /*  SIX - Gennaio 2005 */
  /*  */
  /*  [w,dw,ddp] = ricforw(q,dq,ddq) */
  /*  */
  /*  Calcola, in numerico, le velocitï¿½ e le accelerazioni delle terne */
  /*  */
  /*  Ingressi: */
  /*    q, dq, ddq : vettori 6x1 contenenti le posizioni (in deg), le velocitï¿½ (in deg/sec) e le accelerazioni (in deg/sec^2) */
  /*                 ai giunti in convenzione COMAU  */
  /*  Uscite: */
  /*    matrici 3x6 con i vettori in colonna */
  /*      w   = [w1x   w2x   w3x   w4x   w5x   w6x  */
  /*             w1y   w2y   w3y   w4y   w5y   w6y  */
  /*             w1z   w2z   w3z   w4z   w5z   w6z  ] */
  /*          velocitï¿½ angolari delle terne in rad/sec in convenzione DH */
  /*      dw  = [dw1x  dw2x  dw3x  dw4x  dw5x  dw6x  */
  /*             dw1y  dw2y  dw3y  dw4y  dw5y  dw6y  */
  /*             dw1z  dw2z  dw3z  dw4z  dw5z  dw6z ]    */
  /*          accelerazioni angolari delle terne in rad/sec^2 in convenzione DH */
  /*      ddp = [ddp1x ddp2x ddp3x ddp4x ddp5x ddp6x */
  /*             ddp1y ddp2y ddp3y ddp4y ddp5y ddp6y */
  /*             ddp1z ddp2z ddp3z ddp4z ddp5z ddp6z] */
  /*          accelerazioni lineari delle terne in m/sec^2 in convenzione DH */
  /*  File letti: */
  /*    costanti.m : definzione delle costanti per la dinamica */
  /* ************************************************************************************************************************ */
  /*  Legge i dati contenuti nel file "costanti.m" */
  /* ************************************************************************************************************************ */
  /*  costanti; */
  /* ************************************************************************************************************************ */
  /*  Conversione delle grandezze */
  /* ************************************************************************************************************************ */
  /*  Posizioni ai giunti */
  /*  converte posizioni comau in gradi in posizioni dh in gradi */
  /*  */
  /*  SIX - Gennaio 2005 */
  /*  */
  /*  qdh = comau2dh(qcomau) */
  /*  */
  /*  Converte le posizioni dei giunti dalla convenzione COMAU alla convenzione DH */
  /*  */
  /*  Ingressi: */
  /*    qcomau: vettore 6x1 delle posizioni in convenzione COMAU in gradi */
  /*  Uscite: */
  /*    qdh   : vettore 6x1 delle posizioni in convenzione DH in gradi */
  /*  Note: */
  /*    le unita' di misura devono essere necessariamente in gradi */
  /*    la chiamata seguente: comau2dh(zeros(6,1)) fornisce il vettore q0 in gradi in convenzione DH */
  qdh_deg[0] = -q[0];
  qdh_deg[1] = q[1] - 90.0;
  qdh_deg[2] = -q[2] - 90.0;
  qdh_deg[3] = -q[3];
  qdh_deg[4] = q[4];
  qdh_deg[5] = -q[5] + 180.0;

  /*  converte posizioni dh in gradi in posizioni dh in radianti */
  /*  rinomina le variabili delle posizioni: le variabili qi saranno le posizioni dh in radianti */
  /*  Velocitï¿½ ai giunti */
  /*  converte velocitï¿½ comau in deg/sec in velocitï¿½ dh in deg/sec */
  /*  */
  /*  SIX - Gennaio 2005 */
  /*  */
  /*  dqdh = comau2dh_vel(dqcomau) */
  /*  */
  /*  Converte le velocità/accelerazioni dei giunti dalla convenzione COMAU alla convenzione DH */
  /*  */
  /*  Ingressi: */
  /*    dqcomau: vettore 6x1 delle velocità (o accelerazioni) in convenzione COMAU */
  /*  Uscite: */
  /*    dqdh   : vettore 6x1 delle velocità (o accelerazioni) in convenzione DH */
  /*  Note: */
  /*    le unità di misura sono ininfluenti */
  dqdh_deg[0] = -dq[0];
  dqdh_deg[1] = dq[1];
  dqdh_deg[2] = -dq[2];
  dqdh_deg[3] = -dq[3];
  dqdh_deg[4] = dq[4];
  dqdh_deg[5] = -dq[5];

  /*  converte velocitï¿½ dh in deg/sec in velocitï¿½ dh in rad/sec */
  /*  rinomina le variabili delle velocitï¿½: le variabili dqi saranno le velocitï¿½ dh in rad/sec */
  /*  Accelerazioni ai giunti */
  /*  converte accelerazioni comau in deg/sec^2 in accelerazioni dh in deg/sec^2  */
  /*  */
  /*  SIX - Gennaio 2005 */
  /*  */
  /*  dqdh = comau2dh_vel(dqcomau) */
  /*  */
  /*  Converte le velocità/accelerazioni dei giunti dalla convenzione COMAU alla convenzione DH */
  /*  */
  /*  Ingressi: */
  /*    dqcomau: vettore 6x1 delle velocità (o accelerazioni) in convenzione COMAU */
  /*  Uscite: */
  /*    dqdh   : vettore 6x1 delle velocità (o accelerazioni) in convenzione DH */
  /*  Note: */
  /*    le unità di misura sono ininfluenti */
  ddqdh_deg[0] = -ddq[0];
  ddqdh_deg[1] = ddq[1];
  ddqdh_deg[2] = -ddq[2];
  ddqdh_deg[3] = -ddq[3];
  ddqdh_deg[4] = ddq[4];
  ddqdh_deg[5] = -ddq[5];

  /*  converte accelerazioni dh in deg/sec^2 in accelerazioni dh in rad/sec^2 */
  for (i7 = 0; i7 < 6; i7++) {
    qdh_deg[i7] *= 0.017453292519943295;
    dqdh_deg[i7] *= 0.017453292519943295;
    ddqdh_deg[i7] *= 0.017453292519943295;
  }

  /*  rinomina le variabili delle accelerazioni: le variabili ddqi saranno le accelerazioni dh in rad/sec^2 */
  /* ************************************************************************************************************************ */
  /*  Cinematica diretta (codice presente in "cinematica.txt") */
  /* ************************************************************************************************************************ */
  /*  Velocitï¿½ angolari w delle terne */
  w2x = -muDoubleScalarSin(qdh_deg[1]) * dqdh_deg[0];
  w2y = -muDoubleScalarCos(qdh_deg[1]) * dqdh_deg[0];
  w3x = -dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1]);
  w3y = -dqdh_deg[1] - dqdh_deg[2];
  w3z = -dqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1]);
  w4x = -muDoubleScalarCos(qdh_deg[3]) * dqdh_deg[0] * muDoubleScalarSin
    (qdh_deg[2] + qdh_deg[1]) + muDoubleScalarSin(qdh_deg[3]) * (-dqdh_deg[1] -
    dqdh_deg[2]);
  w4y = -dqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1]) + dqdh_deg[3];
  w4z = -muDoubleScalarSin(qdh_deg[3]) * dqdh_deg[0] * muDoubleScalarSin
    (qdh_deg[2] + qdh_deg[1]) - muDoubleScalarCos(qdh_deg[3]) * (-dqdh_deg[1] -
    dqdh_deg[2]);
  w5x = muDoubleScalarCos(qdh_deg[4]) * (-muDoubleScalarCos(qdh_deg[3]) *
    dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1]) + muDoubleScalarSin
    (qdh_deg[3]) * (-dqdh_deg[1] - dqdh_deg[2])) + muDoubleScalarSin(qdh_deg[4])
    * (-dqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1]) + dqdh_deg[3]);
  w5y = (muDoubleScalarSin(qdh_deg[3]) * dqdh_deg[0] * muDoubleScalarSin
         (qdh_deg[2] + qdh_deg[1]) + muDoubleScalarCos(qdh_deg[3]) * (-dqdh_deg
          [1] - dqdh_deg[2])) - dqdh_deg[4];
  w6x = muDoubleScalarCos(qdh_deg[5]) * (muDoubleScalarCos(qdh_deg[4]) *
    (-muDoubleScalarCos(qdh_deg[3]) * dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2]
    + qdh_deg[1]) + muDoubleScalarSin(qdh_deg[3]) * (-dqdh_deg[1] - dqdh_deg[2]))
    + muDoubleScalarSin(qdh_deg[4]) * (-dqdh_deg[0] * muDoubleScalarCos(qdh_deg
    [2] + qdh_deg[1]) + dqdh_deg[3])) + muDoubleScalarSin(qdh_deg[5]) *
    ((muDoubleScalarSin(qdh_deg[3]) * dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2]
       + qdh_deg[1]) + muDoubleScalarCos(qdh_deg[3]) * (-dqdh_deg[1] - dqdh_deg
       [2])) - dqdh_deg[4]);
  w6y = -muDoubleScalarSin(qdh_deg[5]) * (muDoubleScalarCos(qdh_deg[4]) *
    (-muDoubleScalarCos(qdh_deg[3]) * dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2]
    + qdh_deg[1]) + muDoubleScalarSin(qdh_deg[3]) * (-dqdh_deg[1] - dqdh_deg[2]))
    + muDoubleScalarSin(qdh_deg[4]) * (-dqdh_deg[0] * muDoubleScalarCos(qdh_deg
    [2] + qdh_deg[1]) + dqdh_deg[3])) + muDoubleScalarCos(qdh_deg[5]) *
    ((muDoubleScalarSin(qdh_deg[3]) * dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2]
       + qdh_deg[1]) + muDoubleScalarCos(qdh_deg[3]) * (-dqdh_deg[1] - dqdh_deg
       [2])) - dqdh_deg[4]);
  w6z = (-muDoubleScalarSin(qdh_deg[4]) * (-muDoubleScalarCos(qdh_deg[3]) *
          dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1]) +
          muDoubleScalarSin(qdh_deg[3]) * (-dqdh_deg[1] - dqdh_deg[2])) +
         muDoubleScalarCos(qdh_deg[4]) * (-dqdh_deg[0] * muDoubleScalarCos
          (qdh_deg[2] + qdh_deg[1]) + dqdh_deg[3])) + dqdh_deg[5];

  /*  Accelerazioni angolari dw delle terne */
  dw2y = -muDoubleScalarSin(qdh_deg[1]) * dqdh_deg[1] * -dqdh_deg[0] -
    muDoubleScalarCos(qdh_deg[1]) * ddqdh_deg[0];
  dw3y = -ddqdh_deg[1] - ddqdh_deg[2];
  dw3z = ((-dqdh_deg[1] * -dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg
            [1]) - ddqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1])) -
          muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2y) - muDoubleScalarCos
    (qdh_deg[2]) * dqdh_deg[2] * w2x;
  dw4x = muDoubleScalarCos(qdh_deg[3]) * ((((dqdh_deg[1] * -dqdh_deg[0] *
    muDoubleScalarCos(qdh_deg[2] + qdh_deg[1]) - ddqdh_deg[0] *
    muDoubleScalarSin(qdh_deg[2] + qdh_deg[1])) + muDoubleScalarCos(qdh_deg[2]) *
    dqdh_deg[2] * w2y) - muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2x) +
    dqdh_deg[3] * w3y) + muDoubleScalarSin(qdh_deg[3]) * ((-ddqdh_deg[1] -
    ddqdh_deg[2]) - dqdh_deg[3] * w3x);
  dw4z = muDoubleScalarSin(qdh_deg[3]) * ((((dqdh_deg[1] * -dqdh_deg[0] *
    muDoubleScalarCos(qdh_deg[2] + qdh_deg[1]) - ddqdh_deg[0] *
    muDoubleScalarSin(qdh_deg[2] + qdh_deg[1])) + muDoubleScalarCos(qdh_deg[2]) *
    dqdh_deg[2] * w2y) - muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2x) +
    dqdh_deg[3] * w3y) - muDoubleScalarCos(qdh_deg[3]) * ((-ddqdh_deg[1] -
    ddqdh_deg[2]) - dqdh_deg[3] * w3x);
  dw6x = muDoubleScalarCos(qdh_deg[5]) * ((muDoubleScalarCos(qdh_deg[4]) *
    ((muDoubleScalarCos(qdh_deg[3]) * ((((dqdh_deg[1] * -dqdh_deg[0] *
    muDoubleScalarCos(qdh_deg[2] + qdh_deg[1]) - ddqdh_deg[0] *
    muDoubleScalarSin(qdh_deg[2] + qdh_deg[1])) + muDoubleScalarCos(qdh_deg[2]) *
    dqdh_deg[2] * w2y) - muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2x) +
    dqdh_deg[3] * w3y) + muDoubleScalarSin(qdh_deg[3]) * ((-ddqdh_deg[1] -
    ddqdh_deg[2]) - dqdh_deg[3] * w3x)) + dqdh_deg[4] * w4y) + muDoubleScalarSin
    (qdh_deg[4]) * (((((-dqdh_deg[1] * -dqdh_deg[0] * muDoubleScalarSin(qdh_deg
    [2] + qdh_deg[1]) - ddqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1]))
                       - muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2y) -
                      muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2x) +
                     ddqdh_deg[3]) - dqdh_deg[4] * w4x)) + dqdh_deg[5] * w5y) +
    muDoubleScalarSin(qdh_deg[5]) * (((-muDoubleScalarSin(qdh_deg[3]) *
    ((((dqdh_deg[1] * -dqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1])
        - ddqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1])) +
       muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2y) - muDoubleScalarSin
      (qdh_deg[2]) * dqdh_deg[2] * w2x) + dqdh_deg[3] * w3y) + muDoubleScalarCos
    (qdh_deg[3]) * ((-ddqdh_deg[1] - ddqdh_deg[2]) - dqdh_deg[3] * w3x)) -
    ddqdh_deg[4]) - dqdh_deg[5] * w5x);
  dw6y = -muDoubleScalarSin(qdh_deg[5]) * ((muDoubleScalarCos(qdh_deg[4]) *
    ((muDoubleScalarCos(qdh_deg[3]) * ((((dqdh_deg[1] * -dqdh_deg[0] *
    muDoubleScalarCos(qdh_deg[2] + qdh_deg[1]) - ddqdh_deg[0] *
    muDoubleScalarSin(qdh_deg[2] + qdh_deg[1])) + muDoubleScalarCos(qdh_deg[2]) *
    dqdh_deg[2] * w2y) - muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2x) +
    dqdh_deg[3] * w3y) + muDoubleScalarSin(qdh_deg[3]) * ((-ddqdh_deg[1] -
    ddqdh_deg[2]) - dqdh_deg[3] * w3x)) + dqdh_deg[4] * w4y) + muDoubleScalarSin
    (qdh_deg[4]) * (((((-dqdh_deg[1] * -dqdh_deg[0] * muDoubleScalarSin(qdh_deg
    [2] + qdh_deg[1]) - ddqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1]))
                       - muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2y) -
                      muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2x) +
                     ddqdh_deg[3]) - dqdh_deg[4] * w4x)) + dqdh_deg[5] * w5y) +
    muDoubleScalarCos(qdh_deg[5]) * (((-muDoubleScalarSin(qdh_deg[3]) *
    ((((dqdh_deg[1] * -dqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1])
        - ddqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1])) +
       muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2y) - muDoubleScalarSin
      (qdh_deg[2]) * dqdh_deg[2] * w2x) + dqdh_deg[3] * w3y) + muDoubleScalarCos
    (qdh_deg[3]) * ((-ddqdh_deg[1] - ddqdh_deg[2]) - dqdh_deg[3] * w3x)) -
    ddqdh_deg[4]) - dqdh_deg[5] * w5x);

  /*  Accelerazioni lineari ddp delle terne */
  ddp1x = (-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) *
           0.0) - b_mpower(-dqdh_deg[0]) * 0.15;
  ddp2x = ((muDoubleScalarCos(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) *
              0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0])
             * 0.15) + muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) *
           0.59) - b_mpower(dqdh_deg[1]) * 0.59;
  ddp2y = ((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) *
              0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0])
             * 0.15) + muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] *
           0.59) + w2x * w2y * 0.59;
  ddp3x = ((muDoubleScalarCos(qdh_deg[2]) * (((muDoubleScalarCos(qdh_deg[1]) *
    ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0)
     - b_mpower(-dqdh_deg[0]) * 0.15) + muDoubleScalarSin(qdh_deg[1]) * -9.81) -
              b_mpower(w2y) * 0.59) - b_mpower(dqdh_deg[1]) * 0.59) +
            muDoubleScalarSin(qdh_deg[2]) * (((-muDoubleScalarSin(qdh_deg[1]) *
    ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0)
     - b_mpower(-dqdh_deg[0]) * 0.15) + muDoubleScalarCos(qdh_deg[1]) * -9.81) +
              ddqdh_deg[1] * 0.59) + w2x * w2y * 0.59)) - b_mpower(w3y) * 0.13)
    - b_mpower(w3z) * 0.13;
  ddp3z = ((-muDoubleScalarSin(qdh_deg[2]) * (((muDoubleScalarCos(qdh_deg[1]) *
    ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0)
     - b_mpower(-dqdh_deg[0]) * 0.15) + muDoubleScalarSin(qdh_deg[1]) * -9.81) -
              b_mpower(w2y) * 0.59) - b_mpower(dqdh_deg[1]) * 0.59) +
            muDoubleScalarCos(qdh_deg[2]) * (((-muDoubleScalarSin(qdh_deg[1]) *
    ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0)
     - b_mpower(-dqdh_deg[0]) * 0.15) + muDoubleScalarCos(qdh_deg[1]) * -9.81) +
              ddqdh_deg[1] * 0.59) + w2x * w2y * 0.59)) - dw3y * 0.13) + w3x *
    w3z * 0.13;
  ddp4x = ((muDoubleScalarCos(qdh_deg[3]) * (((muDoubleScalarCos(qdh_deg[2]) *
    (((muDoubleScalarCos(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) * 0.59) - b_mpower
     (dqdh_deg[1]) * 0.59) + muDoubleScalarSin(qdh_deg[2]) *
    (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] * 0.59) + w2x * w2y
     * 0.59)) - b_mpower(w3y) * 0.13) - b_mpower(w3z) * 0.13) +
            muDoubleScalarSin(qdh_deg[3]) * ((((((-muDoubleScalarSin(qdh_deg[0])
    * 0.0 + muDoubleScalarCos(qdh_deg[0]) * 0.0) + -ddqdh_deg[0] * 0.15) + dw2y *
    0.59) - w2x * dqdh_deg[1] * 0.59) + dw3z * 0.13) + w3x * w3y * 0.13)) - dw4z
           * 0.64707) + w4y * w4x * 0.64707;
  ddp4y = ((((-muDoubleScalarSin(qdh_deg[2]) * (((muDoubleScalarCos(qdh_deg[1]) *
    ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0)
     - b_mpower(-dqdh_deg[0]) * 0.15) + muDoubleScalarSin(qdh_deg[1]) * -9.81) -
    b_mpower(w2y) * 0.59) - b_mpower(dqdh_deg[1]) * 0.59) + muDoubleScalarCos
              (qdh_deg[2]) * (((-muDoubleScalarSin(qdh_deg[1]) *
    ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0)
     - b_mpower(-dqdh_deg[0]) * 0.15) + muDoubleScalarCos(qdh_deg[1]) * -9.81) +
    ddqdh_deg[1] * 0.59) + w2x * w2y * 0.59)) - dw3y * 0.13) + w3x * w3z * 0.13)
           - b_mpower(w4z) * 0.64707) - b_mpower(w4x) * 0.64707;
  ddp4z = ((muDoubleScalarSin(qdh_deg[3]) * (((muDoubleScalarCos(qdh_deg[2]) *
    (((muDoubleScalarCos(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) * 0.59) - b_mpower
     (dqdh_deg[1]) * 0.59) + muDoubleScalarSin(qdh_deg[2]) *
    (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] * 0.59) + w2x * w2y
     * 0.59)) - b_mpower(w3y) * 0.13) - b_mpower(w3z) * 0.13) -
            muDoubleScalarCos(qdh_deg[3]) * ((((((-muDoubleScalarSin(qdh_deg[0])
    * 0.0 + muDoubleScalarCos(qdh_deg[0]) * 0.0) + -ddqdh_deg[0] * 0.15) + dw2y *
    0.59) - w2x * dqdh_deg[1] * 0.59) + dw3z * 0.13) + w3x * w3y * 0.13)) + dw4x
           * 0.64707) + w4y * w4z * 0.64707;
  ddp5x = muDoubleScalarCos(qdh_deg[4]) * (((muDoubleScalarCos(qdh_deg[3]) *
    (((muDoubleScalarCos(qdh_deg[2]) * (((muDoubleScalarCos(qdh_deg[1]) *
    ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0)
     - b_mpower(-dqdh_deg[0]) * 0.15) + muDoubleScalarSin(qdh_deg[1]) * -9.81) -
    b_mpower(w2y) * 0.59) - b_mpower(dqdh_deg[1]) * 0.59) + muDoubleScalarSin
       (qdh_deg[2]) * (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos
    (qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower
    (-dqdh_deg[0]) * 0.15) + muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg
                        [1] * 0.59) + w2x * w2y * 0.59)) - b_mpower(w3y) * 0.13)
     - b_mpower(w3z) * 0.13) + muDoubleScalarSin(qdh_deg[3]) *
    ((((((-muDoubleScalarSin(qdh_deg[0]) * 0.0 + muDoubleScalarCos(qdh_deg[0]) *
          0.0) + -ddqdh_deg[0] * 0.15) + dw2y * 0.59) - w2x * dqdh_deg[1] * 0.59)
      + dw3z * 0.13) + w3x * w3y * 0.13)) - dw4z * 0.64707) + w4y * w4x *
    0.64707) + muDoubleScalarSin(qdh_deg[4]) * (((((-muDoubleScalarSin(qdh_deg[2])
    * (((muDoubleScalarCos(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0
    - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
         muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) * 0.59) -
       b_mpower(dqdh_deg[1]) * 0.59) + muDoubleScalarCos(qdh_deg[2]) *
    (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] * 0.59) + w2x * w2y
     * 0.59)) - dw3y * 0.13) + w3x * w3z * 0.13) - b_mpower(w4z) * 0.64707) -
    b_mpower(w4x) * 0.64707);
  ddp5y = ((-muDoubleScalarSin(qdh_deg[3]) * (((muDoubleScalarCos(qdh_deg[2]) *
    (((muDoubleScalarCos(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) * 0.59) - b_mpower
     (dqdh_deg[1]) * 0.59) + muDoubleScalarSin(qdh_deg[2]) *
    (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] * 0.59) + w2x * w2y
     * 0.59)) - b_mpower(w3y) * 0.13) - b_mpower(w3z) * 0.13) +
            muDoubleScalarCos(qdh_deg[3]) * ((((((-muDoubleScalarSin(qdh_deg[0])
    * 0.0 + muDoubleScalarCos(qdh_deg[0]) * 0.0) + -ddqdh_deg[0] * 0.15) + dw2y *
    0.59) - w2x * dqdh_deg[1] * 0.59) + dw3z * 0.13) + w3x * w3y * 0.13)) - dw4x
           * 0.64707) - w4y * w4z * 0.64707;
  ddp5z = -muDoubleScalarSin(qdh_deg[4]) * (((muDoubleScalarCos(qdh_deg[3]) *
    (((muDoubleScalarCos(qdh_deg[2]) * (((muDoubleScalarCos(qdh_deg[1]) *
    ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0)
     - b_mpower(-dqdh_deg[0]) * 0.15) + muDoubleScalarSin(qdh_deg[1]) * -9.81) -
    b_mpower(w2y) * 0.59) - b_mpower(dqdh_deg[1]) * 0.59) + muDoubleScalarSin
       (qdh_deg[2]) * (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos
    (qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower
    (-dqdh_deg[0]) * 0.15) + muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg
                        [1] * 0.59) + w2x * w2y * 0.59)) - b_mpower(w3y) * 0.13)
     - b_mpower(w3z) * 0.13) + muDoubleScalarSin(qdh_deg[3]) *
    ((((((-muDoubleScalarSin(qdh_deg[0]) * 0.0 + muDoubleScalarCos(qdh_deg[0]) *
          0.0) + -ddqdh_deg[0] * 0.15) + dw2y * 0.59) - w2x * dqdh_deg[1] * 0.59)
      + dw3z * 0.13) + w3x * w3y * 0.13)) - dw4z * 0.64707) + w4y * w4x *
    0.64707) + muDoubleScalarCos(qdh_deg[4]) * (((((-muDoubleScalarSin(qdh_deg[2])
    * (((muDoubleScalarCos(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0
    - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
         muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) * 0.59) -
       b_mpower(dqdh_deg[1]) * 0.59) + muDoubleScalarCos(qdh_deg[2]) *
    (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] * 0.59) + w2x * w2y
     * 0.59)) - dw3y * 0.13) + w3x * w3z * 0.13) - b_mpower(w4z) * 0.64707) -
    b_mpower(w4x) * 0.64707);
  ddp6x = ((muDoubleScalarCos(qdh_deg[5]) * (muDoubleScalarCos(qdh_deg[4]) *
             (((muDoubleScalarCos(qdh_deg[3]) * (((muDoubleScalarCos(qdh_deg[2])
    * (((muDoubleScalarCos(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0
    - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
         muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) * 0.59) -
       b_mpower(dqdh_deg[1]) * 0.59) + muDoubleScalarSin(qdh_deg[2]) *
    (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] * 0.59) + w2x * w2y
     * 0.59)) - b_mpower(w3y) * 0.13) - b_mpower(w3z) * 0.13) +
                muDoubleScalarSin(qdh_deg[3]) * ((((((-muDoubleScalarSin
    (qdh_deg[0]) * 0.0 + muDoubleScalarCos(qdh_deg[0]) * 0.0) + -ddqdh_deg[0] *
    0.15) + dw2y * 0.59) - w2x * dqdh_deg[1] * 0.59) + dw3z * 0.13) + w3x * w3y *
    0.13)) - dw4z * 0.64707) + w4y * w4x * 0.64707) + muDoubleScalarSin(qdh_deg
              [4]) * (((((-muDoubleScalarSin(qdh_deg[2]) * (((muDoubleScalarCos
    (qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin
                     (qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
    muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) * 0.59) - b_mpower
    (dqdh_deg[1]) * 0.59) + muDoubleScalarCos(qdh_deg[2]) *
    (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] * 0.59) + w2x * w2y
     * 0.59)) - dw3y * 0.13) + w3x * w3z * 0.13) - b_mpower(w4z) * 0.64707) -
                      b_mpower(w4x) * 0.64707)) + muDoubleScalarSin(qdh_deg[5]) *
            (((-muDoubleScalarSin(qdh_deg[3]) * (((muDoubleScalarCos(qdh_deg[2])
    * (((muDoubleScalarCos(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0
    - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
         muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) * 0.59) -
       b_mpower(dqdh_deg[1]) * 0.59) + muDoubleScalarSin(qdh_deg[2]) *
    (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] * 0.59) + w2x * w2y
     * 0.59)) - b_mpower(w3y) * 0.13) - b_mpower(w3z) * 0.13) +
               muDoubleScalarCos(qdh_deg[3]) * ((((((-muDoubleScalarSin(qdh_deg
    [0]) * 0.0 + muDoubleScalarCos(qdh_deg[0]) * 0.0) + -ddqdh_deg[0] * 0.15) +
    dw2y * 0.59) - w2x * dqdh_deg[1] * 0.59) + dw3z * 0.13) + w3x * w3y * 0.13))
              - dw4x * 0.64707) - w4y * w4z * 0.64707)) + dw6y * 0.095) + w6z *
    w6x * 0.095;
  ddp6y = ((-muDoubleScalarSin(qdh_deg[5]) * (muDoubleScalarCos(qdh_deg[4]) *
             (((muDoubleScalarCos(qdh_deg[3]) * (((muDoubleScalarCos(qdh_deg[2])
    * (((muDoubleScalarCos(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0
    - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
         muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) * 0.59) -
       b_mpower(dqdh_deg[1]) * 0.59) + muDoubleScalarSin(qdh_deg[2]) *
    (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] * 0.59) + w2x * w2y
     * 0.59)) - b_mpower(w3y) * 0.13) - b_mpower(w3z) * 0.13) +
                muDoubleScalarSin(qdh_deg[3]) * ((((((-muDoubleScalarSin
    (qdh_deg[0]) * 0.0 + muDoubleScalarCos(qdh_deg[0]) * 0.0) + -ddqdh_deg[0] *
    0.15) + dw2y * 0.59) - w2x * dqdh_deg[1] * 0.59) + dw3z * 0.13) + w3x * w3y *
    0.13)) - dw4z * 0.64707) + w4y * w4x * 0.64707) + muDoubleScalarSin(qdh_deg
              [4]) * (((((-muDoubleScalarSin(qdh_deg[2]) * (((muDoubleScalarCos
    (qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin
                     (qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
    muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) * 0.59) - b_mpower
    (dqdh_deg[1]) * 0.59) + muDoubleScalarCos(qdh_deg[2]) *
    (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] * 0.59) + w2x * w2y
     * 0.59)) - dw3y * 0.13) + w3x * w3z * 0.13) - b_mpower(w4z) * 0.64707) -
                      b_mpower(w4x) * 0.64707)) + muDoubleScalarCos(qdh_deg[5]) *
            (((-muDoubleScalarSin(qdh_deg[3]) * (((muDoubleScalarCos(qdh_deg[2])
    * (((muDoubleScalarCos(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0
    - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
         muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower(w2y) * 0.59) -
       b_mpower(dqdh_deg[1]) * 0.59) + muDoubleScalarSin(qdh_deg[2]) *
    (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 -
    muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower(-dqdh_deg[0]) * 0.15) +
       muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg[1] * 0.59) + w2x * w2y
     * 0.59)) - b_mpower(w3y) * 0.13) - b_mpower(w3z) * 0.13) +
               muDoubleScalarCos(qdh_deg[3]) * ((((((-muDoubleScalarSin(qdh_deg
    [0]) * 0.0 + muDoubleScalarCos(qdh_deg[0]) * 0.0) + -ddqdh_deg[0] * 0.15) +
    dw2y * 0.59) - w2x * dqdh_deg[1] * 0.59) + dw3z * 0.13) + w3x * w3y * 0.13))
              - dw4x * 0.64707) - w4y * w4z * 0.64707)) - dw6x * 0.095) + w6z *
    w6y * 0.095;
  ddp6z = ((-muDoubleScalarSin(qdh_deg[4]) * (((muDoubleScalarCos(qdh_deg[3]) *
    (((muDoubleScalarCos(qdh_deg[2]) * (((muDoubleScalarCos(qdh_deg[1]) *
    ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0)
     - b_mpower(-dqdh_deg[0]) * 0.15) + muDoubleScalarSin(qdh_deg[1]) * -9.81) -
    b_mpower(w2y) * 0.59) - b_mpower(dqdh_deg[1]) * 0.59) + muDoubleScalarSin
       (qdh_deg[2]) * (((-muDoubleScalarSin(qdh_deg[1]) * ((-muDoubleScalarCos
    (qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower
    (-dqdh_deg[0]) * 0.15) + muDoubleScalarCos(qdh_deg[1]) * -9.81) + ddqdh_deg
                        [1] * 0.59) + w2x * w2y * 0.59)) - b_mpower(w3y) * 0.13)
     - b_mpower(w3z) * 0.13) + muDoubleScalarSin(qdh_deg[3]) *
    ((((((-muDoubleScalarSin(qdh_deg[0]) * 0.0 + muDoubleScalarCos(qdh_deg[0]) *
          0.0) + -ddqdh_deg[0] * 0.15) + dw2y * 0.59) - w2x * dqdh_deg[1] * 0.59)
      + dw3z * 0.13) + w3x * w3y * 0.13)) - dw4z * 0.64707) + w4y * w4x *
             0.64707) + muDoubleScalarCos(qdh_deg[4]) * (((((-muDoubleScalarSin
    (qdh_deg[2]) * (((muDoubleScalarCos(qdh_deg[1]) * ((-muDoubleScalarCos
    (qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0) - b_mpower
    (-dqdh_deg[0]) * 0.15) + muDoubleScalarSin(qdh_deg[1]) * -9.81) - b_mpower
                     (w2y) * 0.59) - b_mpower(dqdh_deg[1]) * 0.59) +
    muDoubleScalarCos(qdh_deg[2]) * (((-muDoubleScalarSin(qdh_deg[1]) *
    ((-muDoubleScalarCos(qdh_deg[0]) * 0.0 - muDoubleScalarSin(qdh_deg[0]) * 0.0)
     - b_mpower(-dqdh_deg[0]) * 0.15) + muDoubleScalarCos(qdh_deg[1]) * -9.81) +
    ddqdh_deg[1] * 0.59) + w2x * w2y * 0.59)) - dw3y * 0.13) + w3x * w3z * 0.13)
              - b_mpower(w4z) * 0.64707) - b_mpower(w4x) * 0.64707)) - b_mpower
           (w6x) * 0.095) - b_mpower(w6y) * 0.095;

  /* ************************************************************************************************************************ */
  /*  Raggruppamento della variabili in uscita */
  /* ************************************************************************************************************************ */
  w[0] = 0.0;
  w[3] = w2x;
  w[6] = w3x;
  w[9] = w4x;
  w[12] = w5x;
  w[15] = w6x;
  w[1] = -dqdh_deg[0];
  w[4] = w2y;
  w[7] = w3y;
  w[10] = w4y;
  w[13] = w5y;
  w[16] = w6y;
  w[2] = 0.0;
  w[5] = dqdh_deg[1];
  w[8] = w3z;
  w[11] = w4z;
  w[14] = -muDoubleScalarSin(qdh_deg[4]) * (-muDoubleScalarCos(qdh_deg[3]) *
    dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1]) + muDoubleScalarSin
    (qdh_deg[3]) * (-dqdh_deg[1] - dqdh_deg[2])) + muDoubleScalarCos(qdh_deg[4])
    * (-dqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1]) + dqdh_deg[3]);
  w[17] = w6z;
  dw[0] = 0.0;
  dw[3] = muDoubleScalarCos(qdh_deg[1]) * dqdh_deg[1] * -dqdh_deg[0] -
    muDoubleScalarSin(qdh_deg[1]) * ddqdh_deg[0];
  dw[6] = ((dqdh_deg[1] * -dqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg
             [1]) - ddqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1])) +
           muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2y) -
    muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2x;
  dw[9] = dw4x;
  dw[12] = muDoubleScalarCos(qdh_deg[4]) * ((muDoubleScalarCos(qdh_deg[3]) *
    ((((dqdh_deg[1] * -dqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1])
        - ddqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1])) +
       muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2y) - muDoubleScalarSin
      (qdh_deg[2]) * dqdh_deg[2] * w2x) + dqdh_deg[3] * w3y) + muDoubleScalarSin
    (qdh_deg[3]) * ((-ddqdh_deg[1] - ddqdh_deg[2]) - dqdh_deg[3] * w3x)) +
    dqdh_deg[4] * w4y) + muDoubleScalarSin(qdh_deg[4]) * (((((-dqdh_deg[1] *
    -dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1]) - ddqdh_deg[0] *
    muDoubleScalarCos(qdh_deg[2] + qdh_deg[1])) - muDoubleScalarSin(qdh_deg[2]) *
    dqdh_deg[2] * w2y) - muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2x) +
    ddqdh_deg[3]) - dqdh_deg[4] * w4x);
  dw[15] = dw6x;
  dw[1] = -ddqdh_deg[0];
  dw[4] = dw2y;
  dw[7] = dw3y;
  dw[10] = (((-dqdh_deg[1] * -dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] +
    qdh_deg[1]) - ddqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1])) -
             muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2y) -
            muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2x) + ddqdh_deg[3];
  dw[13] = (-muDoubleScalarSin(qdh_deg[3]) * ((((dqdh_deg[1] * -dqdh_deg[0] *
    muDoubleScalarCos(qdh_deg[2] + qdh_deg[1]) - ddqdh_deg[0] *
    muDoubleScalarSin(qdh_deg[2] + qdh_deg[1])) + muDoubleScalarCos(qdh_deg[2]) *
    dqdh_deg[2] * w2y) - muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2x) +
             dqdh_deg[3] * w3y) + muDoubleScalarCos(qdh_deg[3]) * ((-ddqdh_deg[1]
              - ddqdh_deg[2]) - dqdh_deg[3] * w3x)) - ddqdh_deg[4];
  dw[16] = dw6y;
  dw[2] = 0.0;
  dw[5] = ddqdh_deg[1];
  dw[8] = dw3z;
  dw[11] = dw4z;
  dw[14] = -muDoubleScalarSin(qdh_deg[4]) * ((muDoubleScalarCos(qdh_deg[3]) *
    ((((dqdh_deg[1] * -dqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] + qdh_deg[1])
        - ddqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1])) +
       muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2y) - muDoubleScalarSin
      (qdh_deg[2]) * dqdh_deg[2] * w2x) + dqdh_deg[3] * w3y) + muDoubleScalarSin
    (qdh_deg[3]) * ((-ddqdh_deg[1] - ddqdh_deg[2]) - dqdh_deg[3] * w3x)) +
    dqdh_deg[4] * w4y) + muDoubleScalarCos(qdh_deg[4]) * (((((-dqdh_deg[1] *
    -dqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1]) - ddqdh_deg[0] *
    muDoubleScalarCos(qdh_deg[2] + qdh_deg[1])) - muDoubleScalarSin(qdh_deg[2]) *
    dqdh_deg[2] * w2y) - muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2x) +
    ddqdh_deg[3]) - dqdh_deg[4] * w4x);
  dw[17] = (-muDoubleScalarSin(qdh_deg[4]) * ((muDoubleScalarCos(qdh_deg[3]) *
              ((((dqdh_deg[1] * -dqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] +
    qdh_deg[1]) - ddqdh_deg[0] * muDoubleScalarSin(qdh_deg[2] + qdh_deg[1])) +
                 muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2y) -
                muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2x) + dqdh_deg[3]
               * w3y) + muDoubleScalarSin(qdh_deg[3]) * ((-ddqdh_deg[1] -
    ddqdh_deg[2]) - dqdh_deg[3] * w3x)) + dqdh_deg[4] * w4y) + muDoubleScalarCos
            (qdh_deg[4]) * (((((-dqdh_deg[1] * -dqdh_deg[0] * muDoubleScalarSin
    (qdh_deg[2] + qdh_deg[1]) - ddqdh_deg[0] * muDoubleScalarCos(qdh_deg[2] +
    qdh_deg[1])) - muDoubleScalarSin(qdh_deg[2]) * dqdh_deg[2] * w2y) -
    muDoubleScalarCos(qdh_deg[2]) * dqdh_deg[2] * w2x) + ddqdh_deg[3]) -
             dqdh_deg[4] * w4x)) + ddqdh_deg[5];
  ddp[0] = ddp1x;
  ddp[3] = ddp2x;
  ddp[6] = ddp3x;
  ddp[9] = ddp4x;
  ddp[12] = ddp5x;
  ddp[15] = ddp6x;
  ddp[1] = -9.81;
  ddp[4] = ddp2y;
  ddp[7] = (((((-muDoubleScalarSin(qdh_deg[0]) * 0.0 + muDoubleScalarCos
                (qdh_deg[0]) * 0.0) + -ddqdh_deg[0] * 0.15) + dw2y * 0.59) - w2x
             * dqdh_deg[1] * 0.59) + dw3z * 0.13) + w3x * w3y * 0.13;
  ddp[10] = ddp4y;
  ddp[13] = ddp5y;
  ddp[16] = ddp6y;
  ddp[2] = (muDoubleScalarSin(qdh_deg[0]) * 0.0 - muDoubleScalarCos(qdh_deg[0]) *
            0.0) - -ddqdh_deg[0] * 0.15;
  ddp[5] = (((muDoubleScalarSin(qdh_deg[0]) * 0.0 - muDoubleScalarCos(qdh_deg[0])
              * 0.0) - -ddqdh_deg[0] * 0.15) - dw2y * 0.59) + w2x * dqdh_deg[1] *
    0.59;
  ddp[8] = ddp3z;
  ddp[11] = ddp4z;
  ddp[14] = ddp5z;
  ddp[17] = ddp6z;
}

/* End of code generation (ricforw.c) */
