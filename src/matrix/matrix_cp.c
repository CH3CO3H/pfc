#include <stdlib.h>
#include "matrix.h"

pfc_matrix* pfc_matrix_cp(pfc_matrix* jcb) {
	pfc_matrix* ret=malloc(sizeof(pfc_matrix));
	size_t len=jcb->len;
	for (size_t i=0;i<len;i++) {
		for (size_t j=0;j<len;j++) {
			ret->m[i][j]=jcb->m[i][j];
		}
	}
	ret->len=len;
	return ret;
}
