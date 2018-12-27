#include <stdio.h>
#include <stdbool.h>
#include <complex.h>
#include "g.h"

#ifndef PFC_AMD_H
#define PFC_ADM_H

typedef struct pfc_adm_node pfc_adm_node;
struct pfc_adm_node {
	size_t nu;
	pfc_adm_node* next;
	double complex y;
	double complex s;
};

typedef struct pfc_adm_graph {
	pfc_adm_node* a[PFC_MAX_N];
	size_t nu;
} pfc_adm_graph;

extern bool pfc_adm_graph_add(pfc_adm_graph* g, size_t ni, size_t nj, double complex y);
extern pfc_adm_graph* pfc_mk_adm_graph(FILE* f);
extern bool pfc_adm_graph_add_edge(pfc_adm_node** e, size_t nj, double complex y);
extern double complex pfc_adm_graph_get(pfc_adm_graph* g, size_t ni, size_t nj);
extern void pfc_swap_s(size_t* a, size_t* b);
extern bool pfc_has_branch(pfc_adm_graph* g, size_t i, size_t j);
extern bool pfc_set_sij(pfc_adm_graph* g, size_t i, size_t j, double complex s);
// extern double pfc_adm_get_graph_g(pfc_adm_graph* ag, size_t i, size_t j);
// extern double pfc_adm_get_graph_b(pfc_adm_graph* ag, size_t i, size_t j);

struct pfc_adm_matrix {
	double complex y[PFC_MAX_N][PFC_MAX_N];
	size_t nu;
};
typedef struct pfc_adm_matrix pfc_adm_matrix;

extern pfc_adm_matrix* pfc_mk_adm_matrix(pfc_adm_graph* g);

#define pfc_adm_get_y(adm, i, j) (adm->y[i][j])
#define pfc_adm_get_b(adm, i, j) cimag(adm->y[i][j])
#define pfc_adm_get_g(adm, i, j) creal(adm->y[i][j])

#endif
