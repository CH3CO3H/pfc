#ifndef PFC_MATRIX_H
#define PFC_MATRIX_H

#include <stdio.h>
#include "g.h"

struct pfc_matrix {
	double m[2*PFC_MAX_N][2*PFC_MAX_N];
	size_t len;
	size_t nu_pq;
};
typedef struct pfc_matrix pfc_matrix;

extern pfc_matrix* pfc_inverse_matrix(pfc_matrix*);
extern void pfc_matrix_add(pfc_matrix* j, size_t r1, size_t r2, double k);
extern void pfc_matrix_swap(pfc_matrix* j, size_t r1, size_t r2);
extern void pfc_matrix_mult(pfc_matrix* j, size_t r, double k);
extern void pfc_matrix_set_e(pfc_matrix*);
extern void pfc_matrix_set_1(pfc_matrix* j, pfc_matrix* v_j, size_t r);

#endif
