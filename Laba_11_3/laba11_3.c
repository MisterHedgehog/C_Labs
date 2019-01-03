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
	printf("�������� �������:");
	matrix = malloc(n * n * sizeof(int));
		// ���������� �������
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3 , 2 + y);
			matrix[y * n + x] = rand() % 100;
			printf("%d", matrix[y * n + x]);

		}
	}
	// ����� ��������������� �������
	sortMatrix(matrix);
	// ����� ���������� �� �����
	printf("\n��������� ����������:");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			setCursorPosition(1 + x * 3, n + 32 + y);
			printf("%d", matrix[y * n + x]);
		}
	}
	getch();
	// ������������ ������
	free(matrix);
}

void sortMatrix(int*matrix) {
	// n - ���������� ��������� �������
	int i, j, times, steps, buf, n = _msize(matrix) / sizeof(int);
	times = 0;
	steps = 0;
	// ������ ����� �������
	int*sorted = malloc(_msize(matrix));
	// ���������������� ������
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
	printf("\n���������������� ������:\n���������� ���������:%d\n���������� ������������:%d\n ", times, steps);
	// ������ ����������
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
	printf("\n������ ����������:\n���������� ���������:%d\n���������� ������������:%d\n ", times, steps);
	// C��������� ���������
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
	printf("\nC��������� ���������:\n���������� ���������:%d\n���������� ������������:%d\n ", times, steps);
	// C��������� ��������� ���������
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
	printf("\nC��������� ��������� ���������:\n���������� ���������:%d\n���������� ������������:%d\n ", times, steps);
	// C��������� ������� �������� ������
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
	printf("\nC��������� ������� �������� ������:\n���������� ���������:%d\n���������� ������������:%d\n ", times, steps);
	// C��������� �����
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
	printf("\nC��������� �����:\n���������� ���������:%d\n���������� ������������:%d\n ", times, steps);
	// ����������� ���������� 
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
	printf("\n����������� ����������:\n���������� ���������:%d\n���������� ������������:%d\n ", times, steps);
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