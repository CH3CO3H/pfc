#include "matrix.h"
#include "test_matrix.h"

int main(int argc, const char* argv[]) {
	if (argc!=2) goto err_arg;
	FILE* fp=fopen(argv[1], "r");
	if (!fp) goto err_fp;
	pfc_matrix* jcb=matrix_input(fp);
	matrix_print("input matrix", jcb);
	pfc_matrix* v_j=pfc_matrix_inverse(jcb);
	matrix_print("inversed matrix", v_j);
	pfc_matrix* rlt=matrix_mult(jcb, v_j);
	matrix_print("jcb * v_j", rlt);
	return 0;
err_arg:
	fprintf(stderr, "usage: ./main <input_file>\n");
	return 1;
err_fp:
	perror("Open input file.");
	return 1;
}
