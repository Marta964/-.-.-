#include<stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL,"rus");
	int n;
	printf("¬ведите номер мес€ца:");
	scanf_s("%d", &n);
	switch (n) {
	case 1:
		printf("€нварь");
		break;
	case 2: printf("февраль");
		break;
	case 3: printf("март");
		break;
	case 4: printf("апрель");
		break;
	case 5: printf("май");
		break;
	case 6: printf("июнь");
		break;
	case 7: printf("июль");
		break;
	case 8: printf("август");
		break;
	case 9: printf("сент€брь");
		break;
	case 10: printf("окт€брь");
		break;
	case 11: printf("но€брь");
		break;
	case 12: printf("декабрь");
		break;
	default: printf("ќшибка ввода.ѕопоробуйте снова.");
		break;
	}
	return 0;
}