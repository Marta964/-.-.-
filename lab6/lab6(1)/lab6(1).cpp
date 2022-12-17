#include<stdio.h>
#include<stdlib.h>
#include"array.h"
#include<time.h>

int main(void) {
	const int n=enterSize();
	int* arr;
	memory(&arr, n);
	random(arr, n);
	printMassiv(arr, n);
	


	int max = maxElement(arr, n);
	printf("\n%d\n", arr[max]);

	double difftime = 0.0;


	clock_t start1 = clock();
	int* mas1;
	memory(&mas1, n);
	copyMas(mas1,arr, n);
	sortSelectionMethod(mas1, n, max);
	printMassiv(mas1, n);
	clock_t end1 = clock();
	difftime += (double)(end1 - start1) / CLOCKS_PER_SEC;
	printf("\ntime of selection sort: %f sec\n", difftime);
	

	clock_t start2 = clock();
	int* mas2;
	memory(&mas2, n);
	copyMas(mas2, arr, n);
	bubbleSort(mas2, n, max);
	printMassiv(mas2, n);
	clock_t end2 = clock();
	difftime += (double)(end2 - start2) / CLOCKS_PER_SEC ;
	printf("\ntime of bubble sort: %f sec\n",difftime );
	

	clock_t start3 = clock();
	int* mas3;
	memory(&mas3, n);
	copyMas(mas3, arr, n);
	worstSort(mas3, n, max);
	printMassiv(mas3, n);
	clock_t end3 = clock();
	difftime += (double)(end3 - start3) / CLOCKS_PER_SEC;
	printf("\ntime of worst sort: %f sec\n", difftime);
	
	printMassiv(arr, n);
	
	free(arr);
	return 0;
}