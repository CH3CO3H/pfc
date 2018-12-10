#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void) {
	matrix* jcb=malloc(sizeof(matrix));
	FILE* input_matrix_p=fopen("input_matrix", "r+");
	if (!input_matrix_p) goto err1;
	input_matrix(input_matrix_p, jcb);
	print_matrix(jcb);
	matrix* v_j=inverse_matrix(jcb);
	printf("j after inverse:\n");
	print_matrix(jcb);
	printf("matrix v_j:\n");
	print_matrix(v_j);
	return 0;

err1:
	perror("open file input_matrix");
	exit(1);
}

