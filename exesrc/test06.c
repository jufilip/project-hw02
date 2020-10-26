#include <cmplx.h>
#include <stdio.h>

int main(void) {
	typedef float cmplx_t[2];

	double mag = 3.605551;
	double phs = 0.982794;

	double b = cmplx_imag(mag, phs);

	printf("I(a) = %f\n", b);
}
