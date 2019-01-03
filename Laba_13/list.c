#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "time.h"
// ������� �������� �������
Payment* createPayment(char* surname, char* number, Date date, char* tarif, Time timeStart, Time timeFinish) {
	Payment* payment = malloc(sizeof(Payment));
	(*payment).surname = surname;
	payment->number = number;
	payment->date = date;
	payment->tarif = tarif;
	payment->timeStart = timeStart;
	payment->timeFinish = timeFinish;
	payment->next = NULL;
	int tStart = timeStart.second + timeStart.minute * 60 + timeStart.hour * 24 * 60;
	int tFinish = timeFinish.second + timeFinish.minute * 60 + timeFinish.hour * 24 * 60;
	payment->timeLength = tFinish - tStart;
	return payment;
}
// ������� ���������� �������
void addPayment(Payment** list, char* surname, char* number, Date date, char* tarif, Time timeStart, Time timeFinish){
	for (; (*list) != NULL; list = &(*list)->next);
	*list = createPayment(surname, number, date, tarif, timeStart, timeFinish);
}
// ������� ���������� ������� � ������ (������) -> [new] -> []->[]->[]->[]->[]->NULL
void addPaymentToFirst(Payment** list, char* surname, char* number, Date date, char* tarif, Time timeStart, Time timeFinish) {
	Payment* temp = createPayment(surname, number, date, tarif, timeStart, timeFinish);
	temp->next = (*list);
	(*list) = temp;
}
// ������� �������� �������
void deletePayment(Payment** payment) {
	Payment* buffer = *payment;
	*payment = (*payment)->next;
	free(buffer);
}
// ������� ������������ ������
void freeList(Payment* list) {
	for(; list != NULL; list = list->next)
		free(list);
}
// ������� ������ ������� � �������
Payment* printPayment(Payment** payment) {
	printf("|| ������������ %s:\n\n", (*payment)->surname);
	printf("** �����: %s\n", (*payment)->number);
	printf("** ���� ���������: %02d.%02d.%04d\n", (*payment)->date.day, (*payment)->date.mounth, (*payment)->date.year);
	printf("** �����: %s\n", (*payment)->tarif);
	printf("** ������ ���������: %02d:%02d:%02d\n", (*payment)->timeStart.hour, (*payment)->timeStart.minute, (*payment)->timeStart.second);
	printf("** ����� ���������: %02d:%02d:%02d\n-------\n", (*payment)->timeFinish.hour, (*payment)->timeFinish.minute, (*payment)->timeFinish.second);
	*payment = (*payment)->next;
	return *payment;
}
// ������� ������ ������ �������� � �������
void printList(Payment* list) {
	printf("\n������ ��������:\n-------\n");
	while (printPayment(&list));
	printf("\n");
}
// ������� ���������� ������� �� �������
void findBySurname(Payment* list, char * surname){
	bool printed = false;
	printf("��������� ������:\n");
	while (list)
		if (!strcmp(surname, list->surname)) {
			printPayment(&list);
			printed = true;
		}
		else {
			list = list->next;
		}
	if (!printed) {
		printf("����� �����������\n");
	}
}
// ������� ���������� ������� �� ���� ���������
void findByDate(Payment * list, Date d){
	bool printed = false;
	printf("��������� ������:\n");
	while (list) {
		if (list->date.year == d.year && list->date.mounth == d.mounth && list->date.day == d.day) {
			//printf("%d == %d \n", talkTime(*list), length);
			printPayment(&list);
			printed = true;
		}
		else {
			//printf("%d != %d \n", talkTime(*list), length);
			list = list->next;
		}
	}
		if (!printed) {
			printf("����� �����������\n");
		}
}
// ������� ���������� ������ �� �������
void sortBySurname(Payment ** list){
	if ((*list) == NULL) {
		printf("\n\n������ ����!\n\n");
		return;
	}
	Payment ** buffer = list;
	int size = 0;
	for (; (*buffer)->next != NULL; size++, buffer = &(*buffer)->next);
	//printf("%d", size);
	buffer = list;
	for (; size > 0; size--) {
		list = buffer;
		for (Payment * pre = NULL; /**/ (*list)->next != NULL; /**/ pre = *list, list = &(*list)->next) {
			Payment* third = (*list)->next->next;
			Payment* second = (*list)->next;
			if (strcmp((*list)->surname, ((*list)->next)->surname) > 0) {
				(*((*list)->next)).next = *list;
				(*(*list)).next = third;
				if (pre != NULL) pre->next = second;
				else *buffer = second;
			}
		}
	}
}
// ������� ���������� ������ �� ������������ ���������
void sortByDate(Payment ** list){
	if ((*list) == NULL) {
		printf("\n\n������ ����!\n\n");
		return;
	}
	Payment ** buffer = list;
	int size = 0;
	for (; (*buffer)->next != NULL; size++, buffer = &(*buffer)->next);
	buffer = list;
	for (; size > 0; size--) {
		list = buffer;
		for (Payment * pre = NULL; /**/ (*list)->next != NULL; /**/ pre = *list, list = &(*list)->next) {
			Payment* third = (*list)->next->next;
			Payment* second = (*list)->next;
			if ( (*list)->date.year > ((*list)->next)->date.year ||
				(*list)->date.mounth > ((*list)->next)->date.mounth ||
				(*list)->date.day > ((*list)->next)->date.day) {
				(*((*list)->next)).next = *list;
				(*(*list)).next = third;
				if (pre != NULL) pre->next = second;
				else *buffer = second;
			}
		}
	}
}
// ������� ������ ������ �������� � �������, ������������ ��������� ������� ������ ���������
void printLongerThen(Payment* list, Time t) {
	int length = t.second + t.minute * 60 + t.hour * 24 * 60;
	while (list)
		if (list->timeLength > length) {
			printPayment(&list);
		}
		else {
			list = list->next;
		}
}