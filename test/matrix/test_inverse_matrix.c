#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

extern void input_matrix(FILE* f, pfc_matrix* j);
extern void print_matrix(pfc_matrix*);

int main(void) {
	pfc_matrix* jcb=malloc(sizeof(pfc_matrix));
	FILE* input_matrix_p=fopen("input_matrix", "r+");
	if (!input_matrix_p) goto err1;
	input_matrix(input_matrix_p, jcb);
	print_matrix(jcb);
	pfc_matrix* v_j=pfc_inverse_matrix(jcb);
	printf("j after inverse:\n");
	print_matrix(jcb);
	printf("matrix v_j:\n");
	print_matrix(v_j);
	return 0;

err1:
	perror("open file input_matrix");
	exit(1);
}

