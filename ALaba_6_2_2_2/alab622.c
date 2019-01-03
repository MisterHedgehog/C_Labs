#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 6.2.2
������� ������ 61391
�������� �.�.
21.09.2018
���� ������: ���� ��������� ����� ���������� ������������ ����� n ���������
� ��������� ����� ������ ������ ����� �����, �� ��������� �����, �
��� ���� ������, ��� n. ������� ����� ��������� �� ����� �����, ��� ��������

*/
//---------------------------------------------------------------------------//
void Zadanie(float*);
//���� ���������
void main(int argc, char* argv[]) {
	float n = 105263157894736837;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	//��������� � �������
	Zadanie(&n);
	// ����� �����
	printf("������ �����: %f", n);
	getch();
}
void Zadanie(float*n) {
	// ���������� ����������
	float razradnost, zifra, chislo;
	long i = 105263157894736837;
	do {
		i++;
		razradnost = 1;
		chislo = i;
		zifra = i % 10;
		while (chislo) {
			chislo /= 10;
			razradnost *= 10;
		}
		printf("�����: %l", i);
		//������� ���������� �����
	} while ((long)(i / 10) + (long)(zifra * (long)(razradnost / 10)) != i * 2);
	*n = i;
}