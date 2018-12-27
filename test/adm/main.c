#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "adm.h"

static void print_adm_matrix(pfc_adm_matrix* m);

int main(int argc, const char* argv[]) {
	if (argc!=2) {
		printf("usage: main <input file>");
		exit(1);
	}
	FILE* f=fopen(argv[1], "r");
	if (f==NULL) {
		perror("Open input file");
		return 1;
	}
	
	pfc_adm_matrix* m=pfc_mk_adm_matrix(pfc_mk_adm_graph(f));
	print_adm_matrix(m);

	return 0;
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

