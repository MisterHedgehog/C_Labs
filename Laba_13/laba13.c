#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#include "list.h"
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 13
учебной группы 61391
Волкова А.А.
Дата выполнения: 29.10.2018
Тема работы: «Разработка, отладка и испытание программ обработки односвязного и двусвязного списков»
Задание: Разовый платеж за телефонный разговор является структурой с полями:
  1. фамилия плательщика
  2. номер телефона 
  3. дата разговора 
  4. тариф за минуту разговора
  5. время начала разговора 
  6. время окончания разговора
  Поиск и сортировка - по фамилии плательщика, дате разговора.
  Найти все разговоры со временем разговора больше заданного.
*/
//---------------------------------------------------------------------------//

void main(int argc, char* argv[]) {
	// Добавляем кириллицу в консоль
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Payment* list = NULL;
	int input;
	char surname[40], number[15], tarif[20], date[15], timeStart[15], timeFinish[15];
	do {
		printf("Выберите режим работы:\n\n");
		printf("0 - Заполнение списка платежей\n");
		printf("1 - Добавление платежа\n");
		printf("2 - Сортировка по дате разговора\n");
		printf("3 - Сортировка по фамилии\n");
		printf("4 - Поиск по дате разговора\n");
		printf("5 - Поиск по фамилии\n");
		printf("6 - Вывод платежей в консоль\n");
		printf("7 - Вывод платежей в консоль, длительность разговора которых длиннее заданного\n");
		printf("8 - Выход\n");
		do {
			scanf("%d", &input);
		} while (input < 0 || input > 10);
		switch (input)
		{
			// Добавление платежей
		case 0: 
			addPayment(&list,"Болконский", "+375295423687", createDate(2000, 04, 27), "Лето", createTime(12, 37, 45), createTime(13, 54, 45));
			addPayment(&list, "Ростова", "+375445498675", createDate(2001, 05, 23), "Весна", createTime(11, 35, 47), createTime(23, 54, 45));
			addPayment(&list, "Безухов", "+375254898675", createDate(2018, 12, 03), "Зима", createTime(13, 14, 15), createTime(17, 16, 02));
			addPayment(&list, "Друбецкой", "+375295498675", createDate(2017, 13, 03), "Осень", createTime(11, 14, 15), createTime(17, 16, 02));
			addPayment(&list, "Курагин", "+375445487675", createDate(2001, 05, 23), "Про_вариант", createTime(11, 35, 47), createTime(23, 54, 45));
			addPayment(&list, "Денисов", "+375295423687", createDate(2000, 04, 27), "Комфорт", createTime(12, 37, 45), createTime(13, 54, 45));
			printf("\n\nДобавлено 6 пользователей в список:\n\n");
			printList(list);
			break;
			// Добавление платежа
		case 1:
			printf("Введите фамилию плательщика\n");
			scanf("%s", surname);
			printf("Введите номер телефона\n");
			scanf("%s", number);
			printf("Введите тариф\n");
			scanf("%s", tarif);
			printf("Введите дату в формате дд.мм.гггг\n");
			scanf("%s", date);
			printf("Введите время начала разговора в формате чч.мм.сс\n");
			scanf("%s", timeStart);
			printf("Введите время конца разговора в формате чч.мм.сс\n");
			scanf("%s", timeFinish);
			addPayment(&list, surname, number, formatStringToDate(date), tarif, formatStringToTime(timeStart), formatStringToTime(timeFinish));
			printf("\n\nПлатёж добавлен!\n\n");
			break;
			// Сортировка по дате разговора
		case 2:
			sortByDate(&list);
			printf("Список отсортирован по дате разговора!\n\n");
			break;
			// Сортировка по фамилии
		case 3:
			sortBySurname(&list);
			printf("Список отсортирован по фамилиям!\n\n");
			break;
			// Поиск по дате разговора
		case 4:
			printf("Введите дату разговора в формате дд.мм.гггг\n");
			scanf("%s", timeStart);
			findByDate(list, formatStringToDate(timeStart));
			break;
			// Поиск по фамилии
		case 5:
			printf("Введите фамилию плательщика\n");
			scanf("%s", surname);
			findBySurname(list, surname);
			break;
			// Вывод платежей в консоль
		case 6:
			printList(list);
			break;
			// Вывод платежей в консоль, длительность разговора которых длиннее заданного
		case 7:
			printf("Введите время разговора в формате чч.мм.сс\n");
			scanf("%s", timeStart);
			printLongerThen(list, formatStringToTime(timeStart));
			break;
			// Выход
		case 8: return;
		}
	} while (1);
	getch();
}