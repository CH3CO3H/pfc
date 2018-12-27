#include <stdio.h>

void pfc_swap_s(size_t* a, size_t* b) {
	size_t t=*a;
	*a=*b;
	*b=t;
}
