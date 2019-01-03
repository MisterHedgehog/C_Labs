#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <math.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 6.2
������� ������ 61391
������� �.�.
���� ����������: 05.10.2018
���� ������: �����������, ������� � ��������� ���������� � �������� �� ����� � ��������� ������ ����������
���� ������: ������� ��������� ��������� ������ � ��������� ������ ����������, ��� ������� ����� ������� ������.
��������� ������: ������� �� ��������, ���, ����� ���������� Dev C++ ��� Bolder C++ .

�������: ������ ����������� ����� N �������� ������ ��������� ��� ����. ����������� K ����� �����

*/
//---------------------------------------------------------------------------//

// ���������� ����� ��������� ���� �����. ���������� k ����� ��������������
int Function(int num, int k);

void main(int argc, char* argv[]) {
	int n, k, result;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ���� ������
	do {
		printf("������� ����������� �����: \n");
		scanf("%d", &n);
	} while (n < 0);
	do {
		printf("������� ���������� �����: \n");
		scanf("%d", &k);
	} while (k < 0);
	// ����� ��������������� �������
	result = Function(n, k);
	// ����� ������ �� �����
	printf("���������: %d", result);
	getch();
}

int Function(int num, int k) {
	int result = 0;
	// ���������� �������������� k ���
	for (; k > 0; k--, result = 0) {
		do {
			// ���������� ����� ����������� �������
			int cifra = num % 10;
			result += cifra * cifra;
			// ��������� ����� �� ���� ������
			num /= 10;
		} while (num);
		num = result;
	}
	return num;
}