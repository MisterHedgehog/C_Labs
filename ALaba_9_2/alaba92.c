#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 9.2
������� ������ 61391
�������� �.�.
21.09.2018
���� ������: ��� ������ �, ��������� �� n ����������� �����. 
������� ������� �������, ����� ���� �������� ����������.
*/
//---------------------------------------------------------------------------//
// ���� �������
void Zadanie(int n, bool*c);
void main(int argc, char* argv[]) {
	// ���������� ����������
	int mass[100], n, sum = 0, buffer = 0, index;
	setlocale(0, "Russian");
	do {
		printf("������� ����������� ������: ");
		scanf("%d", &n);
	} while (n < 1 || n > 100);
	// ���������� �������
	for (int i = 0; i < n; i++) {
		printf("A[%d]",i);
		scanf("%d", &mass[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
	}
	for (int i = 0; i < n; i++) {
		do {
			sum += mass[i] % 10;
			mass[i] /= 10;
			
		} while (mass[i]);

		if (sum > buffer) {
			buffer = sum;
			index = i;
		}
		sum = 0;
	}
	printf("\n");
	printf("������� �������, ����� ���� �������� �����������[%d] = %d",index, buffer);
	getch();
	
}