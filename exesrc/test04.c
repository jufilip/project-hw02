#include <cmplx.h>
#include <stdio.h>

int main(void) {
	typedef float cmplx_t[2];

	cmplx_t a = {2, 3};
	double b = cmplx_phs(a);

	printf("<a = %f radians\n", b);
}
