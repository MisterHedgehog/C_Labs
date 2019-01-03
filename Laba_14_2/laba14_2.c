#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 14
������� ������ 61391
������� �.�.
���� ����������: 28.11.2018
���� ������: �����������, ������� � ��������� �������� ��������� ������ � ��������
�������: ���� ������� ������������ �����, ������������� �� ��������.
�������� � ������� ������� �������������� ���������, �� ������� ���������������. 
*/
//---------------------------------------------------------------------------//
typedef struct Item {
	float data;
	struct Item* next;
} Item;
typedef struct Queue {
	Item* head;
	Item* tail;
} Queue;
// ������� �������� �������
Queue * createQueue();
// ������� �������� ��������
Item * createItem(float);
// ������� ���������� �������
void fillQueue(Queue* queue, int size);
// ������� ���������� �������� � �������
void push(Queue*, float);
// ������� ������� �������� �� �������
float pop(Queue*);
// ������� ������ ��������� ������� � �������
void printQueue(Queue*);
// ������� ���������� ��������� �������
void sortQueue(Queue*);
// ������� ��������� �������� ��������������� �������� ���������
void insertAverage(Queue*);

void main(int argc, char* argv[]) {
	// ���������� ��������� � �������
	setlocale(0, "Russian");
	// �������� �������
	Queue* queue = createQueue();
	int n;
	do { // ���������� ������� �������
		printf("������� ������ �������(������ 100)\n");
		scanf("%d", &n);
	} while (n > 100 || n < 0);
	// ���������� � ���������� �������
	fillQueue(queue, n);
	sortQueue(queue);
	// ����� �������� �������
	printQueue(queue);
	// ������� �������� ��������������� ��������
	insertAverage(queue);
	// ����� �������� �������
	printQueue(queue);
	getch();
}
// ������� �������� �������
Queue * createQueue() {
	Queue * q = malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	return q;
}
Item * createItem(float value) {
	Item *i = malloc(sizeof(Item));
	i->data = value;
	i->next = NULL;
	return i;
}
// ������� ���������� �������� � �������
void push(Queue* queue, float value) {
	Item * item = createItem(value);
	if (queue->tail == NULL) {
		queue->tail = item;
		queue->head = item;
	}
	else {
		queue->tail->next = item;
		queue->tail = item;
	}
}
// ������� ������� �������� �� �������
float pop(Queue* queue) {
	if (queue->head != NULL) {
		float value = queue->head->data;
		queue->head = queue->head->next;
		return value;
	}
	return 0;
}
// ������� ���������� �������
void fillQueue(Queue* queue, int size) {
	for (int i = 0; i < size; i++) {
		float value = (float)(-5000 + rand() % 10001)/100;
		push(queue, value);
	}
}
// ������� ������ ��������� �������       � �������
void printQueue(Queue* queue) {
	Queue* new = createQueue();
	printf("\n�������:\n\n");
	for (int i = 0;queue->head != NULL; i++) {
		float value = pop(queue);
		printf("������� �������[%d]:%.3f\n", i, value);
		push(new, value);
	}
	*queue = *new;
}
// ������� ���������� ��������� �������
void sortQueue(Queue* queue) {
	Queue* new = createQueue();
	float minValue = -100, buffer = 100;
	int size, i;
	for (i = 0; queue->head != NULL; i++) {
		float value = pop(queue);
		push(new, value);
	}
	*queue = *new;
	size = i;
	Queue* resualt = createQueue();
	for (; size > 0; size--) {
		new = createQueue();
		for (int i = 0; queue->head != NULL; i++) {
			float value = pop(queue);
			if (value > minValue && buffer > value) {
				minValue = value;
			}
			push(new, value);
		}
		*queue = *new;
		buffer = minValue;
		minValue = -100;
		push(resualt, buffer);
	}
	*queue = *resualt;
}
// ������� ��������� �������� ��������������� �������� ���������
void insertAverage(Queue* queue) {
	Queue* new = createQueue();
	float average = 0;
	int size;
	// ���������� �������� ��������
	for (size = 0; queue->head != NULL; size++) {
		float value = pop(queue);
		push(new, value);
		average += value;
	}
	average /= size;
	printf("\n������� �������������� ���������: %.3f\n\n", average);
	*queue = *new;
	// ������� �������� �������� � �������
	new = createQueue();
	while (queue->head != NULL) {
		float value = pop(queue);
		if (average && average > value) {
			push(new, average);
			average = 0;
		}
		push(new, value);
	}
	*queue = *new;
}