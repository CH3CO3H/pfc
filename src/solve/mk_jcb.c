#include <stdlib.h>
#include <string.h>
#include "solve.h"

pfc_matrix* pfc_mk_jcb(pfc_adm_matrix* adm, pfc_vector* ef) {
	size_t n=ef->len>>1;
	size_t n_pq=ef->nu_pq;
	pfc_matrix* jcb;
	jcb=malloc(sizeof(pfc_matrix));
	memset(jcb, 0, sizeof(pfc_matrix));
	jcb->len=(n-1)<<1;
	for (size_t i=0;i<n-1;i++) {
		double e_i, f_i;
		e_i=pfc_get_qe(ef, i);
		f_i=pfc_get_pf(ef, i);
		for (size_t j=0;j<n-1;j++) {
			if (i==j) continue;
			double b_ij, g_ij;
			b_ij=pfc_adm_get_b(adm, i, j);
			g_ij=pfc_adm_get_g(adm, i, j);
			pfc_jcb_set_h(jcb, i, j, -b_ij*e_i+g_ij*f_i);	//jcb->m[2*i][2*j]=-b_ij*e_i+g_ij*f_i;
			pfc_jcb_set_n(jcb, i, j, g_ij*e_i+b_ij*f_i);	//jcb->m[2*i][2*j+1]=g_ij*e_i+b_ij*f_i;
			if (i<n_pq) {
				pfc_jcb_set_j(jcb, i, j, -pfc_jcb_get_n(jcb, i, j));	//jcb->m[2*i+1][2*j]=-jcb->m[2*i][2*j+1];
				pfc_jcb_set_l(jcb, i, j, pfc_jcb_get_h(jcb, i, j));	//jcb->m[2*i+1][2*j+1]=jcb->m[2*i][2*j];
			} else {
				pfc_jcb_set_j(jcb, i, j, 0);	//jcb->m[2*i+1][2*j]=0;
				pfc_jcb_set_l(jcb, i, j, 0);	//jcb->m[2*i+1][2*j+1]=0;
			}
		}
		double g_ii, b_ii;
		b_ii=pfc_adm_get_b(adm, i, i);
		g_ii=pfc_adm_get_g(adm, i, i);
		double a_tmp=0, b_tmp=0;
		for (size_t j=0;j<n;j++) {
			double b_ij, g_ij;
			double e_j, f_j;
			b_ij=pfc_adm_get_b(adm, i, j);
			g_ij=pfc_adm_get_g(adm, i, j);
			e_j=pfc_get_qe(ef, j);
			f_j=pfc_get_pf(ef, j);
			a_tmp+=g_ij*e_j-b_ij*f_j;
			b_tmp+=g_ij*f_j+b_ij*e_j;
		}
		pfc_jcb_set_h(jcb, i, i, -b_ii*e_i+g_ii*f_i+b_tmp);	//jcb->m[2*i][2*i]=-b_ii*e_i+g_ii*f_i+b_tmp;
		pfc_jcb_set_n(jcb, i, i, g_ii*e_i+b_ii*f_i+a_tmp);	//jcb->m[2*i][2*i+1]=g_ii*e_i+b_ii*f_i+a_tmp;
		if (i<n_pq) {
			pfc_jcb_set_j(jcb, i, i, -g_ii*e_i-b_ii*f_i+a_tmp);	//jcb->m[2*i+1][2*i]=-g_ii*e_i-b_ii*f_i+g_ii*e_i-b_ii*f_i+b_tmp;
			pfc_jcb_set_l(jcb, i, i, -b_ii*e_i+g_ii*f_i-b_tmp);	//jcb->m[2*i+1][2*i+1]=-b_ii*e_i+g_ii*f_i-g_ii*f_i-b_ii*e_i-b_tmp;
		} else {
			pfc_jcb_set_j(jcb, i, i, 2*f_i);	//jcb->m[2*i+1][2*i]=2*f_i;
			pfc_jcb_set_l(jcb, i, i, 2*e_i);	//jcb->m[2*i+1][2*i+1]=2*e_i;
		}
	}
	return jcb;
}