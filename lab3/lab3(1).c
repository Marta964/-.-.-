#include<stdio.h>+
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int main(void) {
	int n,i, arr[100] = { 0 };
	bool  boolen;
	printf("Number of array elements = ");
	boolen = scanf_s("%d", &n);
	while(n<0||n>100){
		printf("Input error.Try again.");
		(void)getchar();
		boolen = scanf_s("%d", &n);
	}
	while (boolen != 1) {
		printf("Input error.Try again.\n");
		(void)getchar();
		boolen = scanf_s("%d", &n);
	}
	int p;
	printf("Choose a way to enter elements:1-random or 2-entry\n");
	scanf_s("%d", &p);
	switch (p) {
	case 1: {
		srand(time(NULL));
		for (i = 0;i < n;i++) {
			arr[i] = rand() % 201 + (-100);
			printf("%d element = %d\n ", i, arr[i]);
		}
	}
		  break;
	case 2: {
		for (i = 0;i < n;i++) {
			printf("Enter element number  %d  ", i);
			boolen = scanf_s("%d", &arr[i]);
			while (boolen != 1) {
				printf("Input error.Try again.\n");
				(void)getchar();
				boolen = scanf_s("%d", &arr[i]);
			}
		}
	}
		  break;
	default: printf("Input error.Try again.\n");	
	}


	int sum = 0;
	for (i = 0;i < n;i++) {
		if (arr[i] < 0) {
			sum = sum + arr[i];
		}
	}
	printf("\nSum of negative elements = %d\n", sum);



	int proz = 1, imax = 0, imin = 0;
	int max = arr[0];
	int min = arr[0];
	for (i = 0;i < n;i++)
		if (max < arr[i]) {
			max = arr[i];
			imax = i;
		}
	for (i = 0;i < n;i++)
		if (min > arr[i]) {
			min = arr[i];
			imin = i;
		}

	if (imin + 1 == imax || imax + 1 == imin || imax == imin) {
		proz = 0;
	}
	else if (imax < imin) {
		for (i = imax + 1;i < imin;i++) {
			proz = proz * arr[i];
		}
	}
	else if (imax > imin) {
		for (i = imin + 1;i < imax;i++) {
			proz = proz * arr[i];
		}
	}

	printf("The product of the array elements located between the maximum and minimum =%d", proz);

	return 0;
}