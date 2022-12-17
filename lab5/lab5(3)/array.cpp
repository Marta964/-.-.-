#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int enterSize() {
    int n;
    printf("Enter the size of the array: ");
    while (scanf_s("%d", &n) != 1 || (int)n <= 0 || getchar() != '\n') {
        printf("Input error. Try again.\n ");
        rewind(stdin);
    }
    return n;
}

int** memory(int n) {
    int** arr = (int**)calloc(n, sizeof(int*));
    for (int i = 0;i < n;i++) {
        arr[i] = (int*)calloc(n, sizeof(int));
    }
    return arr;
}
void printMassiv(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0;j < n;++j) {
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }
}
void random(int** arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0;j < n;++j) {
            arr[i][j] = rand() % 201 + (-100);
        }
    }
}
void fre(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

}
int MinOnMainDiaginal(int** arr, int n) {
    int min1 = 201;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && arr[i][j] < min1) {
                min1 = arr[i][j];

            }
        }
    }
    return min1;
}

int MinUnderMainDiaginal(int** arr, int n) {
    int min2 = 201;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j && arr[i][j] < min2) {
                min2 = arr[i][j];
            }
        }
    }
    return min2;
}
