#include "solve.h"

void pfc_solve_func(pfc_vector* ub, pfc_matrix* jcb, pfc_vector* dlt_ef) {
	pfc_matrix* jcb_inv=pfc_inverse_matrix(jcb);

