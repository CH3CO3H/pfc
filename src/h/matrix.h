#ifndef PFC_MATRIX_H
#define PFC_MATRIX_H

#include <stdio.h>
#include "g.h"

struct matrix {
	double m[PFC_MAX_N][PFC_MAX_N];
	size_t len;
};
typedef struct matrix pfc_matrix_t;

extern pfc_matrix_t* inverse_matrix(pfc_matrix_t*);
extern void pfc_matrix_add(pfc_matrix_t* j, size_t r1, size_t r2, double k);
extern void pfc_matrix_swap(pfc_matrix_t* j, size_t r1, size_t r2);
extern void pfc_matrix_mult(pfc_matrix_t* j, size_t r, double k);
extern void pfc_matrix_set_e(pfc_matrix_t*);
extern void pfc_matrix_set_1(pfc_matrix_t* j, pfc_matrix_t* v_j, size_t r);

#endif
