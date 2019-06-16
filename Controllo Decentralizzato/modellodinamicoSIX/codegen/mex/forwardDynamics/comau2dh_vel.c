/*
 * comau2dh_vel.c
 *
 * Code generation for function 'comau2dh_vel'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "comau2dh_vel.h"

/* Function Definitions */
void comau2dh_vel(const real_T dqcomau[6], real_T dqdh[6])
{
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
  dqdh[0] = -dqcomau[0];
  dqdh[1] = dqcomau[1];
  dqdh[2] = -dqcomau[2];
  dqdh[3] = -dqcomau[3];
  dqdh[4] = dqcomau[4];
  dqdh[5] = -dqcomau[5];
}

/* End of code generation (comau2dh_vel.c) */
