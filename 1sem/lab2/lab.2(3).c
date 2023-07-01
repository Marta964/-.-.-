#include<stdbool.h>
#include<stdio.h>

void main() {
	int P, Q; 
	bool boolen;
	printf("Enter  P ");
	boolen = scanf_s("%d", &P);
	while (boolen != 1) {
		printf("Input error. Try again.\n");
		getchar();
		boolen = scanf_s("%d", &P);
	}

	printf("Enter Q ");
	boolen=scanf_s("%d", &Q);
	while (boolen != 1) {
		printf("Input error. Try again.\n");
		getchar();
		boolen = scanf_s("%d", &Q);
	}
	
	int nod ;
	for (nod = P;nod > 0;nod--) {
		if (P % nod == 0 && Q % nod == 0 && nod != 1) {
			printf("The numbers are not mutually simple.\n");
			break;
		}
		if (P % nod == 0 && Q % nod == 0 && nod == 1) {
			printf("The numbers %d and %d are nutually simple.\n", P, Q);
			break;
		}
	} 
	return 0;
}