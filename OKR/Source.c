#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int array[100], n, a;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ������ ����������� ������� � ����������
	do {
		printf("������� ����������� (������ 100) ");
		scanf("%d", &n);
	} while (n> 100 || n<0);
	printf("\n");
	// ������ �������� ������� � ����������
	for (int i = 0; i < n; i++) { 
			printf("������� ������� �������[%d]:", i);
			scanf("%d", &array[i]);
		}
	// ������� �������� ��������� �������
	printf("\n�������� ������:\n");
	for (int i = 0; i < n; i++) {
			printf("%3.d", array[i]);
	}
	a = array[0];
	// ���������� � ������� �����
	for (int i = 1; i < n; i++) {
		if (array[i-1] > array[i]) {
		}
	}
	getch();
}