#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

void main(int argc, char* argv[]) {
	int arr[30][3];
	while (true) {
		// Добавляем кириллицу в консоль
		setlocale(0, "Russian");
		srand(time(NULL));
		// Заполнение массива
		for (int i = 0; i < 30; i++) {
			printf(" Оценки учащегося под %d номером в журнале: \t", i + 1);
			for (int j = 0; j < 3; j++) {
				if (i == 0 || i == 6 || i == 5) {
					arr[i][j] = 9;
				}
				else
					arr[i][j] = random(4, 9);
				printf(" %d", arr[i][j]);
			}
			printf("\tСредняя оценка : %.0lf\n", round((arr[i][0] + arr[i][1] + arr[i][2]) / 3));
		}
		printf("\nА зарплата преподавателю : %d\n", random(260, 1000));
		printf("\nПродолжить...\n");
		getch();
	}
}
int random(int min, int max) {
	return min + rand() % (max - min + 1);
}
