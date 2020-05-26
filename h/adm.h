#include <stdio.h>
#include <complex.h>
#include "inl.h"
#include "g.h"

#ifndef PFC_AMD_H
#define PFC_ADM_H

// extern void pfc_swap_s(size_t* a, size_t* b);

typedef double complex pfc_adm_matrix[PFC_MAX_N][PFC_MAX_N];

extern pfc_adm_matrix* pfc_mk_adm_matrix(pfc_branch* br[PFC_MAX_BRANCH], pfc_sysinfo* sys, pfc_bus* bs[PFC_MAX_N]);

#define pfc_adm_get_y(adm, i, j) ((*adm)[i][j])
#define pfc_adm_get_b(adm, i, j) cimag((*adm)[i][j])
#define pfc_adm_get_g(adm, i, j) creal((*adm)[i][j])

#endif
