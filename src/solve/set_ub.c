#include "solve.h"
#include "matrix.h"

void pfc_set_ub(pfc_vector* pq, pfc_vector* ub, pfc_vector* ef, pfc_adm_matrix* adm) {
	size_t nu_all, nu_pq;
	nu_all=ef->len>>1;
	nu_pq=ef->nu_pq;
	for (size_t i=0;i<nu_all-1;i++) {
		double p_i=pfc_get_pf(pq, i);
		double q_i=pfc_get_qe(pq, i);
		double e_i=pfc_get_qe(ef, i);
		double f_i=pfc_get_pf(ef, i);
		double p_tmp=0, q_tmp=0;
		for (size_t j=0;j<nu_all;j++) {
			double e_j=pfc_get_qe(ef, j);
			double f_j=pfc_get_pf(ef, j);
			double g_ij=pfc_adm_get_g(adm, i, j);
			double b_ij=pfc_adm_get_b(adm, i, j);
			p_tmp += e_i*(g_ij*e_j-b_ij*f_j) + f_i*(g_ij*f_j+b_ij*e_j);
			if (i<nu_pq)
			q_tmp += f_i*(g_ij*e_j-b_ij*f_j) - e_i*(g_ij*f_j+b_ij*e_j);
		}
		pfc_set_pf(ub, i, p_i-p_tmp);
		if (i<nu_pq)
			pfc_set_qe(ub, i, q_i-q_tmp);
		else {
			pfc_set_qe(ub, i, q_i-e_i*e_i-f_i*f_i);
		}
	}
}
