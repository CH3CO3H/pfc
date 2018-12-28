#include <stdlib.h>
#include "solve.h"

void pfc_initial(pfc_vector** pq, pfc_vector** ef, FILE* f) {
	*pq=malloc(sizeof(pfc_vector));
	*ef=malloc(sizeof(pfc_vector));
	size_t nu_all, nu_pq;
	fscanf(f, "%zd%zd\n", &nu_all, &nu_pq);
	if (!nu_all || nu_pq>nu_all) goto err_no;
	(*pq)->len=2*nu_all;
	(*ef)->len=2*nu_all;
	(*pq)->nu_pq=nu_pq;
	(*ef)->nu_pq=nu_pq;
	fscanf(f, "%lf%lf\n", &((*ef)->a[(nu_all<<1)-1]), &((*ef)->a[(nu_all<<1)-2]));
	for (size_t i=0;i<nu_pq;i++) {
		pfc_set_pf((*ef), i, 0);
		pfc_set_qe((*ef), i, 1.0);
		double p_g, q_g, p_l, q_l;
		int k=0;
		k=fscanf(f, "| %*u | %lf | %lf | %lf | %lf |\n", &p_g, &q_g, &p_l, &q_l);
		if (k!=4) goto err_scanf;
		pfc_set_pf((*pq), i, p_g-p_l);
		pfc_set_qe((*pq), i, q_g-q_l);
	}
	for (size_t i=nu_pq;i<nu_all-1;i++) {
		pfc_set_pf((*ef), i, 0);
		pfc_set_qe((*ef), i, 1.0);
		double p_g, p_l, u;
		int k=0;
		k=fscanf(f, "| %*u | %lf | %lf | %lf | %*f |\n", &p_g, &u, &p_l);
		if (k!=3) goto err_scanf;
		pfc_set_pf((*pq), i, p_g-p_l);
		pfc_set_qe((*pq), i, u*u);
	}
	return;
err_no:
	fprintf(stderr, "wrong number of nodes in solve input file.\n");
	exit(1);
err_scanf:
	fprintf(stderr, "scanf P, Q, U error.");
	exit(1);
}
