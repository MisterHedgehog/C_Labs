#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 10
������� ������ 61391
�������� �.
���� ����������: 24.10.2018
���� ������: �����������, ������� � ��������� ���������� � �������� ��������� �����.
*/
//---------------------------------------------------------------------------//


void main(int argc, char* argv[]) {
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ����� ������� ����
	printf("������� ����:\n ");
	for (int x = 0; x < 64; x++) {
		for (int y = 0; y < 4; y++) {
			if (!y && (x == 8 || x == 9 || x == 10 || x == 13))
				// ������� ��������: ��� ����� (8), �������������� ��������� (9), ������� �� ����� ������ (10) ��� ������� ������� (13)
				printf("%3.d :    \t", y * 64 + x);
			else
				// � �������� ������ ������ �������
				printf("%3.d : %3.c\t", y * 64 + x, (char)(y * 64 + x));
		}
		printf("\n");
	}
	getch();
}