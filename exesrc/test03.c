#include <cmplx.h>
#include <stdio.h>

int main(void) {
	typedef float cmplx_t[2];

	cmplx_t a = {2, 3};
	double b = cmplx_mag(a);

	printf("|a| = %f\n", b);
}
