#include<stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	float a, b;
	printf("¬ведите a:");
	scanf_s("%f", &a);
	printf("¬ведите b:");
	scanf_s("%f", &b);
	if (a == b) printf("a и b равны\n");
	else printf("a не равно b\n");

	return 0;
}