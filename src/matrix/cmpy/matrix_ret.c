#include <stdlib.h>
#include "matrix.h"

double pfc_matrix_ret(pfc_matrix* jc) {
	size_t n=jc->len;
	if (n==1) return jc->m[0][0];
	double ret=0;
	pfc_matrix* chl=malloc(sizeof(pfc_matrix));
	chl->len=n-1;
	for (size_t i=0;i<n;i++) {
		for (size_t j=0;j<n-1;j++) {
			for (size_t k=0;k<n-1;k++) {
				chl->m[j][k]=jc->m[j+1][k>=i?k+1:k];
			}
		}
		double tmp=pfc_matrix_ret(chl);
		if (i&1) ret-=jc->m[0][i]*tmp;
		else ret+=jc->m[0][i]*tmp;
	}
	free(chl);
	return ret;
}
