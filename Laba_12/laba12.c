#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 12
учебной группы 61391
Волкова А.А.
Дата выполнения: 28.10.2018
Тема работы: «Разработка, отладка и испытание алгоритмов и программ обработки динамических массивов»
Задание: Дана действительная квадратная матрица порядка n. Найдите сумму элементов, расположенных в заштрихованной части матрицы.
													_________
												   |        /|
												   |      ///|
												   |    /////|
												   |_////////|
*/
//---------------------------------------------------------------------------//

// Данная функция вычисляет сумму элементов под побочной диагональю матрицы
int elememtsSum(int*);
// Данная функция устанавливает положение курсора в консоли 
void SetCursorPosition(int, int);

void main(int argc, char* argv[]) {
	int *matrix, n, result;
	// Добавляем кириллицу в консоль
	setlocale(0, "Russian");
	// Ввод данных
	do {
		printf("Введите размерность матриц: ");
		scanf("%d", &n);
	} while (n < 1);
	// Выделение памяти под массив
	matrix = malloc(n * n * sizeof(int));
	// Заполнение матрицы
	printf("Элементы матрицы:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			SetCursorPosition(1 + x * 3, 2 + y);
			scanf("%d", matrix + y * n + x);

		}
	}
	// Вызов вспомогательной функции
	result = elememtsSum(matrix);
	// Вывод результата на экран
	printf("\nРезультат сложения элементов заштрихованной области: %d", result);
	getch();
	// Освобождение памяти
	free(matrix);
}

int elememtsSum(int* matrix) {
	// Определяем размерность матрицы
	int n = sqrt(_msize(matrix) / sizeof(int));
	int sum = 0;
	// Сложение элементов матрицы
	for (int y = 0; y < n; y++) {
		for (int x = n - 1; x >= n - y - 1; x--) {
			sum += matrix[y*n + x];
		}
	}
	return sum;
}
void SetCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}