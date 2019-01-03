#pragma once
#ifndef LIST_H
#define LIST_H
#include "time.h"
// Структура, описывающая платёж
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
// Функция создания платежа
Payment* createPayment(
	char* Фамилия_Пользователя,
	char* Номер,
	Date Дата_разговора,
	char* Тариф,
	Time Начало_разговора,
	Time Конец_Разговора);
// Функция добавления платежа
void addPayment(
	Payment** Список_Платежей, 
	char* Фамилия_Пользователя,
	char* Номер,
	Date Дата_разговора,
	char* Тариф,
	Time Начало_разговора,
	Time Конец_Разговора);
// Функция добавления платежа в начало (ссылка) -> [new] -> []->[]->[]->[]->[]->NULL
void addPaymentToFirst(
	Payment** Список_Платежей,
	char* Фамилия_Пользователя,
	char* Номер,
	Date Дата_разговора,
	char* Тариф,
	Time Начало_разговора,
	Time Конец_Разговора);
// Функция удаления платежа
void deletePayment(Payment** Платёж);
// Функция освобождения памяти
void freeList(Payment* Список);
// Функция вывода платежа в консоль
Payment* printPayment(Payment** Платёж);
// Функция вывода списка платежей в консоль
void printList(Payment* Список);
// Функция вывода списка платежей в консоль, длительность разговора которых больше заданного
void printLongerThen(Payment* Список, Time Время_разговора);
// Функция нахождения платежа по фамилии
void findBySurname(Payment* Список, char* Фамилия);
// Функция нахождения платежа по длительности разговора
void findByDate(Payment* Список, Date Дата_разговора);
// Функция сортировки списка по фамилии
void sortBySurname(Payment** Список);
// Функция сортировки списка по длительности разговора
void sortByDate(Payment** Список);
#endif
