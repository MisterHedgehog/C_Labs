#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "time.h"
// Функция создания даты
Date createDate(int year, int mounth, int day) {
	Date result;
	result.year = year;
	result.mounth = mounth;
	result.day = day;
	return result;
}
// Функция создания время
Time createTime(int hour, int minute, int second) {
	Time result;
	result.hour = hour;
	result.minute = minute;
	result.second = second;
	return result;
}
// Функция преобразования строки в форате дд.мм.гггг в дату
Date formatStringToDate(char* date) {
	int day = fromChar(date[1]) + fromChar(date[0]) * 10;
	int mounth = fromChar(date[4]) + fromChar(date[3]) * 10;
	int year = fromChar(date[9]) + fromChar(date[8]) * 10 + fromChar(date[7]) * 100 + fromChar(date[6]) * 1000;
	return createDate(year, mounth, day);
}
// Функция преобразования строки в форате чч.мм.сс в время
Time formatStringToTime(char * time){
	int hour = fromChar(time[1]) + fromChar(time[0]) * 10;
	int min = fromChar(time[4]) + fromChar(time[3]) * 10;
	int sec = fromChar(time[6]) + fromChar(time[7]) * 10;
	return createTime(hour, min, sec);
}
// Функция преобразования символа в число
int fromChar(char input) {
	//char f = '4';
	switch (input) {
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	default: return 9;
	}
}