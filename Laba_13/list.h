#pragma once
#ifndef LIST_H
#define LIST_H
#include "time.h"
// ���������, ����������� �����
typedef struct Payment{
	char* surname;
	char* number;
	Date date;
	char* tarif;
	Time timeStart;
	Time timeFinish;
	int timeLength;
	struct Payment* next;
} Payment;
// ������� �������� �������
Payment* createPayment(
	char* �������_������������,
	char* �����,
	Date ����_���������,
	char* �����,
	Time ������_���������,
	Time �����_���������);
// ������� ���������� �������
void addPayment(
	Payment** ������_��������, 
	char* �������_������������,
	char* �����,
	Date ����_���������,
	char* �����,
	Time ������_���������,
	Time �����_���������);
// ������� ���������� ������� � ������ (������) -> [new] -> []->[]->[]->[]->[]->NULL
void addPaymentToFirst(
	Payment** ������_��������,
	char* �������_������������,
	char* �����,
	Date ����_���������,
	char* �����,
	Time ������_���������,
	Time �����_���������);
// ������� �������� �������
void deletePayment(Payment** �����);
// ������� ������������ ������
void freeList(Payment* ������);
// ������� ������ ������� � �������
Payment* printPayment(Payment** �����);
// ������� ������ ������ �������� � �������
void printList(Payment* ������);
// ������� ������ ������ �������� � �������, ������������ ��������� ������� ������ ���������
void printLongerThen(Payment* ������, Time �����_���������);
// ������� ���������� ������� �� �������
void findBySurname(Payment* ������, char* �������);
// ������� ���������� ������� �� ������������ ���������
void findByDate(Payment* ������, Date ����_���������);
// ������� ���������� ������ �� �������
void sortBySurname(Payment** ������);
// ������� ���������� ������ �� ������������ ���������
void sortByDate(Payment** ������);
#endif
