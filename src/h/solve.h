#include <stdio.h>
#include <complex.h>

#ifndef SOLVE_H
#define SOLVE_H

struct pfc_vector {
	double a[PFC_MAX_N*2];
	size_t len;
};
typedef struct pfc_vector pfc_vector;

extern void pfc_initial(pfc_vector*, FILE* f);
extern double pfc_get_e(pfc_vector* ef, size_t i);
extern double pfc_get_p(size_t i, pfc_vector*);

#endif
