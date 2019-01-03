#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>
#include "queue.h"
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 15
учебной группы 61391
Волкова А.А.
Дата выполнения: 05.12.2018
Тема работы: «Разработка, отладка и испытание программ обработки бинарных деревьев»
Задание: Найдите высоту дерева H и удалите из него (с перестройкой) все
вершины на уровне H/2. 
*/
//---------------------------------------------------------------------------//
// Функция создания элемента
Element * createElement(int, int, int);
// Функция заполнения дерева
void fillTree(Element* tree, int size);
// Функция добавления элемента в дерево
void push(Element*, int, int, int);
// Функция изъятия элемента из дерева
float pop(Element*);
// Функция вывода элементов дерева в консоль
void printTree(Element*, int);
// Функция нахождения высоты дерева
int height(Element*);
// Функция удаления дочерних элементов узла
void removeChildren(Element*);
// Удаление узла
void removeElement(Element*);
// Устанавливает положение курсора в консоли 
void setCursorPosition(int, int);
// Нахождение значения наибольшего узла
int findBigest(Element*element);
// Удаление сренего уровня дерева
void removeMiddle(Element*);
// Поднятие узла на уровень вверх
void moveUp(Element*,int);

void main(int argc, char* argv[]) {
	// Добавление кириллицы в консоль
	setlocale(0, "Russian");
	// Создания дерева
	Element* tree = createElement(50, 1, 1);
	int n;
	// Ожидание количество узлов дерева
	printf("Введите количество узлов дерева:\n");
	scanf("%d", &n);
	// Заполнение дерева
	fillTree(tree, n);
	// Вывод исходного дерева
	printf("Исходное дерево:\n");
	printTree(tree, 0);
	// Удаление среднего уровня
	removeMiddle(tree);
	// Вывод окончательного дерева
	printTree(tree, 1);
	getch();
}
// Функция создания узла
Element * createElement(int value, int pos, int lvl) {
	Element * i = malloc(sizeof(Element));
	i->data = value;
	i->position = pos;
	i->left = NULL;
	i->right = NULL;
	i->level = lvl;
	return i;
}
// Функция добавления узла в дерево
void push(Element* tree, int value, int pos, int lvl) {
	lvl++; // Переход на следующий уровень
	if (tree->data > value) {
		// Вычисление позиции
		pos *= 2;
		pos--;
		if (tree->left == NULL) {
			// Если левое поддерево свободно, то вставляем значение
			tree->left = createElement(value, pos, lvl);
		}
		else {
			// Если левое поддерево занято, то продолжаем поиски
			push(tree->left, value, pos, lvl);
		}
	}
	else {
		// Вычисление позиции
		pos *= 2;
		if (tree->right == NULL) {
			// Если правое поддерево свободно, то вставляем значение
			tree->right = createElement(value, pos, lvl);
		}
		else {
			// Если правое поддерево занято, то продолжаем поиски
			push(tree->right, value, pos, lvl);
		}
	}
}
// Функция заполнения дерева
void fillTree(Element* tree, int size) {
	for (int i = 0; i < size; i++) {
		int value = 1 + rand() % 99;
		push(tree, value, 1, 1);
	}
}
// Функция вывода узлов дерева в консоль
void printTree(Element* tree, int n) {
	int h = height(tree);
	Queue* q = createQueue();
	pushElement(q, tree);
	for (int i = 0; q->tail != NULL; i++) {
		Element * value = popElement(q);
		int hght = h - value->level;
		int margin = 0;
		for (int i = hght; i > 0; i--) {
			margin *= 2;
			margin += 2;
		}
		int x = margin + ((margin * 2) + 4)*(value->position - 1);
		int y =   n * h * 2 + 3 * (n * 7 + 1) + value->level * 2;
		setCursorPosition(x,y);
		printf("|%2.d|", value->data);
		if (value->left != NULL || value->right != NULL) {
			setCursorPosition(x, y + 1);
			printf(" ||");
			setCursorPosition(x - margin / 2 + 3, y + 2);
			for (int i = 0; i < margin - 2; i++) {
				printf("-");
			}
		}
		if (value->left != NULL) {
			pushElement(q, value->left);
		}
		if (value->right != NULL) {
			pushElement(q, value->right);
		}
	}
}
// Функция нахождения высоты дерева
int height(Element*tree) {
	Queue* q = createQueue();
	pushElement(q, tree);
	int level = 0;
	for (int i = 0; q->tail != NULL; i++) {
		Element * value = popElement(q);
		if (value->level > level) {
			level = value->level;
		}
		if (value->left != NULL) {
			pushElement(q, value->left);
		}
		if (value->right != NULL) {
			pushElement(q, value->right);
		}
	}
	return level;
}
// Устанавливает положение курсора в консоли 
void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
// Функция удаления дочерних элементов узла
void removeChildren(Element* element) {
	// Удаления левого узла
	if (element->left != NULL) {
		// (1) Первый случай - левый узел является листом
		if (element->left->right == NULL && element->left->left == NULL) {
			element->left = NULL;
		}
		else removeElement(element->left);
	}
	// Удаления правого узла
	if (element->right != NULL) {
		// (1) Первый случай - правый узел является листом
		if (element->right->right == NULL && element->right->left == NULL) {
			element->right = NULL;
		}
		else removeElement(element->right);

	}
}
// Удаление узла
void removeElement(Element* element) {
	// (2) Второй случай - существует и левый и правый узел
	if (element->right != NULL && element->left != NULL) {
		int i = findBigest(element);
		element->data = i;
	}
	else
		// (3) Третий случай - существует только правый или только левый узел
		if (element->right != NULL) {
			moveUp(element->right, element->position);
			Element* right = element->right->right;
			element->data = element->right->data;
			element->left = element->right->left;
			element->right = right;
		}
		else {
			Element* right = element->left->right;
			moveUp(element->left, element->position);
			element->data = element->left->data;
			element->left = element->left->left;
			element->right = right;
		}
}
// Нахождение значения наибольшего узла
int findBigest(Element*tree) {
	if (tree->right->right == NULL) {
		int result = tree->right->data;
		tree->right = NULL;
		return result;
	}
	return findBigest(tree->right);
}
// Удаление сренего уровня дерева
void removeMiddle(Element* tree){
	Queue* q = createQueue();
	pushElement(q, tree);
	int h = height(tree)/2;
	printf("\nудаление уровня %d\n", h);
	printf("Результат:");
	for (int i = 0; q->tail != NULL; i++) {
		Element * value = popElement(q);
		if (value->level == h - 1) {
			removeChildren(value);
		}
		if (value->left != NULL) {
			pushElement(q, value->left);
		}
		if (value->right != NULL) {
			pushElement(q, value->right);
		}
	}
}
// Поднятие узла на уровень вверх
void moveUp(Element* tree, int n) {
	tree->position = n;
	tree->level--;
	if (tree->left != NULL) {
		moveUp(tree->left, tree->position * 2 - 1);
	}
	if (tree->right != NULL) {
		moveUp(tree->right, tree->position * 2);
	}
}
