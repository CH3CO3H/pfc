#include "matrix.h"

void pfc_matrix_add(pfc_matrix_t* j, size_t r1, size_t r2, double k) {
	for (size_t i=0;i<j->len;i++)
		j->m[r1][i]+=k*j->m[r2][i];
}

