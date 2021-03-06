#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <math.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 7
������� ������ 61391
������� �.�.
���� ����������: 10.10.2018
���� ������: �����������, ������� � ��������� ���������� � �������� � �������������� �������
���� ������: ������� ��������� ������� � ���������� ������� (����������).

�������: ��������� ������� ����������� �������������� c� �������� �, ��������� ������������ ���������� ������� ������������.
*/
//---------------------------------------------------------------------------//

// ��������� ������� ����������� �������������� �� �������� A
void HexagonArea(double*);

void main(int argc, char* argv[]) {
	double a;
	// ��������� ��������� � �������
	setlocale(0, "Russian");

	// ���� ������
	do {
		printf("������� ������� ����������� ��������������: ");
		scanf("%lf", &a);
	} while (a < 0);

	// ����� ��������������� �������
	HexagonArea(&a);

	// ����� ������ �� �����
	printf("������� ����������� ��������������: %.2lf", a);
	getch();
}

void HexagonArea(double*a) {
	*a = 3 * sqrt(3)*(*a)*(*a) / 2;
}