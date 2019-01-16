#include <string.h>
#include <stdlib.h>
#include "solve.h"

extern void print_matrix(const char[], pfc_matrix*);	//debug

void pfc_solve_func(pfc_vector* ub, pfc_matrix* jcb, pfc_vector* dlt_ef) {
	pfc_matrix* jcb_inv=pfc_matrix_inverse(jcb);
	/* print_matrix("jcb inverse", jcb_inv);	//debug */
	size_t n=ub->len;
	for (size_t i=0;i<n;i++) {
		dlt_ef->a[i]=0;
		for (size_t j=0;j<n;j++) {
			dlt_ef->a[i]+=jcb_inv->m[i][j]*ub->a[j];
		}
	}
	free(jcb); jcb=0;
	free(jcb_inv); jcb_inv=0;
}
