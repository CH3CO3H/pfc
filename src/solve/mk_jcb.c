#include "solve.h"

pfc_matrix* pfc_mk_jcb(pfc_adm_matrix* adm, pfc_vector* ef) {
	size_t n=ef->len;
	size_t n_pq=ef->nu_pq;
	pfc_matrix* jcb;
	jcb=malloc(sizeof(pfc_matrix));
	for (size_t i=0;i<n-1;i++) {
		double e_i, f_i;
		e_i=pfc_get_qe(ef, i);
		f_i=pfc_get_pf(ef, i);
		for (size_t j=0;j<n-1;j++) {
			if (i==j) continue;
			double b_ij;
			double g_ij;
			//get b_ij, g_ij
			jcb->m[2*i][2*j]=-b_ij*e_i+g_ij*f_i;
			jcb->m[2*i][2*j+1]=g_ij*e_i+b_ij*f_i;
			if (i<n_pq) {
				jcb->m[2*i+1][2*j]=-jcb->m[2*i][2*j+1];
				jcb->m[2*i+1][2*j+1]=jcb->m[2*i][2*j];
			} else {
				jcb->m[2*i+1][2*j]=0;
				jcb->m[2*i+1][2*j+1]=0;
			}
		}
		jcb->m[2*i][2*i]=//H_ii
		jcb->m[2*i][2*i+1]=//N_ii
		if (i<nu_pq) {
			jcb[2*i+1][2*j]=//J_ii
			jcb[2*i+1][2*j+1]=//L_ii
		} else {
			jcb[2*i+1][2*j]=//R_ii
			jcb[2*i+1][2*j+1]=//S_ii
		}
	}
	return jcb;
}