#include <math.h>
#include "solve.h"

double pfc_get_dlt_ef_max(pfc_vector* dlt_ef) {
	double ret=0;
	for (size_t i=0;i<dlt_ef->len;i++) {
		if (fabs(dlt_ef->a[i])>ret) ret=fabs(dlt_ef->a[i]);
	}
	return ret;
}
