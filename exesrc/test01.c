#include <cmplx.h>
#include <stdio.h>

int main(void) {
	
	typedef float cmplx_t[2];

	cmplx_t a = {2, 3};
	cmplx_t b = {4, 4};
	cmplx_t c = {0, 0};

	cmplx_div(a, b, c);

	printf("a / b = (%f, %f)\n", c[0], c[1]);
}
