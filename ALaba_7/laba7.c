#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
/* Лабораторная работа №7
   учащегося группы 61391
   Аббасова Рамазана
   Вариант 1
   задание: Найти площадь треугольника при заданных координатах вершин
*/

#include <stdio.h>
#include <math.h>
// Тело функции
float otvet(int x1,int x2,int x3,int y1,int y2,int y3);
void main(int argc, char* argv[]) {
	//Обьявление переменных
	int x1, x2, x3, y1, y2, y3;
	float s;
	//Ввод значений вершин
	printf("Vvedite x1, y1 \n");
	scanf("  %d", &x1);
	scanf("  %d", &y1);
	printf("Vvedite x2, y2 \n");
	scanf("  %d", &x2);
	scanf("  %d", &y2);
	printf("Vvedite x3, y3 \n");
	scanf("  %d", &x3);
	scanf("  %d", &y3);
	//Вывод значений на экран
	s = otvet(x1, x2, x3, y1, y2, y3);
	printf("   S = %.3f cm^2", s);
	getch();
}

float otvet(int x1, int x2, int x3, int y1, int y2, int y3) {
	//Расчёт сторон треугольника и вывод их значений на экран
	float a = sqrt((pow((y1 - y2), 2)) + (pow((x1 - x2), 2)));
	float b = sqrt((pow((y2 - y3), 2)) + (pow((x2 - x3), 2)));
	float c = sqrt((pow((y3 - y1), 2)) + (pow((x3 - x1), 2)));
	//Нахождение периметра и вывод его на экран
	float p = (a + b + c) / 2;
	//Нахождение площади треугольника и вывод его на экран
	return sqrt(p*(p - a)*(p - b)*(p - c));
}