#include <stdio.h>
#include <math.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 2.1
������� ������ 61391
������� �.�.
14.09.2018
���� ������: "����������, ������� � ��������� ���������� ���������� � ��������"
���� ������: ������� �������� ���������.
��������� ������: ������� �� ��������, ���, ����� ���������� Dev C++ ��� Bolder C++ .
*/
//---------------------------------------------------------------------------//

void main(int argc, char* argv[]) {
	// ���� ������� �������
	float radius, side, x, y;		   // �������������� ����������
	setlocale(0, "Russian");          // ��������� ��������� � �������
	printf("�������:\n ���� ������ ����� � ������� ��������. ���������, ������� �� ������� � ����.\n");    // ������� �������
	printf("������� ������ �����. \n");
	scanf_s("%f", &radius);            // ��������� ������
	while (radius <= 0) {              // ������� �������������� ����������
		printf("����� ������ ���� ������ ����. \n");
		scanf_s("%f", &radius);
	}
	printf("������� ������� ��������. \n");
	scanf_s("%f", &side);              // ��������� ������� ��������
	while (side <= 0) {                // ������� �������������� ����������
		printf("������� ������� ������ ���� ������ �����. \n");
		scanf_s("%f", &side);
	}
	// �������� �������� � ������� ��������������� ���������
	if (radius * 2 > side * sqrt(2)) {  
		printf("������� ������ � ����. \n");
	}
	else {
		printf("������� �� ������ � ����. \n");
	}
	getch();
}