#include <stdlib.h>
#include "matrix.h"

pfc_matrix* pfc_matrix_cmpy(pfc_matrix* jcb) {
	size_t n=jcb->len;
	pfc_matrix* ret=malloc(sizeof(pfc_matrix));
	ret->len=n;
	if (n==1) {
		ret->m[0][0]=1;
		return ret;
	}
	pfc_matrix* tmp=malloc(sizeof(pfc_matrix));
	tmp->len=n-1;
	for (size_t i=0;i<n;i++) {
		for (size_t j=0;j<n;j++) {
			for (size_t k=0;k<n-1;k++) {
				for (size_t t=0;t<n-1;t++) {
					tmp->m[k][t]=jcb->m[k>=i?k+1:k][t>=j?t+1:t];
				}
			}
			ret->m[j][i]=pfc_matrix_ret(tmp);
			if ((i+j)&1) ret->m[j][i]=-ret->m[j][i];
		}
	}
	return ret;
}
