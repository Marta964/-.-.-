#include<stdio.h>

int main()
{
	float r, h, pi = 3.14, Sboc, S, V;
	printf("Enter the radius of the cylinder : ");
	scanf_s("%f", &r);
	printf("Enter the height of the cylinder : ");
	scanf_s("%f", &h);
	
	Sboc = 2 * pi * r * h;
	S = 2 * pi * r * (r + h);
	V = pi * r * r * h;
	printf("The area of the side surface of the cylinder =%.2f\n"
		"The area of the entire cylinder = %.2f\n"
		"Cylinder volume =%.2f\n", Sboc, S, V);
	return 0;
}
