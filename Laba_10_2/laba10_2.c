#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <windows.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 10
������� ������ 61391
������� �.�.
���� ����������: 24.10.2018
���� ������: �����������, ������� � ��������� ���������� � �������� ��������� �����.
����� ������ ��� ����: ��������� ������� ����.
*/
//---------------------------------------------------------------------------//

// ������ ������� ������������� ��������� ������� � ������� 
void setCursorPosition(int x, int y);

void main(int argc, char* argv[]) {
	char groups[100];
	int min;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ����� ������� ASCII
	printf("������� ASCII:\n ");
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 64; y++) {
			setCursorPosition(x * 15, 2 + y);
			printf("%3.d : %3.c", x * 64 + y, (char)(x * 64 + y));
		}
	}
	getch();
}

void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}