#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#include "list.h"
//---------------------------------------------------------------------------//
/*
				������������ ������ � 13
������� ������ 61391
������� �.�.
���� ����������: 29.10.2018
���� ������: �����������, ������� � ��������� �������� ��������� ������������ � ����������� �������
�������: ������� ������ �� ���������� �������� �������� ���������� � ������:
  1. ������� �����������
  2. ����� �������� 
  3. ���� ��������� 
  4. ����� �� ������ ���������
  5. ����� ������ ��������� 
  6. ����� ��������� ���������
  ����� � ���������� - �� ������� �����������, ���� ���������.
  ����� ��� ��������� �� �������� ��������� ������ ���������.
*/
//---------------------------------------------------------------------------//

void main(int argc, char* argv[]) {
	// ��������� ��������� � �������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Payment* list = NULL;
	int input;
	char surname[40], number[15], tarif[20], date[15], timeStart[15], timeFinish[15];
	do {
		printf("�������� ����� ������:\n\n");
		printf("0 - ���������� ������ ��������\n");
		printf("1 - ���������� �������\n");
		printf("2 - ���������� �� ���� ���������\n");
		printf("3 - ���������� �� �������\n");
		printf("4 - ����� �� ���� ���������\n");
		printf("5 - ����� �� �������\n");
		printf("6 - ����� �������� � �������\n");
		printf("7 - ����� �������� � �������, ������������ ��������� ������� ������� ���������\n");
		printf("8 - �����\n");
		do {
			scanf("%d", &input);
		} while (input < 0 || input > 10);
		switch (input)
		{
			// ���������� ��������
		case 0: 
			addPayment(&list,"����������", "+375295423687", createDate(2000, 04, 27), "����", createTime(12, 37, 45), createTime(13, 54, 45));
			addPayment(&list, "�������", "+375445498675", createDate(2001, 05, 23), "�����", createTime(11, 35, 47), createTime(23, 54, 45));
			addPayment(&list, "�������", "+375254898675", createDate(2018, 12, 03), "����", createTime(13, 14, 15), createTime(17, 16, 02));
			addPayment(&list, "���������", "+375295498675", createDate(2017, 13, 03), "�����", createTime(11, 14, 15), createTime(17, 16, 02));
			addPayment(&list, "�������", "+375445487675", createDate(2001, 05, 23), "���_�������", createTime(11, 35, 47), createTime(23, 54, 45));
			addPayment(&list, "�������", "+375295423687", createDate(2000, 04, 27), "�������", createTime(12, 37, 45), createTime(13, 54, 45));
			printf("\n\n��������� 6 ������������� � ������:\n\n");
			printList(list);
			break;
			// ���������� �������
		case 1:
			printf("������� ������� �����������\n");
			scanf("%s", surname);
			printf("������� ����� ��������\n");
			scanf("%s", number);
			printf("������� �����\n");
			scanf("%s", tarif);
			printf("������� ���� � ������� ��.��.����\n");
			scanf("%s", date);
			printf("������� ����� ������ ��������� � ������� ��.��.��\n");
			scanf("%s", timeStart);
			printf("������� ����� ����� ��������� � ������� ��.��.��\n");
			scanf("%s", timeFinish);
			addPayment(&list, surname, number, formatStringToDate(date), tarif, formatStringToTime(timeStart), formatStringToTime(timeFinish));
			printf("\n\n����� ��������!\n\n");
			break;
			// ���������� �� ���� ���������
		case 2:
			sortByDate(&list);
			printf("������ ������������ �� ���� ���������!\n\n");
			break;
			// ���������� �� �������
		case 3:
			sortBySurname(&list);
			printf("������ ������������ �� ��������!\n\n");
			break;
			// ����� �� ���� ���������
		case 4:
			printf("������� ���� ��������� � ������� ��.��.����\n");
			scanf("%s", timeStart);
			findByDate(list, formatStringToDate(timeStart));
			break;
			// ����� �� �������
		case 5:
			printf("������� ������� �����������\n");
			scanf("%s", surname);
			findBySurname(list, surname);
			break;
			// ����� �������� � �������
		case 6:
			printList(list);
			break;
			// ����� �������� � �������, ������������ ��������� ������� ������� ���������
		case 7:
			printf("������� ����� ��������� � ������� ��.��.��\n");
			scanf("%s", timeStart);
			printLongerThen(list, formatStringToTime(timeStart));
			break;
			// �����
		case 8: return;
		}
	} while (1);
	getch();
}