#include <stdio.h>
#include <stdbool.h>
#include <complex.h>
#include "g.h"

#ifndef PFC_ADM_GRAPH_H
#define PFC_ADM_GRAPH_H

typedef struct pfc_adm_node pfc_adm_node;
struct pfc_adm_node {
	size_t nu;
	pfc_adm_node* next;
	double complex y;
};

typedef struct pfc_adm_graph {
	pfc_adm_node* a[PFC_MAX_N];
	size_t nu;
} pfc_adm_graph;

extern bool pfc_adm_graph_add(pfc_adm_graph* g, size_t ni, size_t nj, double complex y);
extern pfc_adm_graph* pfc_mk_adm_graph(FILE* f);
extern bool pfc_adm_graph_add_edge(pfc_adm_node** e, size_t nj, double complex y);
extern double complex pfc_adm_graph_get(pfc_adm_graph* g, size_t ni, size_t nj);
extern void swap(size_t* a, size_t* b);

#endif
