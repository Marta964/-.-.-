#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int enterSize() {
	int n;
	printf("Enter the size of the array: ");
	while (scanf_s("%d", &n) != 1 || n < 0 || getchar() != '\n') {
		printf("Input error.Try again.\n");
		rewind(stdin);
	}
	return n;
}
void memory(int** arr, int n) {
	*arr = (int*)calloc(n, sizeof(int));
}
void random(int* arr, int n) {
	srand(time(NULL));
	for (int i = 0;i < n;i++)
		arr[i] = rand() % 201 + (-100);
}
void printMassiv(int* arr, int n) {
	for (int i = 0;i < n;i++)
		printf("%5d", arr[i]);
	printf("\n");
}
int maxElement(int* arr, int n) {
	int max = 0;
	for (int i = 0;i < n;i++) {
		if (arr[i] > arr[max]) {
			max = i;
		}
	}
	return max;
}

void sortSelectionMethod(int* mas, int n, int max) {

	int m, minj;
	for (int i = max + 1;i < n - 1; i++) {
		minj = i;
		for (int j = i + 1;j < n;j++) {
			if (mas[minj] > mas[j]) {
				minj = j;
			}
		}
		m = mas[i];
		mas[i] = mas[minj];
		mas[minj] = m;
	}
}

void worstSort(int* mas, int n, int max) {
	
	sortSelectionMethod(mas, n,max);
	int m, minj;
	for (int i = max + 1;i < n - 1;i++) {
		minj = i;
		for (int j = i + 1;j < n;j++) {
			if (mas[j] > mas[minj]) minj = j;
		}
			m = mas[i];
			mas[i] = mas[minj];
			mas[minj] = m;

	}
	
}
void bubbleSort(int* mas, int n, int max) {
	
	int q;
	for (int i = max + 1;i < n - 1;i++) {
		for (int j = n - 1;j > i;j--) {
			if (mas[j - 1] > mas[j]) {
				q = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = q;
			}
		}
	}
	
}
void copyMas(int* mas, int* arr, int n) {

	int strsize = strlen(arr) + 1;
	for (int i = 0; i < n; i++)
	{
		mas[i] = arr[i];
	}
	return mas;
}
