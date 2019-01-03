#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "list.h"
// Функция создания элемента
Item * createItem(int id,Item* prev){
	Item* item = malloc(sizeof(Item));
	item->id = id;
	item->next = NULL;
	item->prev = prev;
	return item;
}
// Функция добавления элемента
void addItem(Item**list, int id){
	Item* prev = *list;
	for (; (*list) != NULL; prev = *list, list = &(*list)->next);
	*list = createItem(id, prev);
}
// Функция вывода списка элементов в консоль
void printList(Item * list){
	printf("\nЭлементы списка:\n\n");
	for (int i = 1; list != NULL; list = list->next, i++) {
		printf("элемент [%d]: %d\n", i, list->id);
	}
}
// Функция замены крайних элементов
void replaceItems(Item ** list){
	int first = (*list)->id;
	Item * begin = *list;
	for (; (*list)->next != NULL; list = &(*list)->next);
	begin->id = (*list)->id;
	(*list)->id = first;
}
