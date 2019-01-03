#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 9.2
������� ������ 61391
������� �.�.
���� ����������: 24.10.2018
���� ������: �����������, ������� � ��������� ���������� � �������� ��������� ����������� ��������
�������: ���� �������������� ���������� ������� ������� n. ������� ����� ���������, ������������� � �������������� ����� �������.
                                                    _________
                                                   |        /|
                                                   |      ///|
                                                   |    /////|
                                                   |_////////|
*/
//---------------------------------------------------------------------------//

// ��������� ����� ��������� ��� �������� ���������� �������
int elementsSum(int[10][10], int);
// ������������� ��������� ������� � ������� 
void setCursorPosition(int, int);

void main(int argc, char* argv[]) {
	int matrix[10][10], n, result;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ���� ������
	do {
		printf("������� ����������� ������: ");
		scanf("%d", &n);
	} while (n < 1 || n > 10);
	// ���������� �������
	printf("�������� �������:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, 2 + y);
			scanf("%d", &matrix[y][x]);
			
		}
	}
	// ����� ��������������� �������
	result = elementsSum(matrix, n);
	// ����� ���������� �� �����
	printf("\n��������� �������� ��������� �������������� �������: %d", result);
	getch();
}

int elementsSum(int matrix[10][10], int n) {
	int sum = 0;
	// �������� ��������� �������
	for (int y = 0; y < n; y++) {
		for (int x = n - 1; x > n - y - 2; x--) {
			sum += matrix[y][x];
		}
	}
	return sum;
}
void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}