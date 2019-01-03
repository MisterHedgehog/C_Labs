#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>
#include "queue.h"
//---------------------------------------------------------------------------//
/*
				������������ ������ � 16
������� ������ 61391
������� �.�.
���� ����������: 07.12.2018
���� ������: �����������, ������� � ��������� �������� ��������� �������� ��������
�������: �������� ����������� ���������, ������� �������� �������� ��
���� ������� ������.
*/
//---------------------------------------------------------------------------//
// ������� �������� ��������
Element * createElement(int, int, int);
// ������� ���������� ������
void fillTree(Element* tree, int size);
// ������� ���������� �������� � ������
void push(Element*, int, int, int);
// ������� ������� �������� �� ������
float pop(Element*);
// ������� ���������� ��������� �������
int height(Element*);
// ������� ������ ��������� ������� � �������
void printTree(Element*);
// ������� ������ ��������� ������� � �������
void printLeaves(Element*);
// ������������� ��������� ������� � ������� 
void setCursorPosition(int, int);

void main(int argc, char* argv[]) {
	// ���������� ��������� � �������
	setlocale(0, "Russian");
	// �������� ������
	Element* tree = createElement(50, 1, 1);
	int n;
	// �������� ���������� ����� ������
	printf("������� ���������� ����� ������:\n");
	scanf("%d", &n);
	// ���������� ������
	fillTree(tree, n);
	// ����� ��������� ������
	printf("�������� ������:\n");
	printTree(tree);
	// ����� ���� �������
	printf("\n������ ������:\n");
	printLeaves(tree);
	getch();
}
// ������� �������� ������
Element * createElement(int value, int pos, int lvl) {
	Element * i = malloc(sizeof(Element));
	i->data = value;
	i->position = pos;
	i->left = NULL;
	i->right = NULL;
	i->level = lvl;
	return i;
}
// ������� ���������� �������� � ������
void push(Element* tree, int value, int pos, int lvl) {
	lvl++; 	// ������� �� ��������� �������
	if (tree->data > value) {
		// ���������� �������
		pos *= 2;
		pos--;
		if (tree->left == NULL) {
			// ���� ����� ��������� ��������, �� ��������� ��������
			tree->left = createElement(value, pos, lvl);
		}
		else {
			// ���� ����� ��������� ������, �� ���������� ������
			push(tree->left, value, pos, lvl);
		}
	}
	else {
		// ���������� �������
		pos *= 2;
		if (tree->right == NULL) {
			// ���� ������ ��������� ��������, �� ��������� ��������
			tree->right = createElement(value, pos, lvl);
		}
		else {
			// ���� ������ ��������� ������, �� ���������� ������
			push(tree->right, value, pos, lvl);
		}
	}
}
// ������� ���������� ������
void fillTree(Element* tree, int size) {
	for (int i = 0; i < size; i++) {
		int value = 1 + rand() % 99;
		push(tree, value, 1, 1);
	}
}
// ������� ������ ����� ������ � �������
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
// ������� ���������� ������� ������
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
// ������� ������ ������� ������ � �������
void printLeaves(Element* tree) {
	if (tree->left == NULL && tree->right == NULL) {
		printf("\n���� �� ��������� %d ���������� �� ������ %d", tree->data, tree->level);
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
// ������������� ��������� ������� � ������� 
void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
