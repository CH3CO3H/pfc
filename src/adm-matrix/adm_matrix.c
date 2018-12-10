#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include "adm_graph.h"
#include "adm_matrix.h"
#include "g.h"

pfc_adm_matrix* pfc_mk_adm_matrix(pfc_adm_graph* g) {
	printf("ready to make adm matrix.\n");
	printf("graph size: %zd.\n", g->nu);
	pfc_adm_matrix* m=malloc(sizeof(pfc_adm_matrix));
	m->nu=g->nu;
	memset(m->y, 0, PFC_MAX_N*PFC_MAX_N*sizeof(double complex));
	for (size_t i=0;i<g->nu;i++) {
		if (g->a[i]==NULL) continue;
		printf("add adm from node %zd:\n", i);
		for (pfc_adm_node* l=g->a[i];l!=NULL;l=l->next) {
			size_t j=l->nu;
			m->y[i][i]+=l->y;
			m->y[j][j]+=l->y;
			m->y[j][i]=m->y[i][j]=-creal(l->y)-I*cimag(l->y);
		}
	}
	return m;
}
