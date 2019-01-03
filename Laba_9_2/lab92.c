#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 9.2
учебной группы 61391
Волкова А.А.
Дата выполнения: 24.10.2018
Тема работы: «Разработка, отладка и испытание алгоритмов и программ обработки многомерных массивов»
Задание: Дана действительная квадратная матрица порядка n. Найдите сумму элементов, расположенных в заштрихованной части матрицы.
                                                    _________
                                                   |        /|
                                                   |      ///|
                                                   |    /////|
                                                   |_////////|
*/
//---------------------------------------------------------------------------//

// Вычисляет сумму элементов под побочной диагональю матрицы
int elementsSum(int[10][10], int);
// Устанавливает положение курсора в консоли 
void setCursorPosition(int, int);

void main(int argc, char* argv[]) {
	int matrix[10][10], n, result;
	// Добавляем кириллицу в консоль
	setlocale(0, "Russian");
	// Ввод данных
	do {
		printf("Введите размерность матриц: ");
		scanf("%d", &n);
	} while (n < 1 || n > 10);
	// Заполнение матрицы
	printf("Элементы матрицы:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, 2 + y);
			scanf("%d", &matrix[y][x]);
			
		}
	}
	// Вызов вспомогательной функции
	result = elementsSum(matrix, n);
	// Вывод результата на экран
	printf("\nРезультат сложения элементов заштрихованной области: %d", result);
	getch();
}

int elementsSum(int matrix[10][10], int n) {
	int sum = 0;
	// Сложение элементов матрицы
	for (int y = 0; y < n; y++) {
		for (int x = n - 1; x > n - y - 2; x--) {
			sum += matrix[y][x];
		}
	}
	return sum;
}
void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}