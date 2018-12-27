#include "solve.h"

void print_vector(char s[], pfc_vector* v) {
	size_t n=v->len;
	printf(">>> vector %s <<<\n", s);
	for (size_t i=0;i<n;i++)
		printf("%zd: %lf\n", i, v->a[i]);
	printf(">>> %s END <<<\n", s);
}
