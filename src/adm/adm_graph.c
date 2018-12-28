#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "adm.h"

pfc_adm_graph* pfc_mk_adm_graph(FILE* f) {
	int k;
	pfc_adm_graph* g=malloc(sizeof(pfc_adm_graph));
	memset(g->a, 0, PFC_MAX_N*sizeof(pfc_adm_node*));
	size_t nu, edge;
	k=fscanf(f, "%zd%zd\n", &nu, &edge);
	printf("nodes: %zd, branches: %zd\n", nu, edge);
	if (k!=2) goto err_scanf;
	if (!nu || !edge) goto err_0node;
	g->nu=nu;
	for (size_t i=0;i<edge;++i) {
		size_t ni, nj;
		double r, x;
		k=fscanf(f, "| %*u | %zd | %zd | %lf | %lf | %*f |\n", &ni, &nj, &r, &x);
		if (k!=4) goto err_scanf;
		double complex z=r+x*I;
		if (ni>nj) pfc_swap_s(&ni, &nj);
		pfc_adm_graph_add(g, ni, nj, 1/z);
	}
	return g;
err_0node:
	perror("0 node or branch. check input file");
	exit(1);
err_scanf:
	perror("Wrong input file fomat.");
	fprintf(stderr, "match %d\n", k);
	exit(1);
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
	if (ni>nj) pfc_swap_s(&ni, &nj);
	pfc_adm_node* t=g->a[ni];
	while (t!=NULL) {
		if (t->nu==nj) break;
		t=t->next;
	}
	if (t==NULL)
		return 0;
	return t->y;
}

