#include "solve.h"

void pfc_get_new_ef(pfc_vector* ef, pfc_vector* dlt_ef) {
	for (size_t i=0;i<ef->len-2;i++) {
		ef->a[i]+=dlt_ef->a[i];
	}
}
