#include <stdlib.h>
#include "matrix.h"
#include "solve.h"

void solve(pfc_adm_matrix* adm, FILE* f) {
	pfc_vector* ub;
	pfc_vector* dlt_ef;
	pfc_vector* ef;
	pfc_vector* pq;
	double dlt_ef_max;
	double epsn;
	double complex s_s;
	double complex s_ij[PFC_MAX_N][PFC_MAX_N];

	pfc_initial(&pq, &ef, f);
	dlt_ef=malloc(sizeof(pfc_vector));
	ub=malloc(sizeof(pfc_vector));
	memset(dlt_ef, 0, sizeof(pfc_vector));

	unsigned int cnt=0;
	do {
		pfc_get_new_ef(ef, dlt_ef);
		pfc_set_ub(pq, ub, ef, adm);
		pfc_matrix* jcb=pfc_mk_jcb(adm, ef);
		pfc_solve_func(ub, jcb, dlt_ef);
		dlt_ef_max=pfc_get_dlt_ef_max(dlt_ef);
		cnt++;
	} while (dlt_ef_max>epsn);
	s_s=pfc_cla_ss(adm, ef);
	pfc_cal_sij(adm, ef, s_ij);
	pfc_save_rlt(ef, s_s, s_ij);
}
