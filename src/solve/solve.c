#include "matrix.h"
#include "solve.h"

void solve(matrix* adm, FILE* f) {
	pfc_vector_t* ub;
	pfc_vector_t* dlt_ef;
	pfc_vector_t* ef;
	pfc_vector_t* pq;
	size_t nu_all;
	size_t nu_pq;
	size_t nu_pv;
	double e_s;
	double f_s;
	double dlt_ef_max;
	fscanf(f, "%uz%uz", &nu_all, &nu_pq);
	fscanf(f, "%lf%lf", &e_s, &f_s);
	nu_pv=nu_all-nu_pq;
	pfc_initial(pfc_ef, e_s, f_s);
	do {
		pfc_set_ub(ub, ef, adm);
		pfc_mk_jcb(pfc_adm_matrix* adm, pfc_vector* ef);
		dlt_ef=pfc_solve_func(pfc_vector* ub, pfc_matrix* jcb);
		pfc_
	} while (dlt_ef_max>epsn);
