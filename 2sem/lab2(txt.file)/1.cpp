#include"header.h"


int main(void) {
	char fileName[] = "file.txt";
	while (1) {
		int a;
		printf("Choose tasks:\n 1 - Compress \n 2 - Decompress\n 3 - Exit\n");
		while (scanf("%d", &a) != 1 || a < 1 || a > 2 || getchar() != '\n') {
			printf("Input error.Try again.\n");
			rewind(stdin);
		}

		if (a = 1)
			compress(fileName);
		if (a = 2)
			decompress(fileName);
		if (a = 3) return 0;
	}
return 0;
}
