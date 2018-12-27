#include <stdlib.h>
#include "solve.h"

void pfc_initial(pfc_vector** pq, pfc_vector** ef, FILE* f) {
	*pq=malloc(sizeof(pfc_vector));
	*ef=malloc(sizeof(pfc_vector));
	size_t nu_all, nu_pq;
	fscanf(f, "%zd%zd", &nu_all, &nu_pq);
	if (!nu_all || nu_pq>nu_all) goto err_no;
	(*pq)->len=2*nu_all;
	(*ef)->len=2*nu_all;
	(*pq)->nu_pq=nu_pq;
	(*ef)->nu_pq=nu_pq;
	fscanf(f, "%lf%lf", &((*ef)->a[(nu_all<<1)-1]), &((*ef)->a[(nu_all<<1)-2]));
	for (size_t i=0;i<nu_all-1;i++) {
		(*ef)->a[2*i]=0;
		(*ef)->a[2*i+1]=1.0;
		fscanf(f, "%lf%lf", &((*pq)->a[2*i]), &((*pq)->a[2*i+1]));
	}
	return;
err_no:
	fprintf(stderr, "wrong number of nodes in solve input file.\n");
}
