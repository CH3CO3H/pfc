#include "adm.h"

bool pfc_has_branch(pfc_adm_graph* g, size_t i, size_t j) {
	pfc_adm_node* nd=g->a[i];
	for (;nd;) {
		if (nd->nu==j) return true;
		nd=nd->next;
	}
	return false;
}
