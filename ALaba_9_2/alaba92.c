#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 9.2
учебной группы 61391
Аббасова Р.М.
21.09.2018
Тема работы: Дан массив А, состоящий из n натуральных чисел. 
Найдите элемент массива, сумма цифр которого наибольшая.
*/
//---------------------------------------------------------------------------//
// Тело функции
void Zadanie(int n, bool*c);
void main(int argc, char* argv[]) {
	// Обьявление переменных
	int mass[100], n, sum = 0, buffer = 0, index;
	setlocale(0, "Russian");
	do {
		printf("Введите размерность матриц: ");
		scanf("%d", &n);
	} while (n < 1 || n > 100);
	// Заполнение массива
	for (int i = 0; i < n; i++) {
		printf("A[%d]",i);
		scanf("%d", &mass[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
	}
	for (int i = 0; i < n; i++) {
		do {
			sum += mass[i] % 10;
			mass[i] /= 10;
			
		} while (mass[i]);

		if (sum > buffer) {
			buffer = sum;
			index = i;
		}
		sum = 0;
	}
	printf("\n");
	printf("Элемент массива, сумма цифр которого наибольшаяА[%d] = %d",index, buffer);
	getch();
	
}