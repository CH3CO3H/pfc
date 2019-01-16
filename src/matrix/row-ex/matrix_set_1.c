#include <math.h>
#include "matrix.h"

void pfc_matrix_set_1(pfc_matrix* j, pfc_matrix* v_j, size_t r) {
	//printf("set matrix[%zd][%zd] to 1.\n", r, r);
	size_t not_zero_r;
	for (not_zero_r=r;not_zero_r<j->len;not_zero_r++) {
		if (j->m[not_zero_r][r]) break;
	}
	if (not_zero_r!=r) {
		pfc_matrix_swap(j, r, not_zero_r);
		pfc_matrix_swap(v_j, r, not_zero_r);
	}
	if (fabs(j->m[r][r]-1)>0.000001) {
		double k=1.0/j->m[r][r];
		pfc_matrix_row_mult(j, r, k);
		pfc_matrix_row_mult(v_j, r, k);
	}
	for (size_t i=0;i<j->len;i++) {
		if (i==r) continue;
		if (j->m[i][r]) {
			double k=-1*j->m[i][r];
			pfc_matrix_add(j, i, r, k);
			pfc_matrix_add(v_j, i, r, k);
		}
	}
}
