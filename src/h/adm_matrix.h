#include <stdio.h>
#include <complex.h>
#include "g.h"

#ifndef PFC_AMD_MATRIX_H
#define PFC_ADM_MATRIX_H

typedef struct {
	double complex y[PFC_MAX_N][PFC_MAX_N];
	size_t nu;
} pfc_adm_matrix;

extern pfc_adm_matrix* pfc_mk_adm_matrix(pfc_adm_graph* g);

#endif
