#include<stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	float a, b, c;
	printf("введите значение a:\n");
	scanf_s("%f", &a);
	printf("введите значение b:\n");
	scanf_s("%f", &b);
	printf("введите значение c:\n");
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
		} else printf("нет");
	return 0;
}


	/*if (a == -b) {
		printf("%.f\n", c);
	}
	if (a == -c) {
		printf("%2.f\n", b);
	}
	if (b == -c) {
		printf("%2.f\n", a);
	}
	else printf("нет");
	return 0;
}