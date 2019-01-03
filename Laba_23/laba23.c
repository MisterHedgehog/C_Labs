#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#define CAPACITY 300

#include <stdio.h>
#include <math.h>
#include <windows.h>

//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 23
учебной группы 61391
Волкова А.А.
Дата выполнения: 11.12.2018
Тема работы: «Разработка, отладка и испытание алгоритмов и программ генерирования случайных чисел».
Задание: Используя генератор случайных чисел, смоделировать процесс
заполнения зрительного зала кинотеатра на 300 мест. Зрительный зал
имеет вид прямоугольника N x M.
*/
//---------------------------------------------------------------------------//

// Устанавливает положение курсора в консоли 
void setCursorPosition(int x, int y);
// Функция возвращает случайное число от 100000
// @param значение - любое целое число от 100000 (желательно)
long int random(int значение);
// Функция выводит изображение кинотеатра и моделирует процесс заполнения зрительного зала
void drawCinema(long int);

void main() {
	setlocale(0, "Russian");
	long int rand;
	// Считывание первоначального значения
	printf("Введите начальное число:");
	scanf("%ld", &rand);
	// Запуск задания
	drawCinema(rand);
	getch();
}

void drawCinema(long int x) {
	// Изображение кинотеатра
			                printf("\n      |-------------Экран------------|\n");
			                  printf("      |------------------------------|\n");
for (int i = 1; i < 11; i++)printf("ряд %2.d|                              |\n",i);
			                  printf("      |------------------------------|");
	_Bool taken[CAPACITY]; // Занятые места
	for (int i = 0; i < CAPACITY; i++) {
		x = random(x);     // Вычисление случайного числа
		// Нахождение ещё не занятого места
		while (!taken[(++x) % CAPACITY]);
		int place = x % CAPACITY; // Незанятое место
		taken[place] = 0;
		// Определение позиции незанятого места и отметка его
		setCursorPosition(7 + place / 10, 4 + place % 10);
		printf("*");
		// Задержка на 67 миллисекунд
		Sleep(67);
	}
}

// Функция заполнение исходных данных методом середины квадрата
long int random(int x) {
	// на вход поступает число x = 283283
	int k = 0;
	float resultf = (float)x * (float)x; // resultf = 080249257984,0
	do {
		k++;			// Определение количества разрядов входного числа x (k = 6)
	} while (x /= 10);
	resultf /= pow(10, k / 2);  // 080249257  984 Отделение правой части
	long int result = (long int)resultf % (long int)pow(10, k); // 080  249257 Отделение левой части
	return result > 99999 ? result : result + 100000;
}
// Устанавливает положение курсора в консоли 
void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
