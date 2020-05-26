#include "g.h"
#include "inl.h"

void pfc_read_branch(pfc_branch* branch[], pfc_sysinfo* sysinfo, FILE* f) {
	char s[PFC_MAX_LINE];
	size_t n;
	fgets(s, PFC_MAX_LINE, f);
	if (sscanf(s+PFC_READ_BR_OFFSET, "%zd", &n) != 1) err_fmt();
	for (size_t i=0;i<n;i++) {
		fgets(s, PFC_MAX_LINE, f);
		int match;
		if ((match=sscanf(s, "%zd%zd%*d%*d%*d%*d%lf%lf%lf", 
			&branch[i]->from,
			&branch[i]->to,
			&branch[i]->r,
			&branch[i]->x,
			&branch[i]->b)) != 5) {
			err_fmt();
		}
	}
	sysinfo->br=n;
	int e;
	fgets(s, PFC_MAX_LINE, f);
	if (sscanf(s, "%d", &e)!=1 || e!=-999) err_fmt();
}
