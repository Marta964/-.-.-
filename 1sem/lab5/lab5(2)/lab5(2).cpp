#include"arrays.h"

  
int main() {
    int n = enterRows();
    int** arr = mem(n);
   enter(&arr,  n);
   output(&arr, n);
    fre(arr,  n);
    return 0;
}


