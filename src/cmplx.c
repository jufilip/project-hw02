#include <cmplx.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926535
#define E 2.7182818285

typedef float cmplx_t[2];

void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c) {		// c = a / b;
	float nazivnik = b[0] * b[0] + b[1] * b[1];

	c[0] = (a[0] * b[0] + a[1] * b[1]) / nazivnik;
	c[1] = (b[0] * a[1] - a[0] * b[1]) / nazivnik;
}

void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c) {		// c = a * b;
	c[0] = a[0] * b[0] - a[1] * b[1];
	c[1] = a[0] * b[1] + b[0] * a[1];
}

double cmplx_mag(cmplx_t a) {					// returns |a|
	double magnitude = sqrt(a[0] * a[0] + a[1] * a[1]);

	return magnitude;
}

double cmplx_phs(cmplx_t a) {					//returns the phase of a in rad
	double phase = atan(a[1] / a[0]);

	return phase;
}

double cmplx_real(double mag, double phs) {			//returns the real part of mag<phs
	double real = mag * cos(phs);

	return real;
}

double cmplx_imag(double mag, double phs) {			//returns the imaginary part of mag<phs
	double imag = mag * sin(phs);

	return imag;
}

void cmplx_dft(cmplx_t *input, cmplx_t *output, int N) {	//calculates dft of complex input signal
	
	cmplx_t pom;
	cmplx_t suma = {0, 0};

	for(int k = 0; k < N; ++k) {
		suma[0] = 0;
		suma[1] = 0; 
		for(int n = 0; n < N; ++n) {
			cmplx_t transform = {cos(2 * PI * k * n / N), -sin(2 * PI * k * n / N)};
			cmplx_mul(*(input + n), transform, pom);
			suma[0] += pom[0];
			suma[1] += pom[1];
		}
		*(output + k * sizeof(cmplx_t))[0] = suma[0];
		*(output + k * sizeof(cmplx_t))[1] = suma[1];
	}	
}

void cmplx_idft(cmplx_t *input, cmplx_t *output, int N) {	//calculates inverse dft of complex input signal

	cmplx_t pom;
	cmplx_t suma = {0, 0};

	for(int n = 0; n < N; ++n) {
		suma[0] = 0;
		suma[1] = 0;
		for(int k = 0; k < N; ++k) {
			cmplx_t transform = {cos(2 * PI * k * n / N), sin(2 * PI * k * n / N)};
			cmplx_mul(*(input + k), transform, pom);
			suma[0] += pom[0];
			suma[1] += pom[1];
		}
		*(output + n * sizeof(cmplx_t))[0] = suma[0] / N;
		*(output + n * sizeof(cmplx_t))[1] = suma[1] / N;
	}
}
