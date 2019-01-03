#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 14
учебной группы 61391
Волкова А.А.
Дата выполнения: 28.11.2018
Тема работы: «Разработка, отладка и испытание программ обработки стеков и очередей»
Задание: Дана очередь вещественных чисел, упорядоченных по убыванию.
Добавить в очередь среднее арифметическое элементов, не нарушая упорядоченности. 
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
// Функция создания очереди
Queue * createQueue();
// Функция создания элемента
Item * createItem(float);
// Функция заполнения очереди
void fillQueue(Queue* queue, int size);
// Функция добавления элемента в очередь
void push(Queue*, float);
// Функция изъятия элемента из очередь
float pop(Queue*);
// Функция вывода элементов очереди в консоль
void printQueue(Queue*);
// Функция сортировки элементов очереди
void sortQueue(Queue*);
// Функция внедрения среднего арифметического значения элементов
void insertAverage(Queue*);

void main(int argc, char* argv[]) {
	// Добавление кириллицы в консоль
	setlocale(0, "Russian");
	// Создания очереди
	Queue* queue = createQueue();
	int n;
	do { // Считывание размера очереди
		printf("Введите размер очереди(меньше 100)\n");
		scanf("%d", &n);
	} while (n > 100 || n < 0);
	// Заполнение и сортировка очереди
	fillQueue(queue, n);
	sortQueue(queue);
	// Вывод исходной очереди
	printQueue(queue);
	// Вставка среднего арифметического значения
	insertAverage(queue);
	// Вывод конечной очереди
	printQueue(queue);
	getch();
}
// Функция создания очереди
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
// Функция добавления элемента в очередь
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
// Функция изъятия элемента из очереди
float pop(Queue* queue) {
	if (queue->head != NULL) {
		float value = queue->head->data;
		queue->head = queue->head->next;
		return value;
	}
	return 0;
}
// Функция заполнения очереди
void fillQueue(Queue* queue, int size) {
	for (int i = 0; i < size; i++) {
		float value = (float)(-5000 + rand() % 10001)/100;
		push(queue, value);
	}
}
// Функция вывода элементов очереди       в консоль
void printQueue(Queue* queue) {
	Queue* new = createQueue();
	printf("\nОчередь:\n\n");
	for (int i = 0;queue->head != NULL; i++) {
		float value = pop(queue);
		printf("элемент очереди[%d]:%.3f\n", i, value);
		push(new, value);
	}
	*queue = *new;
}
// Функция сортировки элементов очереди
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
// Функция внедрения среднего арифметического значения элементов
void insertAverage(Queue* queue) {
	Queue* new = createQueue();
	float average = 0;
	int size;
	// Вычисление среднего значения
	for (size = 0; queue->head != NULL; size++) {
		float value = pop(queue);
		push(new, value);
		average += value;
	}
	average /= size;
	printf("\nСреднее арифметическое элементов: %.3f\n\n", average);
	*queue = *new;
	// Вставка среднего значения в очередь
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