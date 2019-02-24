#include "g.h"
#include "inl.h"

void pfc_read_branch(pfc_branch* branch[], pfc_sysinfo* sysinfo, FILE* f) {
	char s[PFC_MAX_LINE];
	size_t i;
	for (i=0;;i++) {
		fgets(s, PFC_MAX_LINE, f);
		int match;
		if ((match=sscanf(s, "%ld%ld%*d%lf%lf%lf", 
			&branch[i]->from,
			&branch[i]->to,
			&branch[i]->r,
			&branch[i]->x,
			&branch[i]->b)) != 5) {
			break;
		}
	}
	sysinfo->br=i;
	int e;
	if (sscanf(s, "%d", &e)!=1 && e) err_fmt();
}
