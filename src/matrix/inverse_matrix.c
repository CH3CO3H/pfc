#include <stdlib.h>
#include "matrix.h"

pfc_matrix_t* pfc_inverse_matrix(pfc_matrix_t* j) {
	if (j->len==0) goto err1;
	pfc_matrix_t* v_j=malloc(sizeof(pfc_matrix_t));
	pfc_matrix_set_e(v_j);
	v_j->len=j->len;
	for (size_t i=0;i<j->len;i++)
		pfc_matrix_set_1(j, v_j, i);
	return v_j;

err1:
	perror("inverse zero length matrix.");
	return NULL;
}

