#include<stdio.h>

int main() {
	float a, b;
	printf("Enter a:");
	scanf_s("%f", &a);
	printf("Enter b:");
	scanf_s("%f", &b);
	if (a == b) printf("a and b are equal\n");
	else printf("a is not equal to b\n");

	return 0;
}
