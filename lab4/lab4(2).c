#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int main() {
	int arr[100][100], sizei, sizej, p;
	printf("Enter the number of lines:");
	while (scanf_s("%d", &sizei) != 1 || (int)sizei < 0 || sizei>100||getchar()!='\n') {
		printf("Input error. Try again.\n ");
		rewind(stdin);
	}

	printf("Enter the number of columns:");
	while (scanf_s("%d", &sizej) != 1 ||(int) sizej < 0 || sizej>100||getchar()!='\n') {
		printf("Input error. Try again.\n ");
		rewind(stdin);
	}

	printf("Choose input method: random or keybord.");
	while (scanf_s("%d", &p) != 1 ||(int) p < 1 || p>2||getchar()!='\n') {
		printf("Input error.Try again.\n");
		rewind(stdin);
	}
	switch (p) {
	case 1:
		srand(time(NULL));
		for (int i = 0;i < sizei;i++) {
			for (int j = 0;j < sizej;j++) {
				arr[i][j] = rand() % 201 + (-100);
				//printf("%d element = %d\n ", i, arr[i]);
			}
		}
		break;
	case 2:
		for (int i = 0;i < sizei;i++) {
			for (int j = 0;j < sizej;j++) {
				printf("Input %dx%d number:", i + 1, j + 1);
				while (!scanf_s("%d", &arr[i][j])||getchar()!='\n') {
					printf("Input error.Try again.");
					rewind(stdin);
				}
			}
		}
		break;
	}
	printf("Array:\n");
	for (int i = 0;i < sizei;i++) {
		for (int j = 0;j < sizej;j++) {
			printf("%d\t", arr[i][j]);
			if (j == sizej - 1) printf("\n");
		}
	}
	int sum = 0;
	for (int i = 0;i < sizei;i++) {
		for (int j = 0;j < sizej;j++) {
			if (arr[i][j] >= 0) {
				sum = sum + arr[i][j];
			}
			else {
				sum = 0;
				break;
			}
		}
		if (sum > 0) break;
	}
	printf("%d\n", sum);

	if (sum > 0) {
		printf("Modified array:\n");
		for (int i = 0;i < sizei;i++) {
			for (int j = 0;j < sizej;j++) {
				printf("%d\t", arr[i][j] - sum);
				if (j == sizej - 1) printf("\n");
			}
		}
	}
	else printf("There is now row,all elements of which are positive");

	return 0;
}
