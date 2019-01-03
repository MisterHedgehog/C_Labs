#include <stdio.h>
#include <math.h>

void metodDown(int a, int b, int n);
void metodUp(int a, int b, int n);
int random(int min, int max);


void main(int argc, char* argv[]) {
	int r, a = 0, n, b = 1;

	// Добавляем кириллицу в консоль 
	setlocale(0, "Russian");
	for (;;) {
		printf("vvedite n:");
		scanf_s("%d", &n);
		while (n <= 0 || n > 10) {
			printf("ТЫ ЧЁ ПЁС ");
			scanf_s("%d", &n);
		}
		r = random(1, 10);
		metodUp(a, b, n);
		printf("\n");
		if (r == n) {
			printf("Ты Молодец-Огурец!");
		}
		else
		{
			printf("Чи Да ?");
		}
		metodDown(a, b, n);
		printf("Введите число от 1 до 12\n");
		scanf_s("%d", &n);
		switch (n) {
		case 1: printf("январь\n"); break;
		case 2: printf("февраль\n"); break;
		case 3: printf("март\n"); break;
		case 4: printf("апрель\n"); break;
		case 5: printf("май\n"); break;
		case 6: printf("июнь\n"); break;
		case 7: printf("июль\n"); break;
		case 8: printf("август\n"); break;
		case 9: printf("сентябрь\n"); break;
		case 10: printf("октябрь\n"); break;
		case 11: printf("ноябрь\n"); break;
		case 12: printf("декабрь\n"); break;
		}
		switch (n) {
		case 12:
		case 1:
		case 2: printf("зима\n"); break;
		case 3:
		case 4:
		case 5: printf("весна\n"); break;
		case 6:
		case 7:
		case 8: printf("лето\n"); break;
		case 9:
		case 10:
		case 11: printf("осень\n"); break;
		}
	}

}

int random(int min, int max) {
	int random = min + rand() % max;
	return random;
}
void metodUp(int a , int b , int n) {
	for (a = 0; a < n; a++)
	{
		printf("\n");
		for (b = 1; b <= a; b++)
		{
			printf("*");
		}
	}
}
void metodDown(int a, int b, int n) {
	for (a = n; a > 1; a--)
	{
		printf("\n");
		for (b = 1; b <= a; b++)
		{
			printf("*");
		}
	}
}