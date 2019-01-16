#include <stdlib.h>
#include "matrix.h"

pfc_matrix* pfc_matrix_inverse(pfc_matrix* j) {
	size_t n=j->len;
	if (!n) goto err1;
	pfc_matrix* v_j=malloc(sizeof(pfc_matrix));
	pfc_matrix* j_cp=pfc_matrix_cp(j);
	pfc_matrix_set_e(v_j, n);
	v_j->len=j->len;
	for (size_t i=0;i<j->len;i++)
		pfc_matrix_set_1(j_cp, v_j, i);
	return v_j;

err1:
	fprintf(stderr, "inverse zero length matrix.");
	exit(1);
}

