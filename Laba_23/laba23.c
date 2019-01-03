#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#define CAPACITY 300

#include <stdio.h>
#include <math.h>
#include <windows.h>

//---------------------------------------------------------------------------//
/*
				������������ ������ � 23
������� ������ 61391
������� �.�.
���� ����������: 11.12.2018
���� ������: �����������, ������� � ��������� ���������� � �������� ������������� ��������� �����.
�������: ��������� ��������� ��������� �����, ������������� �������
���������� ����������� ���� ���������� �� 300 ����. ���������� ���
����� ��� �������������� N x M.
*/
//---------------------------------------------------------------------------//

// ������������� ��������� ������� � ������� 
void setCursorPosition(int x, int y);
// ������� ���������� ��������� ����� �� 100000
// @param �������� - ����� ����� ����� �� 100000 (����������)
long int random(int ��������);
// ������� ������� ����������� ���������� � ���������� ������� ���������� ����������� ����
void drawCinema(long int);

void main() {
	setlocale(0, "Russian");
	long int rand;
	// ���������� ��������������� ��������
	printf("������� ��������� �����:");
	scanf("%ld", &rand);
	// ������ �������
	drawCinema(rand);
	getch();
}

void drawCinema(long int x) {
	// ����������� ����������
			                printf("\n      |-------------�����------------|\n");
			                  printf("      |------------------------------|\n");
for (int i = 1; i < 11; i++)printf("��� %2.d|                              |\n",i);
			                  printf("      |------------------------------|");
	_Bool taken[CAPACITY]; // ������� �����
	for (int i = 0; i < CAPACITY; i++) {
		x = random(x);     // ���������� ���������� �����
		// ���������� ��� �� �������� �����
		while (!taken[(++x) % CAPACITY]);
		int place = x % CAPACITY; // ��������� �����
		taken[place] = 0;
		// ����������� ������� ���������� ����� � ������� ���
		setCursorPosition(7 + place / 10, 4 + place % 10);
		printf("*");
		// �������� �� 67 �����������
		Sleep(67);
	}
}

// ������� ���������� �������� ������ ������� �������� ��������
long int random(int x) {
	// �� ���� ��������� ����� x = 283283
	int k = 0;
	float resultf = (float)x * (float)x; // resultf = 080249257984,0
	do {
		k++;			// ����������� ���������� �������� �������� ����� x (k = 6)
	} while (x /= 10);
	resultf /= pow(10, k / 2);  // 080249257  984 ��������� ������ �����
	long int result = (long int)resultf % (long int)pow(10, k); // 080  249257 ��������� ����� �����
	return result > 99999 ? result : result + 100000;
}
// ������������� ��������� ������� � ������� 
void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
