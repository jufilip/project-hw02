#include <cmplx.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	
	typedef float cmplx_t[2];
	
	cmplx_t x[4];
	cmplx_t dx[4];

	int fd = open("test_dft.txt", O_RDONLY);

	for(int i = 0; i < 4; ++i) {
		int vrijednost_ieee = read_word(fd);
		void *a = (void *) &vrijednost_ieee;
		float vrijednost = *((float *) a);

		*(dx + i * sizeof(cmplx_t))[0] = vrijednost;

		vrijednost_ieee = read_word(fd);
		a = (void *) &vrijednost_ieee;
		vrijednost = *((float *) a);
		
		*(dx + i * sizeof(cmplx_t))[1] = vrijednost;
	}	

	cmplx_idft(&dx, &x, 4);

	for(int i = 0; i < 4; ++i) {
		printf("Signal u vremenskoj domeni je %f, %f\n", *(x + i )[0], *(x + i )[1]);
	}	
}
