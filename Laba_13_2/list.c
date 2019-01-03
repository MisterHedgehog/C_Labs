#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "list.h"
// ������� �������� ��������
Item * createItem(int id,Item* prev){
	Item* item = malloc(sizeof(Item));
	item->id = id;
	item->next = NULL;
	item->prev = prev;
	return item;
}
// ������� ���������� ��������
void addItem(Item**list, int id){
	Item* prev = *list;
	for (; (*list) != NULL; prev = *list, list = &(*list)->next);
	*list = createItem(id, prev);
}
// ������� ������ ������ ��������� � �������
void printList(Item * list){
	printf("\n�������� ������:\n\n");
	for (int i = 1; list != NULL; list = list->next, i++) {
		printf("������� [%d]: %d\n", i, list->id);
	}
}
// ������� ������ ������� ���������
void replaceItems(Item ** list){
	int first = (*list)->id;
	Item * begin = *list;
	for (; (*list)->next != NULL; list = &(*list)->next);
	begin->id = (*list)->id;
	(*list)->id = first;
}
