#include <stdio.h>
#include <math.h>

void metodDown(int a, int b, int n);
void metodUp(int a, int b, int n);
int random(int min, int max);


void main(int argc, char* argv[]) {
	int r, a = 0, n, b = 1;

	// ��������� ��������� � ������� 
	setlocale(0, "Russian");
	for (;;) {
		printf("vvedite n:");
		scanf_s("%d", &n);
		while (n <= 0 || n > 10) {
			printf("�� ר Ϩ� ");
			scanf_s("%d", &n);
		}
		r = random(1, 10);
		metodUp(a, b, n);
		printf("\n");
		if (r == n) {
			printf("�� �������-������!");
		}
		else
		{
			printf("�� �� ?");
		}
		metodDown(a, b, n);
		printf("������� ����� �� 1 �� 12\n");
		scanf_s("%d", &n);
		switch (n) {
		case 1: printf("������\n"); break;
		case 2: printf("�������\n"); break;
		case 3: printf("����\n"); break;
		case 4: printf("������\n"); break;
		case 5: printf("���\n"); break;
		case 6: printf("����\n"); break;
		case 7: printf("����\n"); break;
		case 8: printf("������\n"); break;
		case 9: printf("��������\n"); break;
		case 10: printf("�������\n"); break;
		case 11: printf("������\n"); break;
		case 12: printf("�������\n"); break;
		}
		switch (n) {
		case 12:
		case 1:
		case 2: printf("����\n"); break;
		case 3:
		case 4:
		case 5: printf("�����\n"); break;
		case 6:
		case 7:
		case 8: printf("����\n"); break;
		case 9:
		case 10:
		case 11: printf("�����\n"); break;
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