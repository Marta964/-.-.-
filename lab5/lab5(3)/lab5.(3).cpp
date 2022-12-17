#include"arrays.h"

int main() {
    int  n = enterSize();
    int** arr = memory(n);
    random(arr,n);
    printMassiv(arr,n);

    printf("The minimum element on the main diagonal= %d", MinOnMainDiaginal(arr,n));
    printf("\nThe minimum element under the main diagonal= %d", MinUnderMainDiaginal(arr,n));
    fre(arr,n);
    return 0;
}