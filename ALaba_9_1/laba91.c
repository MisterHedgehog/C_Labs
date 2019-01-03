#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 9.1
������� ������ 61391
�������� �.�.
���� ����������: 21.12.2018
���� ������: �����������, ������� � ��������� ���������� � �������� ��������� ����������� ��������
�������: ������� ������������ ������� �� �������.
*/
//---------------------------------------------------------------------------//

// ��������� ����� ��������� ��� �������� ���������� �������
void proizvedenie(int[10][10], int[10], int);

void main(int argc, char* argv[]) {
	int matrix[10][10], vector[10], n, result;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ���� ������



	do {
		printf("������� ����������� ������: ");
		scanf("%d", &n);
	} while (n < 1 || n > 10);
	// ���������� �������
	printf("\n���������� �������:\n");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printf("������� [%d][%d]: ",y,x);
			scanf("%d", &matrix[y][x]);
		}
	}
	printf("\n�������� �������:\n");
	for (int y = 0; y < n; y++) {
		printf("������� [%d]:", y);
		scanf("%d", &vector[y]);
	}
	printf("\n�������� �������:\n");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printf("%3d", matrix[y][x]);
		}
		printf("|%3d\n", vector[y]);
	}
	// ����� ��������������� �������
	proizvedenie(matrix, vector, n);
	// ����� ���������� �� �����
	printf("\n�������� �������:\n");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printf("%3d", matrix[y][x]);
		}
		printf("\n");
	}
	getch();
}

void proizvedenie(int mat[10][10], int vec[10], int n) {
	for (int i = 0; i < n; i++) {
		for (int c = 0; c < n; c++) {
			mat[i][c] *= vec[i];
		}
	}
}