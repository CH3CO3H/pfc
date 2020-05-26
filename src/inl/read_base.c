#include "g.h"
#include "inl.h"

void pfc_read_base(pfc_sysinfo* sysinfo, FILE* f) {
	char s[PFC_MAX_LINE];
	fgets(s, PFC_MAX_LINE, f);
	if (sscanf(s+PFC_READ_BASE_OFFSET, " %lf", &(sysinfo->b)) != 1) err_fmt();
}
