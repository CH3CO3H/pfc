#include "solve.h"

double complex pfc_cal_ss(pfc_adm_matrix* adm, pfc_vector* ef) {
	size_t n=ef->len>>1;
	double complex i_s=0;
	for (size_t i=0;i<n;i++) {
		double complex u_i=pfc_get_qe(ef, i)+I*pfc_get_pf(ef, i);
		i_s+=pfc_adm_get_y(adm, n-1, i)*u_i;
	}
	double complex u_n=pfc_get_qe(ef, n-1)+I*pfc_get_pf(ef, n-1);
	return conj(i_s)*u_n;
}
