#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 9.1
������� ������ 61391
������� �.�.
���� ����������: 20.10.2018
���� ������: �����������, ������� � ��������� ���������� � �������� ��������� ����������� ��������
�������: ������� ��� ����������� ������� ������� n, � ������� ������ �������� ��� ������� ���������� ������� �� ����.
*/
//---------------------------------------------------------------------------//

// ������ ������� ������ ����� ����������� ������� ���������� � �������� �������
void sumOfMatrixRect(int[10][10], int);
// ������ ������� ������������� ��������� ������� � ������� 
void setCursorPosition(int, int);

void main(int argc, char* argv[]) {
	// ������ ������ ������������ ��� �������� ������� ������������� ����� ������
	// ������� ����������� ������ ������� ���������� � ������ ����� ����� ������� 
	int matrix[10][10], n;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ���� ������
	do {
		printf("������� ����������� ������: ");
		scanf("%d", &n);
	} while (n < 1 || n > 10);
	// ���������� �������� ������������ ������ �������
	// ������ ������� ����� �������
	printf("������ �������:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, 2 + y);
			if (x > y) {
				scanf("%d", &matrix[y][x]);
			}
			else {
				printf("0");
			}
		}
	}
	// ���������� �������� ������������ ������ �������
	// ����� ������ ����� �������
	printf("\n������ �������:");
	for (int y = n - 1, y1 = 0; y >= 0; y--, y1++) {
		for (int x = n - 1; x >= 0; x--) {
			// ����������� ������� � ��������������� �����������
			setCursorPosition(1 + (n - x - 1) * 3, 3 + n + (n - y - 1));
			if (x < y) {
				scanf("%d", &matrix[y][x]);
			}
			else {
				printf("0");
			}
		}
	}
	// ����� ��������������� �������
	sumOfMatrixRect(matrix, n);
	// ����� ���������� �� �����
	printf("\n��������� �������� ������:\n");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (x > y) {
			printf("%3.d", matrix[y][x]);
		}
			else {
				printf("  0");
			}
	}
	printf("\n");
}
getch();
}

void sumOfMatrixRect(int matrix[10][10], int n) {
	// ������������� ����� �������� � ������� ������������ ������� � �� ��������.
	// ���������� x,y ������������� ��� ����������� �� ��������� ������� ������������,
	// � ������� (n - x - 1), (n - y - 1) - ��� ����������� �� ��������� �������� ������������
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < y; x++) {
			matrix[(n - y - 1)][(n - x - 1)] += matrix[y][x];
		}
	}
}
void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}