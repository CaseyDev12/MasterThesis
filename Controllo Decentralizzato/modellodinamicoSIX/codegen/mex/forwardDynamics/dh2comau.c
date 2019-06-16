/*
 * dh2comau.c
 *
 * Code generation for function 'dh2comau'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "dh2comau.h"

/* Function Definitions */
void dh2comau(const real_T qdh[8], real_T qcomau[6])
{
  /*  Converte le posizioni dei giunti dalla convenzione DH(gradi) alla */
  /*  convenzione Comau(gradi) */
  /*   */
  /*  Ingressi: */
  /*     qdh   : vettore 6x1 delle posizioni in convenzione DH in gradi  */
  /*  Uscite: */
  /*     qcomau: vettore 6x1 delle posizioni in convenzione COMAU in gradi */
  /*  Note: */
  /*    le unita' di misura devono essere necessariamente in gradi */
  /*    IL FILE E' STATO CREATO DA MARINO */
  qcomau[0] = -qdh[0];
  qcomau[1] = qdh[1] + 90.0;
  qcomau[2] = -qdh[2] - 90.0;
  qcomau[3] = -qdh[3];
  qcomau[4] = qdh[4];
  qcomau[5] = -qdh[5] + 180.0;
}

/* End of code generation (dh2comau.c) */
