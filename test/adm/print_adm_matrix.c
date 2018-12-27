#include "adm.h"

void print_adm_matrix(pfc_adm_matrix* m) {
	printf(">>> adm matrix <<<\n");
	printf("matrix size: %zu\n", m->nu);
	for (size_t i=0;i<m->nu;i++) {
		for (size_t j=0;j<m->nu;j++) {
			printf("%.5lf + j%.5lf\t", creal(m->y[i][j]), cimag(m->y[i][j]));
		}
		putchar('\n');
	}
    printf(">>> adm matrix END <<<\n");
}