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
float HexagonArea(float);
void main(int argc, char* argv[]) {
	float a;
	// ��������� ��������� � �������
	setlocale(0, "Russian");

	// ���� ������
	do {
		printf("������� ������� ����������� ��������������: ");
		scanf("%f", &a);
	} while (a < 0);

	// ����� ��������������� �������
	a = 6 * HexagonArea(a);

	// ����� ������ �� �����
	printf("������� ����������� ��������������: %.2f", a);
	getch();
}

float HexagonArea(float a) {
	return sqrt(3)*a*a / 4;
	}