#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <string.h>
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 10
учебной группы 61391
Волкова А.А.
Дата выполнения: 24.10.2018
Тема работы: «Разработка, отладка и испытание алгоритмов и программ обработки строк».
Задание: Дана строка, состоящая из групп нулей и единиц, разделенных пробелами.
Найдите и выведите на экран самую короткую группу.
*/
//---------------------------------------------------------------------------//

// Определяет индекс первого символа кротчайшей группы строки
int indexOfShortestGroup(char*);

void main(int argc, char* argv[]) {
	char groups[100];
	 int min;
	// Добавляем кириллицу в консоль
	setlocale(0, "Russian");
	// Ввод строки
	printf("Введите строку\n");
	gets(groups);
	// Вызов вспомогательной функции
	min = indexOfShortestGroup(groups);
	// Вывод группы символов на экран
	printf("Самая короткая группа: ");
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