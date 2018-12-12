#include "matrix.h"

void print_matrix(pfc_matrix* j) {
	for (size_t i=0;i<j->len;i++) {
		for (size_t k=0;k<j->len;k++)
			printf("%lf\t", j->m[i][k]);
		putchar('\n');
	}
}

