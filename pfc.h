#include <stdio.h>
#include <complex.h>
// #include <stdlib.h>

#ifndef PFC_H
#define PFC_H

#define PFC_MAX_N (1<<10)
#define PFC_MAX_BRANCH (1<<12)
#define PFC_PCN 0.00005
#define PFC_ITERATION_LIMITS 10

struct pfc_sysinfo {
	double b;	// System base(MVA)
	size_t all;	// Nomber of all buses
	size_t br;	// Nomber of branches
	size_t pq;	// Nomber of PQ buses
};
typedef struct pfc_sysinfo pfc_sysinfo;

#define PFC_MAX_LINE 160
#define PFC_READ_BASE_OFFSET 31
#define PFC_READ_BUS_OFFSET 16
#define PFC_READ_BR_OFFSET 19

struct pfc_bus {
	size_t no;	// No.
	unsigned char type;	/*	1 - Load bus (no generation)
						2 - Generator or plant bus
					 	3 - Swing bus
						4 - Islolated bus
				*/
	double pl;	// load MW
	double ql;	// load MVAR
	double pg;	// Generation MW
	double qg;	// Generation MVAR
	double v;	// Voltage magnitude, per unit
	double va;	// Voltage angle, degrees
	double bv;	// Base voltage, KV
};
typedef struct pfc_bus pfc_bus;

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

typedef double complex pfc_adm_matrix[PFC_MAX_N][PFC_MAX_N];

extern pfc_adm_matrix* pfc_mk_adm_matrix(pfc_branch* br[PFC_MAX_BRANCH], pfc_sysinfo* sys, pfc_bus* bs[PFC_MAX_N]);

#define pfc_adm_get_y(adm, i, j) ((*adm)[i][j])
#define pfc_adm_get_b(adm, i, j) cimag((*adm)[i][j])
#define pfc_adm_get_g(adm, i, j) creal((*adm)[i][j])

#endif
