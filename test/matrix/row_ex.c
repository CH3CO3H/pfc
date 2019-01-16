#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

extern void input_matrix(FILE* f, pfc_matrix* j);
extern void print_matrix(pfc_matrix*);
extern pfc_matrix* matrix_mult(pfc_matrix* j, pfc_matrix* j_v);

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
	pfc_matrix* ret=matrix_mult(jcb, v_j);
	printf("j mult v_j:\n");
	print_matrix(ret);

	pfc_matrix* j_v_b=malloc(sizeof(pfc_matrix));
	FILE* jvb_txt=fopen("jvb_txt", "r+");
	input_matrix(jvb_txt, j_v_b);
	printf("matrix jcb inverse in book:\n");
	print_matrix(j_v_b);
	pfc_matrix* br=matrix_mult(jcb, j_v_b);
	printf("jcb mult reverse in book:\n");
	print_matrix(br);
	return 0;

err1:
	perror("open file input_matrix");
	exit(1);
}

