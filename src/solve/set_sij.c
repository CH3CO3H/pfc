#include "solve.h"

bool pfc_set_sij(pfc_adm_graph* g, size_t i, size_t j, double complex s) {
	pfc_adm_node* nd=g->a[i];
	for (;nd;) {
		if (nd->nu==j) {
			nd->s=s;
			return true;
		}
		nd=nd->next;
	}
	return false;
}
