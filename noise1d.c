#include <math.h>
#include "noise1d.h"

double noise(double x) {
	double xf = floor(x);
	x -= xf;
	unsigned long long int xi = (unsigned long long int)xf;

	double y0 = hash(xi);
	double y1 = hash(xi + 1);

	double s0 = hash(xi + 2);
	double s1 = hash(xi + 3);

	double c0 = hash(xi + 4);
	double c1 = hash(xi + 5);

	double a = y1 - y0 - s0 - 0.5 * c0;
	double b = s1 - s0 - c0;
	double c = c1 - c0;
	double d = 6 * a - 3 * b + 0.5 * c;
	double e = -15 * a + 7 * b - c;
	double f = 10 * a - 4 * b + 0.5 * c;
	
	return x * (x * (x * (x * (x * d + e) + f) + 0.5 * c0) + s0) + y0;
}

double hash(unsigned long long int x) {
	x += 1;
	x ^= x >> 33;
	x *= 0xFF51AFD7ED558CCD;
	x ^= x >> 33;
	x *= 0xC4CEB9FE1A85EC53;
	x ^= x >> 33;

	return 2.0 * ((double)x / (double)0xFFFFFFFFFFFFFFFF) - 1.0;
}
