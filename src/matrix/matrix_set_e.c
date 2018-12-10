#include <string.h>
#include "matrix.h"

void pfc_matrix_set_e(pfc_matrix_t* v) {
	memset(v, 0, PFC_MAX_N*PFC_MAX_N*sizeof(double));
	for (size_t i=0;i<PFC_MAX_N;i++)
		v->m[i][i]=1.0;
}

