#include <stddef.h>

#ifndef PFC_G_H
#define PFC_G_H

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

#endif
