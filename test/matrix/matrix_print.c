#include "matrix.h"

void matrix_print(const char s[], pfc_matrix* j) {
	printf(">>> matrix %s <<<\n", s);
	size_t n=j->len;
	printf("matrix size: %zd\n", n);
	for (size_t i=0;i<n;i++) {
		for (size_t k=0;k<n;k++)
			printf("%lf\t", j->m[i][k]);
		putchar('\n');
	}
	printf(">>> matrix %s END <<<\n", s);
}
