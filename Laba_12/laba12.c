#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 12
������� ������ 61391
������� �.�.
���� ����������: 28.10.2018
���� ������: �����������, ������� � ��������� ���������� � �������� ��������� ������������ ��������
�������: ���� �������������� ���������� ������� ������� n. ������� ����� ���������, ������������� � �������������� ����� �������.
													_________
												   |        /|
												   |      ///|
												   |    /////|
												   |_////////|
*/
//---------------------------------------------------------------------------//

// ������ ������� ��������� ����� ��������� ��� �������� ���������� �������
int elememtsSum(int*);
// ������ ������� ������������� ��������� ������� � ������� 
void SetCursorPosition(int, int);

void main(int argc, char* argv[]) {
	int *matrix, n, result;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ���� ������
	do {
		printf("������� ����������� ������: ");
		scanf("%d", &n);
	} while (n < 1);
	// ��������� ������ ��� ������
	matrix = malloc(n * n * sizeof(int));
	// ���������� �������
	printf("�������� �������:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			SetCursorPosition(1 + x * 3, 2 + y);
			scanf("%d", matrix + y * n + x);

		}
	}
	// ����� ��������������� �������
	result = elememtsSum(matrix);
	// ����� ���������� �� �����
	printf("\n��������� �������� ��������� �������������� �������: %d", result);
	getch();
	// ������������ ������
	free(matrix);
}

int elememtsSum(int* matrix) {
	// ���������� ����������� �������
	int n = sqrt(_msize(matrix) / sizeof(int));
	int sum = 0;
	// �������� ��������� �������
	for (int y = 0; y < n; y++) {
		for (int x = n - 1; x >= n - y - 1; x--) {
			sum += matrix[y*n + x];
		}
	}
	return sum;
}
void SetCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}