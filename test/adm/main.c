#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "adm.h"

static void print_adm_matrix(pfc_adm_matrix* m);
static void print_adm_graph(pfc_adm_graph*);

int main(int argc, const char* argv[]) {
	if (argc!=2) goto err_arg;
	FILE* f=fopen(argv[1], "r");
	if (!f) goto err_fopen;
	pfc_adm_graph* ag=pfc_mk_adm_graph(f);
	print_adm_graph(ag);
	pfc_adm_matrix* m=pfc_mk_adm_matrix(ag);
	print_adm_matrix(m);

	return 0;
err_arg:
	printf("usage: main <input file>");
	exit(1);
err_fopen:
	perror("Open input file");
	exit(1);
}

void print_adm_graph(pfc_adm_graph* ag) {
	size_t n=ag->nu;
	for (size_t i=0;i<n;i++) {
		pfc_adm_node* nd=ag->a[i];
		for (;nd;nd=nd->next) {
			printf("%zu -> %zu: %lf + j%lf\n", i, nd->nu, creal(nd->y), cimag(nd->y));
		}
	}
}

void print_adm_matrix(pfc_adm_matrix* m) {
	printf("ready to print matrix:\n");
	printf("matrix size: %zd\n", m->nu);
	for (size_t i=0;i<m->nu;i++) {
		for (size_t j=0;j<=m->nu;j++) {
			printf("%.5lf + j%.5lf\t", creal(m->y[i][j]), cimag(m->y[i][j]));
		}
		putchar('\n');
	}
}

