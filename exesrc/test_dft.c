#include <cmplx.h>
#include <io.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define PI 3.1415926535

int main(void) {

	typedef float cmplx_t[2];
	
	cmplx_t x[4];
	cmplx_t dx[4];

	for(int n = 0; n < 4; ++n) {
		x[n][0] = sin(n * PI / 2);
		x[n][1] = 0;
	}

	cmplx_dft(&x, &dx, 4);
	
	for(int n = 0; n < 4; ++n) {
		printf("DFT: %f, %f\n", *(dx + n * sizeof(cmplx_t))[0], *(dx + n * sizeof(cmplx_t))[1]);
	}

	int fd = open("test_dft.txt", O_CREAT, O_WRONLY);

	for(int n = 0; n < 4; ++n) {
		float vrijednost = *(dx + n * sizeof(cmplx_t))[0];
		void *a = (void *) &vrijednost;
		int vrijedost_ieee = *((int *) a);
		int vrijednost_cijeli_broj = (int) vrijednost;

		write_word(fd, vrijedost_ieee);

		vrijednost = *(dx + n * sizeof(cmplx_t))[1];
		a = (void *) &vrijednost;
		vrijedost_ieee = *((int *) a);
		vrijednost_cijeli_broj = (int) vrijednost;

		write_word(fd, vrijedost_ieee);
	}
	close(fd);
	return 0;
}
