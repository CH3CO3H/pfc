#include "g.h"
#include "inl.h"

void pfc_read_bus(pfc_bus* bs[], pfc_sysinfo* sysinfo, FILE* f) {
	char s[PFC_MAX_LINE];
	size_t nu_pq=0;
	size_t i;
	for (i=0;;i++) {
		fgets(s, PFC_MAX_LINE, f);
		int match;
		if ((match=sscanf(s, "%ld %hhu %lf %lf %lf %lf %*u %lf %lf ' %*s ' %lf",
			&bs[i]->no,
			&bs[i]->type,
			&bs[i]->pl,
			&bs[i]->ql,
			&bs[i]->g,
			&bs[i]->b,
			&bs[i]->v,
			&bs[i]->va,
			&bs[i]->bv)) != 9) {
			break;
		}
		if (bs[i]->type==1) nu_pq++;
	}
	sysinfo->all=i;
	sysinfo->ld=nu_pq;
	int e;
	if (sscanf(s, "%d", &e)!=1 && e) err_fmt();
}
