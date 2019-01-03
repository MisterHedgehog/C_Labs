#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 9.1
учебной группы 61391
Волкова А.А.
Дата выполнения: 20.10.2018
Тема работы: «Разработка, отладка и испытание алгоритмов и программ обработки многомерных массивов»
Задание: Сложите две треугольные матрицы порядка n, у которых только элементы над главной диагональю отличны от нуля.
*/
//---------------------------------------------------------------------------//

// Данная функция к верхнему треугольнику первой матрицы прибавляет верхний треугольник второй матрицы
void sumOfMatrixRect(int[10][10], int[10][10], int);
// Данная функция устанавливает положение курсора в консоли 
void setCursorPosition(int, int);

void main(int argc, char* argv[]) {
	int matrix1[10][10], matrix2[10][10], n;
	// Добавляем кириллицу в консоль
	setlocale(0, "Russian");
	// Ввод данных
	do {
		printf("Введите размерность матриц: ");
		scanf("%d", &n);
	} while (n < 1 || n > 10);
	// Заполнение верхнего треугольника первой матрицы
	printf("Первая матрица:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, 2 + y);
			if (x > y) {
				scanf("%d", &matrix1[y][x]);
			}
			else {
				printf("0");
				matrix1[y][x] = 0;
			}
		}
	}
	// Заполнение верхнего треугольника второй матрицы
	printf("\n\nВторая матрица:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, n + 4 + y);
			if (x > y) {
				scanf("%d", &matrix2[y][x]);
			}
			else {
				printf("0");
				matrix2[y][x] = 0;
			}
		}
	}
	// Вызов вспомогательной функции
	sumOfMatrixRect(matrix1, matrix2, n);
	// Вывод результата на экран
	printf("\n\nРезультат сложения матриц:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, n * 2 + 6 + y);
			printf("%d", matrix1[y][x]);
		}
	}
	getch();
}

void sumOfMatrixRect(int matrix1[10][10], int matrix2[10][10], int n) {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			matrix1[y][x] += matrix2[y][x];
		}
	}
}
void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}