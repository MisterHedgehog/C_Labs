#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

void main(int argc, char* argv[]) {
	int arr[30][3];
	while (true) {
		// ��������� ��������� � �������
		setlocale(0, "Russian");
		srand(time(NULL));
		// ���������� �������
		for (int i = 0; i < 30; i++) {
			printf(" ������ ��������� ��� %d ������� � �������: \t", i + 1);
			for (int j = 0; j < 3; j++) {
				if (i == 0 || i == 6 || i == 5) {
					arr[i][j] = 9;
				}
				else
					arr[i][j] = random(4, 9);
				printf(" %d", arr[i][j]);
			}
			printf("\t������� ������ : %.0lf\n", round((arr[i][0] + arr[i][1] + arr[i][2]) / 3));
		}
		printf("\n� �������� ������������� : %d\n", random(260, 1000));
		printf("\n����������...\n");
		getch();
	}
}
int random(int min, int max) {
	return min + rand() % (max - min + 1);
}
