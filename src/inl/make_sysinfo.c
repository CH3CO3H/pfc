#include "inl.h"

extern inline pfc_sysinfo* pfc_make_sysinfo(void) {
	pfc_sysinfo* si=malloc(sizeof(pfc_sysinfo));
	return si;
}
