#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>
#include "queue.h"
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 16
учебной группы 61391
Волкова А.А.
Дата выполнения: 07.12.2018
Тема работы: «Разработка, отладка и испытание программ обработки бинарных деревьев»
Задание: Написать рекурсивную процедуру, которая печатает элементы из
всех листьев дерева.
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
// Функция сортировки элементов очереди
int height(Element*);
// Функция вывода элементов очереди в консоль
void printTree(Element*);
// Функция вывода элементов очереди в консоль
void printLeaves(Element*);
// Устанавливает положение курсора в консоли 
void setCursorPosition(int, int);

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
	printTree(tree);
	// Вывод всех листьев
	printf("\nЛистья дерева:\n");
	printLeaves(tree);
	getch();
}
// Функция создания дерева
Element * createElement(int value, int pos, int lvl) {
	Element * i = malloc(sizeof(Element));
	i->data = value;
	i->position = pos;
	i->left = NULL;
	i->right = NULL;
	i->level = lvl;
	return i;
}
// Функция добавления элемента в дерево
void push(Element* tree, int value, int pos, int lvl) {
	lvl++; 	// Переход на следующий уровень
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
void printTree(Element* tree) {
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
		int y = 3 * 1 + value->level * 2;
		setCursorPosition(x, y);
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
// Функция вычесления размера дерева
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
// Функция вывода листьев дерева в консоль
void printLeaves(Element* tree) {
	if (tree->left == NULL && tree->right == NULL) {
		printf("\nузел со значением %d расположен на уровне %d", tree->data, tree->level);
	}
	else {
		if (tree->left != NULL) {
			printLeaves(tree->left);
		}
		if (tree->right != NULL) {
			printLeaves(tree->right);
		}
	}
}
// Устанавливает положение курсора в консоли 
void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
