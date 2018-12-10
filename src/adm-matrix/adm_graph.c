#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "adm_graph.h"

pfc_adm_graph* pfc_mk_adm_graph(FILE* f) {
	pfc_adm_graph* g=malloc(sizeof(pfc_adm_graph));
	memset(g->a, 0, PFC_MAX_N*sizeof(pfc_adm_node*));
	size_t nu, edge;
	fscanf(f, "%zd%zd", &nu, &edge);
	if (!nu) {
		perror("0 node. check input file");
		exit(1);
	}
	g->nu=nu;
	for (size_t i=0;i<edge;++i) {
		size_t ni, nj;
		double yr, yi;
		fscanf(f, "%zd%zd%lf %lf", &ni, &nj, &yr, &yi);
		double complex y=yr+yi*I;
		if (pfc_adm_graph_add(g, ni, nj, y))
			printf("add adm succeed. %zd->%zd: %lf+i*%lf\n", ni, nj, yr, yi);
	}
	return g;
}

bool pfc_adm_graph_add(pfc_adm_graph* g, size_t ni, size_t nj, double complex y) {
	if (g==NULL) {
		perror("add to NULL admittance graph");
		return false;
	}
	return pfc_adm_graph_add_edge(&(g->a[ni]), nj, y);
}

bool pfc_adm_graph_add_edge(pfc_adm_node** e, size_t nj, double complex y) {
	if (*e!=NULL)
		return pfc_adm_graph_add_edge(&((*e)->next), nj, y);
	*e=malloc(sizeof(pfc_adm_node));
	(*e)->nu=nj;
	(*e)->y=y;
	(*e)->next=NULL;
	return true;
}

double complex pfc_adm_graph_get(pfc_adm_graph* g, size_t ni, size_t nj) {
	if (ni>nj) swap(&ni, &nj);
	pfc_adm_node* t=g->a[ni];
	while (t!=NULL) {
		if (t->nu==nj) break;
		t=t->next;
	}
	if (t==NULL)
		return 0;
	return t->y;
}

