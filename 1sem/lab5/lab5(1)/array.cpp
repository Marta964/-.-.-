#include<stdio.h>
#include <stdlib.h>
#include<time.h>

void enterSize(int n) {
    printf("Enter the size of the array: ");
    while (scanf_s("%d", &n) != 1 || (int)n <= 0 || n > 100 || getchar() != '\n') {
        printf("Input error. Try again.\n ");
        rewind(stdin);
    }
}
void memory(int* arr, int n) {
    arr = (int*)malloc(n * sizeof(int));
}
void printMassiv(int* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void random(int* arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        arr[i] = 2 * (rand() % 50);
    }
}
