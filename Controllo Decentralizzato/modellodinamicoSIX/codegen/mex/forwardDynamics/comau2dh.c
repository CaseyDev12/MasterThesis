/*
 * comau2dh.c
 *
 * Code generation for function 'comau2dh'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "comau2dh.h"

/* Function Definitions */
void comau2dh(const real_T qcomau[6], real_T qdh[6])
{
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
  qdh[0] = -qcomau[0];
  qdh[1] = qcomau[1] - 90.0;
  qdh[2] = -qcomau[2] - 90.0;
  qdh[3] = -qcomau[3];
  qdh[4] = qcomau[4];
  qdh[5] = -qcomau[5] + 180.0;
}

/* End of code generation (comau2dh.c) */
