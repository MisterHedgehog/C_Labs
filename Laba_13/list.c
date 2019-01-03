#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "time.h"
// Функция создания платежа
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
// Функция добавления платежа
void addPayment(Payment** list, char* surname, char* number, Date date, char* tarif, Time timeStart, Time timeFinish){
	for (; (*list) != NULL; list = &(*list)->next);
	*list = createPayment(surname, number, date, tarif, timeStart, timeFinish);
}
// Функция добавления платежа в начало (ссылка) -> [new] -> []->[]->[]->[]->[]->NULL
void addPaymentToFirst(Payment** list, char* surname, char* number, Date date, char* tarif, Time timeStart, Time timeFinish) {
	Payment* temp = createPayment(surname, number, date, tarif, timeStart, timeFinish);
	temp->next = (*list);
	(*list) = temp;
}
// Функция удаления платежа
void deletePayment(Payment** payment) {
	Payment* buffer = *payment;
	*payment = (*payment)->next;
	free(buffer);
}
// Функция освобождения памяти
void freeList(Payment* list) {
	for(; list != NULL; list = list->next)
		free(list);
}
// Функция вывода платежа в консоль
Payment* printPayment(Payment** payment) {
	printf("|| Пользователь %s:\n\n", (*payment)->surname);
	printf("** Номер: %s\n", (*payment)->number);
	printf("** Дата разговора: %02d.%02d.%04d\n", (*payment)->date.day, (*payment)->date.mounth, (*payment)->date.year);
	printf("** Тариф: %s\n", (*payment)->tarif);
	printf("** Начало разговора: %02d:%02d:%02d\n", (*payment)->timeStart.hour, (*payment)->timeStart.minute, (*payment)->timeStart.second);
	printf("** Конец разговора: %02d:%02d:%02d\n-------\n", (*payment)->timeFinish.hour, (*payment)->timeFinish.minute, (*payment)->timeFinish.second);
	*payment = (*payment)->next;
	return *payment;
}
// Функция вывода списка платежей в консоль
void printList(Payment* list) {
	printf("\nСписок платежей:\n-------\n");
	while (printPayment(&list));
	printf("\n");
}
// Функция нахождения платежа по фамилии
void findBySurname(Payment* list, char * surname){
	bool printed = false;
	printf("Результат поиска:\n");
	while (list)
		if (!strcmp(surname, list->surname)) {
			printPayment(&list);
			printed = true;
		}
		else {
			list = list->next;
		}
	if (!printed) {
		printf("Платёж отсутствует\n");
	}
}
// Функция нахождения платежа по дате разговора
void findByDate(Payment * list, Date d){
	bool printed = false;
	printf("Результат поиска:\n");
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
			printf("Платёж отсутствует\n");
		}
}
// Функция сортировки списка по фамилии
void sortBySurname(Payment ** list){
	if ((*list) == NULL) {
		printf("\n\nСписок пуст!\n\n");
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
// Функция сортировки списка по длительности разговора
void sortByDate(Payment ** list){
	if ((*list) == NULL) {
		printf("\n\nСписок пуст!\n\n");
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
// Функция вывода списка платежей в консоль, длительность разговора которых больше заданного
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