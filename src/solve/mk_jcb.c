#include "solve.h"

pfc_matrix* pfc_mk_jcb(pfc_vector* ef, pfc_adm_matrix* adm) {
	pfc_matrix* jcb;
	jcb=malloc(sizeof(pfc_matrix));
	for (size_t i=0;i<n-1;i++) {
		double e_i, f_i;
		//get e_i, f_i
		for (size_t j=0;j<n-1;j++) {
			if (i==j) continue;
			double b_ij;
			double g_ij;
			jcb[2*i][2*j]=-b_ij*e_i+g_ij*f_i;
			jcb[2*i][2*j+1]=g_ij*e_i+b_ij*f_i;
			if (i<nu_pq) {
				jcb[2*i+1][2*j]=-jcb[2*i][2*j+1];
				jcb[2*i+1][2*j+1]=jcb[2*i][2*j];
			} else {
				jcb[2*i+1][2*j]=0;
				jcb[2*i+1][2*j+1]=0;
			}
		}
		jcb[2*i][2*i]=//H_ii
		jcb[2*i][2*i+1]=//N_ii
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