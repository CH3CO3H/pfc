#include <stdlib.h>
#include "matrix.h"

pfc_matrix* pfc_matrix_inverse(pfc_matrix* jcb) {
	double ret=pfc_matrix_ret(jcb);
	if (ret-0.0<1e-6) goto err_0ret;
	size_t n=jcb->len;
	pfc_matrix* v_j=pfc_matrix_cmpy(jcb);
	for (size_t i=0;i<n;i++) {
		for (size_t j=0;j<n;j++) {
			v_j->m[i][j]/=ret;
		}
	}
	return v_j;
err_0ret:
	fprintf(stderr, "matrix ret 0, exit.\n");
	exit(1);
}
