#include<stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	float a, b;
	printf("������� a:");
	scanf_s("%f", &a);
	printf("������� b:");
	scanf_s("%f", &b);
	if (a == b) printf("a � b �����\n");
	else printf("a �� ����� b\n");

	return 0;
}