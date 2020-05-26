#include <stdio.h>
#include <stdlib.h>
#include "g.h"

#ifndef PFC_INL_H
#define PFC_INL_H

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

// extern inline pfc_buses* pfc_make_buses(void);
// extern inline pfc_branches* pfc_make_branches(void);
extern inline pfc_make_sysinfo(void);
extern void pfc_read_base(pfc_sysinfo* sysinfo, FILE* f);
extern void pfc_read_bus(pfc_bus* bs[], pfc_sysinfo* sysinfo, FILE* f);
extern void pfc_read_branch(pfc_branch* branch[], pfc_sysinfo* sysinfo, FILE* f);

#endif
