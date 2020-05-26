#include <stdio.h>
#include <complex.h>
#include "g.h"
#include "adm.h"
#include "matrix.h"

#ifndef SOLVE_H
#define SOLVE_H

extern void pfc_solve(pfc_adm_matrix* adm, pfc_sysinfo* sysinfo);
extern void pfc_solve_inl(pfc_vector** pq, pfc_vector** ef, FILE* f);
extern void pfc_set_ub(pfc_vector* pq, pfc_vector* ub, pfc_vector* ef,pfc_adm_matrix* adm);
extern pfc_matrix* pfc_mk_jcb(pfc_adm_matrix* adm, pfc_vector* ef);
extern void pfc_solve_func(pfc_vector* ub, pfc_matrix* jcb, pfc_vector* dlt_ef);
extern double pfc_get_dlt_ef_max(pfc_vector* dlt_ef);
extern void pfc_get_new_ef(pfc_vector* ef, pfc_vector* dlt_ef);
extern double complex pfc_cal_ss(pfc_adm_matrix*, pfc_vector* ef);
extern void pfc_cal_sij(pfc_adm_graph*, pfc_vector* ef);
//extern void pfc_save_rlt(pfc_vector* ef, double complex s_s, double complex s_ij[][]);

#define pfc_get_pf(pq, i) ((pq)->a[2*(i)])
#define pfc_get_qe(pq, i) ((pq)->a[2*(i)+1])
#define pfc_set_pf(pq, i, x) (pq)->a[2*(i)]=(x)
#define pfc_set_qe(pq, i, x) (pq)->a[2*(i)+1]=(x)

#define pfc_jcb_set_h(jcb, i, j, x) jcb->m[2*(i)][2*(j)]=(x)
#define pfc_jcb_set_n(jcb, i, j, x) jcb->m[2*(i)][2*(j)+1]=(x)
#define pfc_jcb_set_j(jcb, i, j, x) jcb->m[2*(i)+1][2*(j)]=(x)
#define pfc_jcb_set_l(jcb, i, j, x) jcb->m[2*(i)+1][2*(j)+1]=(x)
#define pfc_jcb_get_h(jcb, i, j) (jcb->m[2*(i)][2*(j)])
#define pfc_jcb_get_n(jcb, i, j) (jcb->m[2*(i)][2*(j)+1])

#endif
