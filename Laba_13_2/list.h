#pragma once
#ifndef LIST_H
#define LIST_H
#include "time.h"
// ���������, ����������� �������
typedef struct Item {
	int id;
	struct Item* prev;
	struct Item* next;
} Item;
// ������� �������� ��������
Item* createItem(int id, Item* prev);
// ������� ���������� ��������
void addItem(Item**list, int id);
// ������� ������ ������ ��������� � �������
void printList(Item* ������);
// ������� ������ ������� ���������
void replaceItems(Item**������);
#endif