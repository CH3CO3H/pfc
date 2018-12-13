#include <stdio.h>
#include <complex.h>
#include "g.h"
#include "adm_matrix.h"
#include "matrix.h"

#ifndef SOLVE_H
#define SOLVE_H

struct pfc_vector {
	double a[PFC_MAX_N*2];
	size_t len;
	size_t nu_pq;
};
typedef struct pfc_vector pfc_vector;

extern void pfc_initial(pfc_vector** pq, pfc_vector** ef, FILE* f);
extern void pfc_set_ub(pfc_vector* pq, pfc_vector* ub, pfc_vector* ef,pfc_adm_matrix* adm);
extern pfc_matrix* pfc_mk_jcb(pfc_adm_matrix* adm, pfc_vector* ef);
extern void pfc_solve_func(pfc_vector* ub, pfc_matrix* jcb, pfc_vector* dlt_ef);
extern double pfc_get_dlt_ef_max(pfc_vector* dlt_ef);
extern void pfc_get_new_ef(pfc_vector* ef, pfc_vector* dlt_ef);
extern void pfc_cal_sij(pfc_adm_matrix* adm, pfc_vector* ef, double complex s_ij[][]);
extern void pfc_save_rlt(pfc_vector* ef, double complex s_s, double complex s_ij[][]);

extern double pfc_get_e(pfc_vector* ef, size_t i);
extern double pfc_get_p(size_t i, pfc_vector*);

#define pfc_get_pf(pq, i) (pq->a[2*i])
#define pfc_get_qe(pq, i) (pq->a[2*i+1])
#define pfc_set_pf(pq, i, x) pq->a[2*i]=x
#define pfc_set_qe(pq, i, x) pq->a[2*i+1]=x

#endif
