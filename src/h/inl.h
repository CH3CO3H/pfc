#include <stdio.h>
#include <stdlib.h>

#ifndef PFC_INL_H
#define PFC_INL_H

#define PFC_MAX_LINE 160

struct pfc_branch {
	size_t from;
	size_t to;
	double r;
	double x;
	double b;
};
typedef struct pfc_branch pfc_branch;

#define err_fmt() \
	do {\
	fprintf(stderr, "Data format error. Check input file.\n");\
	exit(1);\
	} while(0)

extern void pfc_read_base(pfc_sysinfo* sysinfo, FILE* f);
extern void pfc_read_bus(pfc_bus* bs[], pfc_sysinfo* sysinfo, FILE* f);
extern void pfc_read_branch(pfc_branch* branch[], pfc_sysinfo* sysinfo, FILE* f);

#endif
