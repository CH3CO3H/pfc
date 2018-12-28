#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "solve.h"

extern void print_vector(char[], pfc_vector*);	//debug
extern void print_adm_matrix(pfc_adm_matrix*);	//debug
extern void print_matrix(const char[], pfc_matrix* j);	//debug

void pfc_solve(pfc_adm_graph* ag, FILE* f) {
	pfc_vector* ub;
	pfc_vector* dlt_ef;
	pfc_vector* ef;
	pfc_vector* pq;
	pfc_adm_matrix* adm=pfc_mk_adm_matrix(ag);
	/* print_adm_matrix(adm);	//debug */
	double dlt_ef_max;
	double complex s_s;

	pfc_initial(&pq, &ef, f);
	print_vector("power", pq);	//debug
	dlt_ef=malloc(sizeof(pfc_vector));
	ub=malloc(sizeof(pfc_vector));
	memset(dlt_ef, 0, sizeof(pfc_vector));
	memset(ub, 0, sizeof(pfc_vector));
	ub->len=dlt_ef->len=(ag->nu-1)<<1;

	unsigned int cnt=0;
	do {
		printf("iteration calculating time: %u\n", cnt+1);	//unnecessary
		pfc_get_new_ef(ef, dlt_ef);
		print_vector("voltage", ef);	//debug
		pfc_set_ub(pq, ub, ef, adm);
		print_vector("unbalance", ub);	//debug
		pfc_matrix* jcb=pfc_mk_jcb(adm, ef);
		/* print_matrix("matrix jcb", jcb);	//debug */
		pfc_solve_func(ub, jcb, dlt_ef);
		print_vector("dlt_ef", dlt_ef);	//debug
		dlt_ef_max=pfc_get_dlt_ef_max(dlt_ef);
		printf("dlt_ef_max: %lf\n", dlt_ef_max);
		cnt++;
		if (cnt>PFC_ITERATION_LIMITS) goto err_nc;
	} while (dlt_ef_max>PFC_PCN);
	printf("iteration count: %u\n", cnt);
	s_s=pfc_cal_ss(adm, ef);
	printf("S_s: %lf + j%lf\n", creal(s_s), cimag(s_s));
	pfc_cal_sij(ag, ef);
	// pfc_save_rlt(ef, s_s, s_ij);
	free(adm); adm=0;
	free(pq); pq=0;
	free(ef); ef=0;
	free(dlt_ef); dlt_ef=0;
	free(ub); ub=0;
	return;
err_nc:
	fprintf(stderr, "Too many iteration times, maybe not converge.\n");
	exit(1);
}
