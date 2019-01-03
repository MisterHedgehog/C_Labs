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

// ������ ������� � �������� ������������ ������ ������� ���������� ������� ����������� ������ �������
void sumOfMatrixRect(int[10][10], int[10][10], int);
// ������ ������� ������������� ��������� ������� � ������� 
void setCursorPosition(int, int);

void main(int argc, char* argv[]) {
	int matrix1[10][10], matrix2[10][10], n;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ���� ������
	do {
		printf("������� ����������� ������: ");
		scanf("%d", &n);
	} while (n < 1 || n > 10);
	// ���������� �������� ������������ ������ �������
	printf("������ �������:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, 2 + y);
			if (x > y) {
				scanf("%d", &matrix1[y][x]);
			}
			else {
				printf("0");
				matrix1[y][x] = 0;
			}
		}
	}
	// ���������� �������� ������������ ������ �������
	printf("\n\n������ �������:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, n + 4 + y);
			if (x > y) {
				scanf("%d", &matrix2[y][x]);
			}
			else {
				printf("0");
				matrix2[y][x] = 0;
			}
		}
	}
	// ����� ��������������� �������
	sumOfMatrixRect(matrix1, matrix2, n);
	// ����� ���������� �� �����
	printf("\n\n��������� �������� ������:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, n * 2 + 6 + y);
			printf("%d", matrix1[y][x]);
		}
	}
	getch();
}

void sumOfMatrixRect(int matrix1[10][10], int matrix2[10][10], int n) {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			matrix1[y][x] += matrix2[y][x];
		}
	}
}
void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}