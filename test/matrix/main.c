#include <stdio.h>
#include <string.h>
#include "g.h"
#include "jacob_matrix.h"

extern void read_jacob_matrix(pfc_jacob_matrix* j, FILE* f);
extern void print_jacob_matrix(pfc_jacob_matrix* j);

int main(void) {
	pfc_jacob_matrix* j=malloc(sizeof(pfc_jacob_matrix));
	FILE* f=fopen("jacob_matrix_input", "r+");
	read_jacob_matrix(j, f);
	pfc_jacob_matrix_swap();
	pfc_jacob_matrix_mult();
	pfc_jacob_matrix_add();
	print_jacob_matrix(j);

	return 0;
}

