#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int array[100], n, a;
	// Добавляем кириллицу в консоль
	setlocale(0, "Russian");
	// Вводим размерность массива с клавиатуры
	do {
		printf("Введите размерность (меньше 100) ");
		scanf("%d", &n);
	} while (n> 100 || n<0);
	printf("\n");
	// Вводим элементы массива с клавиатуры
	for (int i = 0; i < n; i++) { 
			printf("Введите элемент массива[%d]:", i);
			scanf("%d", &array[i]);
		}
	// Выводим элементы исходного массива
	printf("\nИсходный массив:\n");
	for (int i = 0; i < n; i++) {
			printf("%3.d", array[i]);
	}
	a = array[0];
	// Определяем и выводим ответ
	for (int i = 1; i < n; i++) {
		if (array[i-1] > array[i]) {
		}
	}
	getch();
}