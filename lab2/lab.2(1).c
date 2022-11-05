#include<stdio.h>
#include<math.h>

void main() {
	float grrr = 1 ;
	int aff = 0, n = 2;
	
	do {
		aff++;
		grrr = grrr + 1.0/n;
	} while (grrr <= 3);
	printf("Number of terms %d", aff);
	return 0;
}