#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include "queue.h"
// Функция создания очереди
Queue * createQueue() {
	Queue * q = malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	return q;
}
Item * createItem(Element* value) {
	Item *i = malloc(sizeof(Item));
	i->data = value;
	i->next = NULL;
	return i;
}
// Функция добавления элемента в стек
void pushElement(Queue* queue, Element* value) {
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
// Функция изъятия элемента из стек
Element * popElement(Queue* queue) {
	if (queue->head != NULL) {
		Element * value = queue->head->data;
		if (queue->head->next == NULL) {
			queue->head = NULL;
			queue->tail = NULL;
		}
		else {
			queue->head = queue->head->next;
		}
		return value;
	}
	printf("нет\n");
	Element * null = malloc(sizeof(Element));
	return null;
}