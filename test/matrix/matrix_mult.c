#include <string.h>
#include <stdlib.h>
#include "matrix.h"

pfc_matrix* matrix_mult(pfc_matrix* jcb, pfc_matrix* jcb_inv) {
	pfc_matrix* r;
	r=malloc(sizeof(pfc_matrix));
	memset(r, 0, sizeof(pfc_matrix));
	size_t len=jcb->len;
	r->len=len;
	for (size_t i=0;i<len;i++) {
		for (size_t j=0;j<len;j++) {
			for (size_t k=0;k<len;k++) {
				r->m[i][j]+=jcb->m[i][k]*jcb_inv->m[k][j];
			}
		}
	}
	return r;
}
