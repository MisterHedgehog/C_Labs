#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <math.h>
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
void copy(int*, int*);
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
	printf("Элементы матрицы:");
	matrix = malloc(n * n * sizeof(int));
		// Заполнение матрицы
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3 , 2 + y);
			matrix[y * n + x] = rand() % 100;
			printf("%d", matrix[y * n + x]);

		}
	}
	// Вызов вспомогательной функции
	sortMatrix(matrix);
	// Вывод результата на экран
	printf("\nРезультат сортировки:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, n + 32 + y);
			printf("%d", matrix[y * n + x]);
		}
	}
	getch();
	// Освобождение памяти
	free(matrix);
}

void sortMatrix(int*matrix) {
	// n - количество элементов массива
	int i, j, times, steps, buf, n = _msize(matrix) / sizeof(int);
	times = 0;
	steps = 0;
	// Создаём копию массива
	int*sorted = malloc(_msize(matrix));
	// Модифицированный пузырёк
	copy(sorted, matrix);
	i = n;
	int f, k;
	do {
		f = 0;
		for (k = 0; k < i - 1; k++) {
			times++;
			if (sorted[k] > sorted[k + 1])
			{
				steps += 3;
				buf = sorted[k];
				sorted[k] = sorted[k + 1];
				sorted[k + 1] = buf;
				f = 1;
			}
		}
		i--;
		times++;
	} while (f && i > 1);
	printf("\nМодифицированный пузырёк:\nКоличество сравнений:%d\nКоличество перестановок:%d\n ", times, steps);
	// Шейкер сортировка
	times = 0;
	steps = 0;
	copy(sorted, matrix);
	k = n - 1;
	int left = 1;
	int right = n - 1;
	do
	{
		for (j = right; j >= left; j--) {
			times++;
			if (sorted[j - 1] > sorted[j])
			{
				steps += 3;
				buf = sorted[j - 1];
				sorted[j - 1] = sorted[j];
				sorted[j] = buf;
				k = j;
			}
		}
		left = k + 1;
		for (j = left; j <= right; j++) {
			times++;
			if (sorted[j - 1] > sorted[j])
			{
				steps += 3;
				buf = sorted[j - 1];
				sorted[j - 1] = sorted[j];
				sorted[j] = buf;
				k = j;
			}
		}
		right = k - 1;
		times++;
	} while (left <= right);
	printf("\nШейкер сортировка:\nКоличество сравнений:%d\nКоличество перестановок:%d\n ", times, steps);
	// Cортировка вставками
	times = 0;
	steps = 0;
	copy(sorted, matrix);
	int r;
	for (i = 1; i < n; i++)
	{
		r = sorted[i];
		j = i - 1;
		times++;
		while (j >= 0 && sorted[j] > r) {
			steps++;
			times++;
			sorted[j + 1] = sorted[j];
			j--;
		}
		steps++;
		sorted[j + 1] = r;
	}
	printf("\nCортировка вставками:\nКоличество сравнений:%d\nКоличество перестановок:%d\n ", times, steps);
	// Cортировка бинарными вставками
	times = 0;
	steps = 0;
	copy(sorted, matrix);
	int x, sred;
	for (i = 1; i < n; i++)
	{
		times++;
		if (sorted[i - 1] > sorted[i])
		{
			steps++;
			x = sorted[i];
			int left = 0;
			int right = i - 1;
			do {
				sred = (left + right) / 2;
				times++;
				if (sorted[sred] < x) {
					left = sred + 1;
					steps++;
				}
				else
					right = sred - 1;
				times++;
			} while (left <= right);
			for (j = i - 1; j >= left; j--) {
				sorted[j + 1] = sorted[j];
				steps++;
			}
			sorted[left] = x;
			steps++;
		}
	}
	printf("\nCортировка бинарными вставками:\nКоличество сравнений:%d\nКоличество перестановок:%d\n ", times, steps);
	// Cортировка методом простого выбора
	times = 0;
	steps = 0;
	copy(sorted, matrix);
	int m;
	for (i = n - 1; i > 0; i--)
	{
		int k = i;
		steps++;
		m = sorted[i];
		for (j = 0; j < i; j++) {
			times++;
			if (sorted[j] > m) {
				k = j;
				steps++;
				m = sorted[k];
			}
		}
		times++;
		if (k != i) {
			steps += 2;
			sorted[k] = sorted[i];
			sorted[i] = m;
		}
	}
	printf("\nCортировка методом простого выбора:\nКоличество сравнений:%d\nКоличество перестановок:%d\n ", times, steps);
	// Cортировка Шелла
	times = 0;
	steps = 0;
	copy(sorted, matrix);
	int c, step = n / 2;
	do {
		step = step / 3 + 1;
		int k = 0;
		times++;
		while (k < step) {
			for (i = k + step; i < n; i = i + step)
			{
				steps++;
				c = sorted[i];
				j = i - step;
				while (j >= 0 && sorted[j] > c) {
					steps++;
					sorted[j + step] = sorted[j];
					j = j - step;
					times++;
				}
				steps++;
				sorted[j + step] = c;
			}
			k++;
			times++;
		}
		times++;
	} while (step != 1);
	printf("\nCортировка Шелла:\nКоличество сравнений:%d\nКоличество перестановок:%d\n ", times, steps);
	// Пузырьковая сортировка 
	times = 0;
	steps = 0;
	copy(sorted, matrix);
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++) {
			times++;
			if (sorted[j] > sorted[j + 1])
			{
				steps += 3;
				buf = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = buf;
			}
		}
	printf("\nПузырьковая сортировка:\nКоличество сравнений:%d\nКоличество перестановок:%d\n ", times, steps);
	// Пузырьковая сортировка 
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++) {
			if (matrix[j] > matrix[j + 1])
			{
				buf = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = buf;
			}
		}
}

void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
void copy(int*to, int*from) {
	int n = _msize(to) / sizeof(int);
	while (n > 0) {
		n--;
		to[n] = from[n];
	}
}