#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <math.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 11
������� ������ 61391
������� �.�.
���� ����������: 28.10.2018
���� ������:  �����������, ������� � ��������� ���������� � �������� � �������������� ���������� ������� ����������
�������: ������������� �������� ���������� ������������ ������� ����������� n, �������� ����������� ����������.
*/
//---------------------------------------------------------------------------//

// ������ ������� ��������� �������� ���������� ������������ �������
void sortMatrix(int*);
void copy(int*, int*);
void showResult(char*, int*, int*);
// ������������� ��������� ������� � ������� 
void setCursorPosition(int, int);

void main(int argc, char* argv[]) {
	int *matrix, n, result;
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	// ���� ������
	do {
		printf("������� ����������� ������: ");
		scanf("%d", &n);
	} while (n < 1);
	// ��������� ������ ��� ������
	printf("�������� ������:");
	matrix =malloc(n * n * 5 * sizeof(int));
	for (int i = 0; i < 5; i++) {
		// ���������� �������
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				setCursorPosition(1 + x*3 + i*n*5, 2 + y);
				matrix[n * i + y * n + x] = rand() % 100;
				printf("%d", matrix[n * i + y * n + x]);

			}
		}
	}
	// ����� ��������������� �������
	sortMatrix(matrix);
	// ����� ���������� �� �����
	printf("\n��������� ����������:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, n + 60 + y);
			printf("%d", matrix[y * n + x]);
		}
	}
	getch();
	// ������������ ������
	free(matrix);
}

void sortMatrix(int*matrix) {
	// n - ���������� ��������� �������
	int i, j, *times, *steps, buf, n = (_msize(matrix) / 5) / sizeof(int);
	times = malloc(20);
	steps = malloc(20);
	for (int i = 0; i < 5; i++) {
		times[i] = 0;
		steps[i] = 0;
	}
	// ������ ����� �������
	int*sorted = malloc((_msize(matrix) / 5));
	// ���������������� ������
	for (int w = 0; w < 5; w++) {
		copy(sorted, matrix + w * n);
		i = n;
		int f, k;
		do {
			f = 0;
			for (k = 0; k < i - 1; k++) {
				times[w]++;
				if (sorted[k] > sorted[k + 1])
				{
					steps[w] += 3;
					buf = sorted[k];
					sorted[k] = sorted[k + 1];
					sorted[k + 1] = buf;
					f = 1;
				}
			}
			i--;
			times[w]++;
		} while (f && i > 1);
	}
	showResult("���������������� ������", times, steps);
	// ������ ����������
	for (int w = 0; w < 5; w++) {
		copy(sorted, matrix + w * n);
		int k = n - 1;
		int left = 1;
		int right = n - 1;
		do
		{
			for (j = right; j >= left; j--) {
				times[w]++;
				if (sorted[j - 1] > sorted[j])
				{
					steps[w] += 3;
					buf = sorted[j - 1];
					sorted[j - 1] = sorted[j];
					sorted[j] = buf;
					k = j;
				}
			}
			left = k + 1;
			for (j = left; j <= right; j++) {
				times[w]++;
				if (sorted[j - 1] > sorted[j])
				{
					steps[w] += 3;
					buf = sorted[j - 1];
					sorted[j - 1] = sorted[j];
					sorted[j] = buf;
					k = j;
				}
			}
			right = k - 1;
			times[w]++;
		} while (left <= right);
	}
	showResult("������ ����������", times, steps);
	// C��������� ���������
	for (int w = 0; w < 5; w++) {
		copy(sorted, matrix + w * n);
		int r;
		for (i = 1; i < n; i++)
		{
			r = sorted[i];
			j = i - 1;
			times[w]++;
			while (j >= 0 && sorted[j] > r) {
				steps[w]++;
				times[w]++;
				sorted[j + 1] = sorted[j];
				j--;
			}
			steps[w]++;
			sorted[j + 1] = r;
		}	}
	showResult("C��������� ���������", times, steps);
	// C��������� ��������� ���������
	for (int w = 0; w < 5; w++) {
		copy(sorted, matrix + w * n);
		int x, sred;
		for (i = 1; i < n; i++)
		{
			times[w]++;
			if (sorted[i - 1] > sorted[i])
			{
				steps[w]++;
				x = sorted[i];
				int left = 0;
				int right = i - 1;
				do {
					sred = (left + right) / 2;
					times[w]++;
					if (sorted[sred] < x) {
						left = sred + 1;
						steps[w]++;
					}
					else
						right = sred - 1;
					times[w]++;
				} while (left <= right);
				for (j = i - 1; j >= left; j--) {
					sorted[j + 1] = sorted[j];
					steps[w]++;
				}
				sorted[left] = x;
				steps[w]++;
			}
		}
	}
	showResult("C��������� ��������� ���������", times, steps);
	// C��������� ������� �������� ������
	for (int w = 0; w < 5; w++) {
		copy(sorted, matrix + w * n);
		int m;
		for (i = n - 1; i > 0; i--)
		{
			int k = i;
			steps[w]++;
			m = sorted[i];
			for (j = 0; j < i; j++) {
				times[w]++;
				if (sorted[j] > m) {
					k = j;
					steps[w]++;
					m = sorted[k];
				}
			}
			times[w]++;
			if (k != i) {
				steps[w] += 2;
				sorted[k] = sorted[i];
				sorted[i] = m;
			}
		}
		showResult("C��������� ������� �������� ������", times, steps);
	}
	// C��������� �����
	for (int w = 0; w < 5; w++) {
		copy(sorted, matrix + w * n);
		int c, step = n / 2;
		do {
			step = step / 3 + 1;
			int k = 0;
			times[w]++;
			while (k < step) {
				for (i = k + step; i < n; i = i + step)
				{
					steps[w]++;
					c = matrix[i];
					j = i - step;
					while (j >= 0 && matrix[j] > c) {
						steps[w]++;
						matrix[j + step] = matrix[j];
						j = j - step;
						times[w]++;
					}
					steps[w]++;
					matrix[j + step] = c;
				}
				k++;
				times[w]++;
			}
			times[w]++;
		} while (step != 1);
	}
	showResult("C��������� �����", times, steps);
	// ����������� ���������� 
	for (int w = 0; w < 5; w++) {
		copy(sorted, matrix + w * n);
		for (i = 0; i < n - 1; i++)
			for (j = 0; j < n - i - 1; j++) {
				times[w]++;
				if (sorted[j] > sorted[j + 1])
				{
					steps[w] += 3;
					buf = sorted[j];
					sorted[j] = sorted[j + 1];
					sorted[j + 1] = buf;
				}
			}
	}
	showResult("����������� ����������", times, steps);
	// ����������� ���������� 
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
void showResult(char* title, int*times, int*steps) {
	int mid = 0;
	printf("\n\n\n%s:\n���������� ��������� ", title);
	for (int i = 0; i < 5; i++) {
		printf("  %d", times[i]);
		mid += times[i];
		times[i] = 0;
	}
	printf("   ������� ���������� ���������:%5.d ", (int) mid/5);
	printf("\n���������� ����� ");
	mid = 0;
	for (int i = 0; i < 5; i++) {
		printf("  %d", steps[i]);
		mid += steps[i];
		steps[i] = 0;
	}
	printf("   ������� ���������� �����:%5.d ", (int)mid / 5);
}