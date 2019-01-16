#include <stdlib.h>
#include "matrix.h"

pfc_matrix* matrix_input(FILE* f) {
	pfc_matrix* j=malloc(sizeof(pfc_matrix));
	printf("reading matrix input file...\n");
	size_t n;
	fscanf(f, "%zu", &n);
	if (!n) goto err1;
	j->len=n;
	printf("matrix size: %zd\n", n);
	for (size_t i=0;i<n;i++)
		for (size_t k=0;k<n;k++)
			fscanf(f, "%lf", &(j->m[i][k]));
	return j;
err1:
	perror("input zero length matrix, check input file.");
	exit(1);
}
