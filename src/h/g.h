#include <stddef.h>

#ifndef PFC_G_H
#define PFC_G_H

#define PFC_MAX_N (1<<10)
#define PFC_MAX_BRANCH (1<<12)
#define PFC_PCN 0.00005
#define PFC_ITERATION_LIMITS 10

struct pfc_bus {
	size_t no;	// No.
	unsigned char type;	/*	1 - Load bus (no generation)
						2 - Generator or plant bus
					 	3 - Swing bus
						4 - Islolated bus
				*/
	double pl;	// load MW
	double ql;	// load MVAR
	double g;	// Shunt conductance, MW at 1.0 per unit voltage
	double b;	// Shunt susceptance, MVAR at 1.0 per unit voltage. (- = reactor)
	double v;	// Voltage magnitude, per unit
	double va;	// Voltage angle, degrees
	double bv;	// Base voltage, KV
};
typedef struct pfc_bus pfc_bus;

struct pfc_sysinfo {
	double b;	// System base(MVA)
	size_t all;	// Nomber of all buses
	size_t br;	// Nomber of branches
	size_t ld;	// Nomber of load buses
};
typedef struct pfc_sysinfo pfc_sysinfo;

#endif
