#include <stdio.h>
#include "g.h"

#ifndef PFC_MATRIX_H
#define PFC_MATRIX_H

struct pfc_matrix {
	double m[2*PFC_MAX_N][2*PFC_MAX_N];
	size_t len;
	size_t nu_pq;
};
typedef struct pfc_matrix pfc_matrix;

extern pfc_matrix* pfc_matrix_inverse(pfc_matrix*);
extern pfc_matrix* pfc_matrix_cp(pfc_matrix*);
extern void pfc_swap_double(double* a, double* b);

#include "matrix/cmpy.h"
#include "matrix/row_ex.h"
// #include "matrix/lu.h"

#endif
