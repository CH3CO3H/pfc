#include "solve.h"

double complex pfc_cal_ss(pfc_adm_matrix* adm, pfc_vector* ef) {
	size_t n=ef->len;
	double i_sr=0, i_si=0;
	double e_s=pfc_get_qe(ef, n-1);
	double f_s=pfc_get_pf(ef, n-2);
	for (size_t i=0;i<n;i++) {
		double g_sj=pfc_get_g(adm, n-1, i);
		double b_sj=pfc_get_b(adm, n-1, i);
		double e_j=pfc_get_e(ef, i);
		double f_j=pfc_get_f(ef, i);
		i_sr+=g_sj*e_j-b_sj*f_j;
		i_si-=g_sj*f_j+b_sj*e_j;
	}
	return e_s*i_sr-f_s*i_si+I*(f_s*i_sr+e_s*i_si);
}
