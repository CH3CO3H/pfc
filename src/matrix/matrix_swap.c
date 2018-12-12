#include "matrix.h"

void pfc_matrix_swap(pfc_matrix* j, size_t r1, size_t r2) {
	for (size_t i=0;i<j->len;i++)
		pfc_swap_double(&(j->m[r1][i]), &(j->m[r2][i]));
}

