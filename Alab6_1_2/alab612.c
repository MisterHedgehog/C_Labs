#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 6.1.2
������� ������ 61391
�������� �.�.
21.09.2018
���� ������: ���� ����������� ����� n. ��������, ����� �� ����������� ������
����� � ���� ������������ ���� ���������������� ����������� �����, � ������������.
*/
//---------------------------------------------------------------------------//
bool Zadanie(int n);
//���� ����������
void main(int argc, char* argv[]) {
	// ���������� ����������
	int n;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ���� �����
	printf("Vvedite chislo\n");
	scanf("%d", &n);
	//����� ������
	if (Zadanie(n)) {
		printf("��, ����� �����������");
	}
	else {
		printf("���, ������ �����������");
	}
	getch();
}
//������ � ���������� ��������
bool Zadanie(int n) {
	int a = 1;
	while (a < n) {
		if ((a * (a + 1) *(a + 2)) == n) {
			return true;
		}
		a++;
	}
	return false;
}