#include<stdio.h>

int main() {
	float a, b, c;
	printf("Enter a:\n");
	scanf_s("%f", &a);
	printf("Enter b:\n");
	scanf_s("%f", &b);
	printf("Enter c:\n");
	scanf_s("%f", &c);

	if (a == -b) {
		{
			printf("%f\n", c);
		} if (a == -c) {
			{
				printf("%f\n", b);
			} if (b == -c) {
				printf("%f\n", a);
			}
		}
		} else printf("no");
	return 0;
}
