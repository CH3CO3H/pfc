#include "matrix.h"

void pfc_matrix_mult(pfc_matrix_t* j, size_t r, double k) {
	for (size_t i=0;i<j->len;i++)
		j->m[r][i]*=k;
}

