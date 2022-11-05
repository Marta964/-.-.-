#include<stdio.h>+
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int main(void) {
	int n, i, arr[100] = { 0 };
	bool  boolen;
	printf("Number of array elements = ");
	boolen = scanf_s("%d", &n);
	while (n < 0||n>100) {
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
			if (arr[i] == 0) {
				printf("Error!!!The array must not contain zero elements.");
				break;
			}
		}
	}
		  break;
	case 2: {
		for (i = 0;i < n;i++) {
			printf("Enter element number %d ", i);
			boolen = scanf_s("%d", &arr[i]);
			while (boolen != 1) {
				printf("Input error.Try again.\n");
				(void)getchar();
				boolen = scanf_s("%d", &arr[i]);
			}
			if (arr[i] == 0) {
				printf("Error!!!The array must not contain zero elements.");
				break;
			}
		}
	}
		  break;
	default: printf("Input error.Try again.\n");
	}

	
	int j = 0, q = 0;
	for (i = 0;i <  n - 1;i++){
		for(j=0;j<n-i-1;j++){
			if (arr[j] < arr[j + 1]) {
				q = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = q;
			}
		}
	}

	for (i = 0;i < n;i++) {
		printf(" %d ", arr[i]);
	}

	return 0;
}