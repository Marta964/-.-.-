#include<stdio.h>
#include<math.h>
#include<stdbool.h>

void main() {
	int fred, ge = 0, i, j; 
	bool boolean;
	printf("Enter a number:");
	boolean=scanf_s("%d", &fred);
	while (boolean != 1) {
		printf("Input error. Try again.\n");
		getchar();
		boolean=scanf_s("%d", &fred);
	}

    for (i = 0; i*i*i <= fred-1; i++)
		for (j = i; j*j*j <= fred-1; j++) 
			if (i*i*i + j*j*j== fred) 
				ge++;
	printf("%d ways.", ge);
	
	return 0;
}