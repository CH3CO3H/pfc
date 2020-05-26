#include "pfc.h"

int main(int argc, const char* argv[]) {
	if (argc!=2) goto err_arg;
	FILE* f=fopen(argv[1], "r");
	if (!f) goto err_fopen;
	pfc_bus* bus[PFC_MAX_N];
	for (size_t i=0;i<PFC_MAX_N;i++)
		bus[i]=malloc(sizeof(pfc_bus));
	pfc_branch* branch[PFC_MAX_BRANCH];
	for (size_t i=0;i<PFC_MAX_BRANCH;i++)
		branch[i]=malloc(sizeof(pfc_branch));
	pfc_sysinfo* sysinfo=pfc_make_sysinfo();
	pfc_read_base(sysinfo, f);
	printf("System base: %lfMVA.\n", sysinfo->b);
	pfc_read_bus(bus, sysinfo, f);
	size_t n=sysinfo->all;
	size_t pq=sysinfo->pq;
	printf("Bus: %zd\nPQ: %zd\n", n, pq);
	pfc_read_branch(branch, sysinfo, f);
	printf("Branch: %zd\n", sysinfo->br);
	pfc_adm_matrix* m=pfc_mk_adm_matrix(branch, sysinfo, bus);
	print_adm_matrix(m, n);
	// pfc_matrix* b_n;
	// pfc_matrix* b_m;
	// pfc_matrix_b(m, b_n, b_m, n);
	// pfc_matrix_reverse(b_n);
	// pfc_matrix_reverse(b_m);
	pfc_solve(adm);
	return 0;
err_arg:
	printf("usage: main <input_file>\n");
	exit(1);
err_fopen:
	perror("Open input file.");
	exit(1);
}

void print_adm_matrix(pfc_adm_matrix* m, size_t n) {
	printf("ready to print adm matrix:\n");
	printf("matrix size: %zd\n", n);
	for (size_t i=0;i<n;i++) {
		for (size_t j=0;j<n;j++) {
			printf("%.5lf + j%.5lf\t", pfc_adm_get_g(m, i, j), pfc_adm_get_b(m, i, j));
		}
		putchar('\n');
	}
}

