#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 8
������� ������ 61391
�������� �.�.
28.11.2018
���� ������: � ���������� �������, ��������� �� n ������������ ���������
���������� ��������� ����� ������������� ��������� �������.
*/
//---------------------------------------------------------------------------//
// ���� �������
void main(int argc, char* argv[]) {
	// ���������� ����������
	setlocale(0, "Russian");
	double *a, sum = 0;
	// ���������� �������
	a = malloc(100 * sizeof(double));
	// ���������� �������
	for (int i = 0; i < 100; i++){
		a[i] = -5 +  (double)(rand() % 1001) / 100;
	}
	// ����� �������
	printf("\n�������� ������:\n");
	for (int i = 0; i < 100; i++) {
		printf("������� [%d] = %.2lf\n",i, a[i]);
	}
	// ����� ������������� �������� �������
	for (int i = 0; i < 100; i++) {
		if (a[i] < 0) {
			sum += a[i];
		}
	}
	// ����� �����
	printf("\n\n����� �����: %.2lf", sum);
	getch();
}