#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	float r, h, pi = 3.14, Sboc, S, V;
	printf("Введите радиус цилиндра: ");
	scanf_s("%f", &r);
	printf("Введите высоту цилиндра: ");
	scanf_s("%f", &h);
	
	Sboc = 2 * pi * r * h;
	S = 2 * pi * r * (r + h);
	V = pi * r * r * h;
	printf("Площадь боковой поверхности цилиндра=%.2f\n"
		"Площадь всей поверхности цилиндра = %.2f\n"
		"Объём цилиндра=%.2f\n", Sboc, S, V);
	return 0;
}