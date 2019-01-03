#pragma once
#ifndef TIME_H
#define TIME_H
// Структура, описывающая дату
typedef struct Date {
	int year;
	int mounth;
	int day;
} Date;
// Структура, описывающая время
typedef struct Time {
	int hour;
	int minute;
	int second;
} Time;
// Функция создания даты
Date createDate(int Год, int Месяц, int День);
// Функция создания время
Time createTime(int Час, int Минута, int Секунда);
// Функция преобразования строки в форате дд.мм.гггг в дату
Date formatStringToDate(char* Строка);
// Функция преобразования строки в форате дд.мм.гггг в дату
Time formatStringToTime(char* Строка);
// Функция преобразования символа в число
int fromChar(char Символ);
#endif