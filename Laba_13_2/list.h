#pragma once
#ifndef LIST_H
#define LIST_H
#include "time.h"
// Структура, описывающая элемент
typedef struct Item {
	int id;
	struct Item* prev;
	struct Item* next;
} Item;
// Функция создания элемента
Item* createItem(int id, Item* prev);
// Функция добавления элемента
void addItem(Item**list, int id);
// Функция вывода списка элементов в консоль
void printList(Item* Список);
// Функция замены крайних элементов
void replaceItems(Item**Список);
#endif