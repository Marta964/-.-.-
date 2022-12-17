#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int enterRows() {
    int n;
    printf("Enter the number of rows: ");
    while (scanf_s("%d", &n) != 1 || (int)n <= 0 || n > 100 || getchar() != '\n') {
        printf("Input error. Try again.\n ");
        rewind(stdin);
    }
    return n;
}
void output(int** arr, int n) {
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (arr[i][j] != 0)
        {
            printf("%5d", arr[i][j]);
            j++;
        }
        printf("\n");
    }
}
int mem(int n) {
    int** arr = (int**)calloc(n, sizeof(int*));
    return arr;
}
void enter(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)calloc(10000, sizeof(int));
    }
    for (int i = 0; i < n; i++) {

        int j = -1;
        printf("row[%d] ", i);
        do {
            j++;
            while (scanf_s("%d", &arr[i][j]) != 1 || arr[i][j] < 0 || getchar() != '\n') {
                printf("Wrong input!\n");
                rewind(stdin);
            }
        } while (arr[i][j] != 0);
        arr[i] = (int*)realloc(arr[i], (j + 1) * sizeof(int));

    }
    // output(arr, n);
}

void fre(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}
