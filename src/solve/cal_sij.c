#include "solve.h"

void pfc_cal_sij(pfc_adm_graph* ag, pfc_vector* ef) {
	size_t n=ag->nu;
	for (size_t i=0;i<n-1;i++) {
		double complex u_i=pfc_get_qe(ef, i) + I*pfc_get_pf(ef, i);
		for (size_t j=i+1;j<n;j++) {
			if (!pfc_has_branch(ag, i, j)) continue;
			double complex u_j=pfc_get_qe(ef, j) + I*pfc_get_pf(ef, j);
			double complex y_ij=pfc_adm_graph_get(ag, i, j);
			double complex s_ij=u_i*conj((u_i-u_j)*y_ij);
			pfc_set_sij(ag, i, j, s_ij);
		}
	}
}
