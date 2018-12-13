#include "solve.h"

void pfc_initial(pfc_vector** pq, pfc_vector** ef, FILE* f) {
	*pq=malloc(sizeof(pfc_vector));
	*ef=malloc(sizeof(pfc_vector));
	size_t nu_all, nu_pq;
	fscanf(f, "%zd%zd", &nu_all, &nu_pq);
	(*pq)->len=nu_all;
	(*ef)->len=nu_all;
	(*pq)->nu_pq=nu_pq;
	(*ef)->nu_pq=nu_pq;
	fscnaf(f, "%lf%lf", &((*ef)->a[nu_all-1]), &((*ef)->a[nu_all-2]));
	for (size_t i=0;i<nu_all-1;i++) {
		(*ef)->a[2*i]=0;
		(*ef)->a[2*i+1]=1.0;
		fscanf(f, "%lf%lf", &((*pq)->a[2*i]), &((*pq)->a[2*i+1]));
	}
}
