#include <stdlib.h>
#include "matrix.h"

void input_matrix(FILE* f, pfc_matrix* j) {
	printf("reading matrix input file...\n");
	fscanf(f, "%zu", &(j->len));
	if (!(j->len)) goto err1;
	printf("matrix size: %zd\n", j->len);
	for (size_t i=0;i<j->len;i++)
		for (size_t k=0;k<j->len;k++)
			fscanf(f, "%lf", &(j->m[i][k]));
	return;
err1:
	perror("input zero length matrix, check input file.");
	exit(1);
}

