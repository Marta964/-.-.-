#include"array.h"

int main() {
	int row = enterRow();
	int col = enterCol();
	int **arr=memory(row, col);
	random(arr, row, col);
	printMassiv(arr, row, col);
	shell_sort( arr,  row, col);

	printMassiv(arr, row, col);
	
	fre(arr,row);
	return 0;
 }