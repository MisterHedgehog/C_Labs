#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
/* ������������ ������ �7
   ��������� ������ 61391
   �������� ��������
   ������� 1
   �������: ����� ������� ������������ ��� �������� ����������� ������
*/

#include <stdio.h>
#include <math.h>
// ���� �������
float otvet(int x1,int x2,int x3,int y1,int y2,int y3);
void main(int argc, char* argv[]) {
	//���������� ����������
	int x1, x2, x3, y1, y2, y3;
	float s;
	//���� �������� ������
	printf("Vvedite x1, y1 \n");
	scanf("  %d", &x1);
	scanf("  %d", &y1);
	printf("Vvedite x2, y2 \n");
	scanf("  %d", &x2);
	scanf("  %d", &y2);
	printf("Vvedite x3, y3 \n");
	scanf("  %d", &x3);
	scanf("  %d", &y3);
	//����� �������� �� �����
	s = otvet(x1, x2, x3, y1, y2, y3);
	printf("   S = %.3f cm^2", s);
	getch();
}

float otvet(int x1, int x2, int x3, int y1, int y2, int y3) {
	//������ ������ ������������ � ����� �� �������� �� �����
	float a = sqrt((pow((y1 - y2), 2)) + (pow((x1 - x2), 2)));
	float b = sqrt((pow((y2 - y3), 2)) + (pow((x2 - x3), 2)));
	float c = sqrt((pow((y3 - y1), 2)) + (pow((x3 - x1), 2)));
	//���������� ��������� � ����� ��� �� �����
	float p = (a + b + c) / 2;
	//���������� ������� ������������ � ����� ��� �� �����
	return sqrt(p*(p - a)*(p - b)*(p - c));
}