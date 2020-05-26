#include <stdlib.h>
#include <errno.h>
#include "inl.h"

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
	pfc_sysinfo* sysinfo;
	sysinfo=malloc(sizeof(pfc_sysinfo));
	pfc_read_base(sysinfo, f);
	printf("System base: %lfMVA.\n", sysinfo->b);
	pfc_read_bus(bus, sysinfo, f);
	size_t n=sysinfo->all;
	size_t pq=sysinfo->pq;
	printf("Bus: %zi\nPQ cnt: %zi\n", n, pq);
	pfc_read_branch(branch, sysinfo, f);
	printf("Branch: %zi\n", sysinfo->br);

	return 0;
err_arg:
	printf("usage: main <input_file>\n");
	exit(1);
err_fopen:
	perror("Open input file.");
	exit(1);
}
