#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <string.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 10
������� ������ 61391
������� �.�.
���� ����������: 24.10.2018
���� ������: �����������, ������� � ��������� ���������� � �������� ��������� �����.
�������: ���� ������, ��������� �� ����� ����� � ������, ����������� ���������.
������� � �������� �� ����� ����� �������� ������.
*/
//---------------------------------------------------------------------------//

// ���������� ������ ������� ������� ���������� ������ ������
int indexOfShortestGroup(char*);

void main(int argc, char* argv[]) {
	char groups[100];
	 int min;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ���� ������
	printf("������� ������\n");
	gets(groups);
	// ����� ��������������� �������
	min = indexOfShortestGroup(groups);
	// ����� ������ �������� �� �����
	printf("����� �������� ������: ");
	while (groups[min] != ' ' && groups[min] != '\0') {
		printf("%c", groups[min]);
		min++;
	}
	getch();
}

int indexOfShortestGroup(char* groups) {
	int n = 1, min, x = strlen(groups);
	for (int i = 0; groups[i] != '\0'; i++)
	{
		if (groups[i + 1] == ' ' || groups[i + 1] == '\0') {
			if (n > 0 && n < x) {
				x = n;
				min = i - n + 1;
			}
			n = 0;
		}
		else {
			n++;
		}
	}
	return min;
}