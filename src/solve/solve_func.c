#include "solve.h"

void pfc_solve_func(pfc_vector* ub, pfc_matrix* jcb, pfc_vector* dlt_ef) {
	pfc_matrix* jcb_inv=pfc_inverse_matrix(jcb);
	size_t len=ub->len;
	memset(dlt_ef, 0, sizeof(pfc_vector));
	for (size_t i=0;i<len;i++) {
		for (size_t j=0;j<len;j++) {
			dlt_ef->a[i]+=jcb_inv->m[i][j]*ub->a[i];
		}
	}
}
