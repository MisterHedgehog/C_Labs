#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 11
������� ������ 61391
������� �.�.
���� ����������: 28.10.2018
���� ������:  �����������, ������� � ��������� ���������� � �������� � �������������� ���������� ������� ����������
�������: ������������� �������� ���������� ������������ ������� ����������� n, �������� ����������� ����������.
*/
//---------------------------------------------------------------------------//

// ������ ������� ��������� �������� ���������� ������������ �������
void sortMatrix(int*);
// ������������� ��������� ������� � ������� 
void setCursorPosition(int, int);

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
			setCursorPosition(1 + x * 3, 2 + y);
			scanf("%d", matrix + y * n + x);

		}
	}
	// ����� ��������������� �������
	sortMatrix(matrix);
	// ����� ���������� �� �����
	printf("\n��������� ����������:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {

			setCursorPosition(1 + x * 3, n + 3 + y);
			printf("%d", matrix[y * n + x]);

		}
	}
	getch();
	// ������������ ������
	free(matrix);
}

void sortMatrix(int* matrix) {
	// n - ���������� ��������� �������
	int buf, n = _msize(matrix)/sizeof(int);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (matrix[j] > matrix[j + 1])
			{
				buf = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = buf;
			}

}

void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}