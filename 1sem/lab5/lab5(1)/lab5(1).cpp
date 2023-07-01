#include<stdio.h>
#include<malloc.h>
#include"array.h"

int startOfSegment() {
    int a;
    printf("\nEnter a segment: from ");
    while (scanf_s("%d", &a) != 1 || getchar() != '\n') {
        printf("Input error. Try again.\n ");
        rewind(stdin);
    }
    return a;
}
int endOfSegment(int a){
    int b;
    printf("to ");
    while (scanf_s("%d", &b) != 1 || getchar() != '\n' || b < a) {
        printf("Input error. Try again.\n ");
        rewind(stdin);
    }
    return b;
}

int main() {
    int* arr;
    int n;
    printf("Enter the size of the array: ");
    while (scanf_s("%d", &n) != 1 || n <= 0 || getchar() != '\n') {
        printf("Input error. Try again.\n ");
        rewind(stdin);
    }
    arr = (int*)malloc(n * sizeof(int));
    random(arr, n);
    printMassiv(arr, n);
    int a = startOfSegment();
    int b = endOfSegment(a);
    //printf("%d   %d\n", a, b);
    for (int i = n - 1;i >= 0;i--) {
        if (arr[i] >=  a && arr[i] <= b) {
            arr[i] = arr[n - 1];
            n--;
        }
    }
    int q = 0;
    for (int i = 0;i < n - 1;i++) {
        for (int j = 0;j < n - i - 1;j++) {
            if (arr[j-1] > arr[j]) {
                q = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = q;
            }
        }
    }

    if (n == 0)
        printf("All elements of the array are in the segment.");
    else printMassiv(arr, n);
    free(arr);
    return 0;
}