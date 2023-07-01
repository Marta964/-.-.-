#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int enterRow() {
	int row;
	printf("Enter the size of the array: ");
	while (scanf_s("%d", &row) != 1 || row < 0 || getchar() != '\n') {
		printf("Input error.Try again.\n");
		rewind(stdin);
	}
	return row;
}
int enterCol() {
	int col;
	printf("Enter the size of the array: ");
	while (scanf_s("%d", &col) != 1 || col < 0 || getchar() != '\n') {
		printf("Input error.Try again.\n");
		rewind(stdin);
	}
	return col;
}
int** memory(int row, int col) {
	int** arr = (int**)calloc(row, sizeof(int*));
	for (int i = 0;i < row;i++) {
		arr[i] = (int*)calloc(col, sizeof(int));
	}
	return arr;
}
void random(int** arr, int row, int col) {
	srand(time(NULL));
	for (int i = 0;i < row;i++)
		for (int j = 0;j < col;j++)
			arr[i][j] = rand() % 201 + (-100);
}
void printMassiv(int** arr, int row, int col) {
	printf("\n");
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++)
			printf("%5d", arr[i][j]);
		printf("\n");
	}
}
void fre(int** arr, int row) {
	for (int i = 0; i < row; i++) {
		free(arr[i]);
	}
	free(arr);
}

int sum(int* arr, int col) {
	int sum = 0;
	for (int j = 0;j < col;j++)
		sum = sum+arr[j];
	return sum;
}
void shell_sort(int** arr, int row, int col) {
	int n;
	for (int gap = row / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < row; ++i) {

			for (int j = i - gap;j >= 0 && sum(arr[j], col) < sum(arr[j + gap], col);j -= gap) {
				for (int k = 0; k < col; k++) {
					n = arr[j][k];
					arr[j][k] = arr[j + gap][k];
					arr[j + gap][k] = n;
				}
			}
		}
	}

}
