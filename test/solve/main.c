#include "stdlib.h"
#include "solve.h"

static void print_rlt(pfc_adm_graph*);

int main(int argc, const char* argv[]) {
	if (argc!=2) goto err_arg;
	FILE* f=fopen(argv[1], "r");
	if (!f) goto err_open_file;
	pfc_adm_graph* ag=pfc_mk_adm_graph(f);
	pfc_solve(ag, f);
	print_rlt(ag);
	free(ag);
	return 0;
err_arg:
	fprintf(stderr, "usage: main <graph_input> <solve_input>\n");
	exit(1);
err_open_file:
	perror("Open input file.");
	exit(1);
}

void print_rlt(pfc_adm_graph* g) {
	pfc_adm_node* nd;
	size_t n=g->nu;
	for (size_t i=0;i<n;i++) {
		nd=g->a[i];
		for (;nd;) {
			printf("S_ij_[%zd->%zd]: %lf + j%lf\n", i, nd->nu, creal(nd->s), cimag(nd->s));
			nd=nd->next;
		}
	}
}
