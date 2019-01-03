#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 9.1
учебной группы 61391
Аббасова А.А.
Дата выполнения: 21.12.2018
Тема работы: «Разработка, отладка и испытание алгоритмов и программ обработки многомерных массивов»
Задание: Найдите произведение вектора на матрицу.
*/
//---------------------------------------------------------------------------//

// Вычисляет сумму элементов под побочной диагональю матрицы
void proizvedenie(int[10][10], int[10], int);

void main(int argc, char* argv[]) {
	int matrix[10][10], vector[10], n, result;
	// Добавляем кириллицу в консоль
	setlocale(0, "Russian");
	// Ввод данных



	do {
		printf("Введите размерность матриц: ");
		scanf("%d", &n);
	} while (n < 1 || n > 10);
	// Заполнение матрицы
	printf("\nЗаполнение матрицы:\n");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printf("Элемент [%d][%d]: ",y,x);
			scanf("%d", &matrix[y][x]);
		}
	}
	printf("\nЭлементы вектора:\n");
	for (int y = 0; y < n; y++) {
		printf("Элемент [%d]:", y);
		scanf("%d", &vector[y]);
	}
	printf("\nЭлементы матрицы:\n");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printf("%3d", matrix[y][x]);
		}
		printf("|%3d\n", vector[y]);
	}
	// Вызов вспомогательной функции
	proizvedenie(matrix, vector, n);
	// Вывод результата на экран
	printf("\nЭлементы матрицы:\n");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printf("%3d", matrix[y][x]);
		}
		printf("\n");
	}
	getch();
}

void proizvedenie(int mat[10][10], int vec[10], int n) {
	for (int i = 0; i < n; i++) {
		for (int c = 0; c < n; c++) {
			mat[i][c] *= vec[i];
		}
	}
}