#include "solve.h"
#include "matrix.h"

void pfc_set_ub(pfc_vector* ub, pfc_vector* ef, matrix* adm) {
    for (size_t i=0;i<n-1;i++) {
			double p_i=pfc_get_pf(pq, i);
			double q_i=pfc_get_qe(pq, i);
			double e_i=pfc_get_qe(ef, i);
			double p_t=0, q_t=0;
			for (size_t j=0;j<n-1;j++) {
				double e_j=pfc_get_qe(ef, j);
				double f_j=pfc_get_pf(ef, j);
				double g_ij=pfc_get_g(adm, i, j);
				double b_ij=pfc_get_b(adm, i, j);
				p_t += e_i*(g_ij*e_j-b_ij*f_j) + f_i*(g_ij*f_j+b_ij*e_j);
				q_t += f_i*(g_ij*e_j-b_ij*f_j) - e_i*(g_ij*f_j_b_ij*e_j);
			}
			pfc_set_pf(ub, i, p_i-p_t);
			pfc_set_qe(ub, i, q_i-q_t);
		}
}