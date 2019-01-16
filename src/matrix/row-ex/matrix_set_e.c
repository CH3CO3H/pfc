#include <string.h>
#include "matrix.h"

void pfc_matrix_set_e(pfc_matrix* v, size_t n) {
	v->len=n;
	for (size_t i=0;i<n;i++) {
		for (size_t j=0;j<n;j++) {
			v->m[i][j]=0;
		}
	}
	for (size_t i=0;i<n;i++)
		v->m[i][i]=1.0;
}

