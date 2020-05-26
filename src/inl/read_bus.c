#include "g.h"
#include "inl.h"

void pfc_read_bus(pfc_bus* bs[], pfc_sysinfo* sysinfo, FILE* f) {
	char s[PFC_MAX_LINE];
	size_t n;
	size_t nu_pq=0;
	fgets(s, PFC_MAX_LINE, f);
	if (sscanf(s+PFC_READ_BUS_OFFSET, "%zd", &n) != 1) err_fmt();
	sysinfo->all=n;
	for (size_t i=0;i<n;i++) {
		fgets(s, PFC_MAX_LINE, f);
		if ((sscanf(s, "%zd %*12c %*d %*d %hhu %lf %lf %lf %lf %lf %lf %lf",
			&bs[i]->no,
			&bs[i]->type,
			&bs[i]->v,
			&bs[i]->va,
			&bs[i]->pl,
			&bs[i]->ql,
			&bs[i]->pg,
			&bs[i]->qg,
			&bs[i]->bv)) != 9) {
			err_fmt();
		}
		if (!bs[i]->type || bs[i]->type==1) nu_pq++;
	}
	sysinfo->pq=nu_pq;
	int e;
	fgets(s, PFC_MAX_LINE, f);
	if (sscanf(s, "%d", &e)!=1 || e!=-999) err_fmt();
}
