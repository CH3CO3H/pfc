#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include "adm.h"
#include "g.h"

pfc_adm_matrix* pfc_mk_adm_matrix(pfc_branch* br[PFC_MAX_BRANCH], pfc_sysinfo* sys, pfc_bus* bs[PFC_MAX_N]) {
	size_t n=sys->br;
	pfc_adm_matrix* m=malloc(sizeof(pfc_adm_matrix));
	memset(m, 0, sizeof(pfc_adm_matrix));
	for (size_t i=0;i<n;i++) {
		size_t no1=br[i]->from;
		size_t no2=br[i]->to;
		size_t index1, index2;
		for (size_t j=0;j<n;j++) {
			if (bs[j]->no==no1) {
				index1=j;
				break;
			}
		}
		for (size_t j=0;j<n;j++) {
			if (bs[j]->no==no2) {
				index2=j;
				break;
			}
		}
		double r=br[i]->r;
		double x=br[i]->x;
		double b=br[i]->b;
		double complex y_ij=1/(r+I*x);
		double complex y_ii=0.5*b*I;
		(*m)[index1][index2] -= y_ij;
		(*m)[index2][index1] -= y_ij;
		(*m)[index1][index1] += y_ii+y_ij;
		(*m)[index2][index2] += y_ii+y_ij;
	}
	return m;
}
