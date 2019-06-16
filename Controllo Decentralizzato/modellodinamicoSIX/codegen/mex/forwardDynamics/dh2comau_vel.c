/*
 * dh2comau_vel.c
 *
 * Code generation for function 'dh2comau_vel'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "dh2comau_vel.h"

/* Function Definitions */
void dh2comau_vel(const real_T dqdh[8], real_T dqcomau[6])
{
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
  dqcomau[0] = -dqdh[0];
  dqcomau[1] = dqdh[1];
  dqcomau[2] = -dqdh[2];
  dqcomau[3] = -dqdh[3];
  dqcomau[4] = dqdh[4];
  dqcomau[5] = -dqdh[5];

  /*  dqdh(1) = -dqcomau(1); */
  /*  dqdh(2) =  dqcomau(2); */
  /*  dqdh(3) = -dqcomau(3); */
  /*  dqdh(4) = -dqcomau(4); */
  /*  dqdh(5) =  dqcomau(5); */
  /*  dqdh(6) = -dqcomau(6); */
}

/* End of code generation (dh2comau_vel.c) */
