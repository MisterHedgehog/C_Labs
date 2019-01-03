#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <windows.h>
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 10
учебной группы 61391
Волкова А.А.
Дата выполнения: 24.10.2018
Тема работы: «Разработка, отладка и испытание алгоритмов и программ обработки строк».
Общая задача для всех: построить таблицу аски.
*/
//---------------------------------------------------------------------------//

// Данная функция устанавливает положение курсора в консоли 
void setCursorPosition(int x, int y);

void main(int argc, char* argv[]) {
	char groups[100];
	int min;
	// Добавляем кириллицу в консоль
	setlocale(0, "Russian");
	// Вывод таблицы ASCII
	printf("Таблица ASCII:\n ");
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 64; y++) {
			setCursorPosition(x * 15, 2 + y);
			printf("%3.d : %3.c", x * 64 + y, (char)(x * 64 + y));
		}
	}
	getch();
}

void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}