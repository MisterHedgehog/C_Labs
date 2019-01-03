#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 11
учебной группы 61391
Волкова А.А.
Дата выполнения: 28.10.2018
Тема работы:  «Разработка, отладка и испытание алгоритмов и программ с использованием внутренних методов сортировки»
Задание: Отсортировать элементы квадратной вещественной матрицы размерности n, применив пузырьковую сортировку.
*/
//---------------------------------------------------------------------------//

// Данная функция сортирует элементы квадратной вещественной матрицы
void sortMatrix(int*);
// Устанавливает положение курсора в консоли 
void setCursorPosition(int, int);

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
			setCursorPosition(1 + x * 3, 2 + y);
			scanf("%d", matrix + y * n + x);

		}
	}
	// Вызов вспомогательной функции
	sortMatrix(matrix);
	// Вывод результата на экран
	printf("\nРезультат сортировки:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {

			setCursorPosition(1 + x * 3, n + 3 + y);
			printf("%d", matrix[y * n + x]);

		}
	}
	getch();
	// Освобождение памяти
	free(matrix);
}

void sortMatrix(int* matrix) {
	// n - количество элементов массива
	int buf, n = _msize(matrix)/sizeof(int);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (matrix[j] > matrix[j + 1])
			{
				buf = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = buf;
			}

}

void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}