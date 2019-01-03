#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>
#include "queue.h"
//---------------------------------------------------------------------------//
/*
				������������ ������ � 15
������� ������ 61391
������� �.�.
���� ����������: 05.12.2018
���� ������: �����������, ������� � ��������� �������� ��������� �������� ��������
�������: ������� ������ ������ H � ������� �� ���� (� ������������) ���
������� �� ������ H/2. 
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
// ������� ������ ��������� ������ � �������
void printTree(Element*, int);
// ������� ���������� ������ ������
int height(Element*);
// ������� �������� �������� ��������� ����
void removeChildren(Element*);
// �������� ����
void removeElement(Element*);
// ������������� ��������� ������� � ������� 
void setCursorPosition(int, int);
// ���������� �������� ����������� ����
int findBigest(Element*element);
// �������� ������� ������ ������
void removeMiddle(Element*);
// �������� ���� �� ������� �����
void moveUp(Element*,int);

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
	printTree(tree, 0);
	// �������� �������� ������
	removeMiddle(tree);
	// ����� �������������� ������
	printTree(tree, 1);
	getch();
}
// ������� �������� ����
Element * createElement(int value, int pos, int lvl) {
	Element * i = malloc(sizeof(Element));
	i->data = value;
	i->position = pos;
	i->left = NULL;
	i->right = NULL;
	i->level = lvl;
	return i;
}
// ������� ���������� ���� � ������
void push(Element* tree, int value, int pos, int lvl) {
	lvl++; // ������� �� ��������� �������
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
// ������� ���������� ������ ������
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
// ������������� ��������� ������� � ������� 
void setCursorPosition(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
// ������� �������� �������� ��������� ����
void removeChildren(Element* element) {
	// �������� ������ ����
	if (element->left != NULL) {
		// (1) ������ ������ - ����� ���� �������� ������
		if (element->left->right == NULL && element->left->left == NULL) {
			element->left = NULL;
		}
		else removeElement(element->left);
	}
	// �������� ������� ����
	if (element->right != NULL) {
		// (1) ������ ������ - ������ ���� �������� ������
		if (element->right->right == NULL && element->right->left == NULL) {
			element->right = NULL;
		}
		else removeElement(element->right);

	}
}
// �������� ����
void removeElement(Element* element) {
	// (2) ������ ������ - ���������� � ����� � ������ ����
	if (element->right != NULL && element->left != NULL) {
		int i = findBigest(element);
		element->data = i;
	}
	else
		// (3) ������ ������ - ���������� ������ ������ ��� ������ ����� ����
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
// ���������� �������� ����������� ����
int findBigest(Element*tree) {
	if (tree->right->right == NULL) {
		int result = tree->right->data;
		tree->right = NULL;
		return result;
	}
	return findBigest(tree->right);
}
// �������� ������� ������ ������
void removeMiddle(Element* tree){
	Queue* q = createQueue();
	pushElement(q, tree);
	int h = height(tree)/2;
	printf("\n�������� ������ %d\n", h);
	printf("���������:");
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
// �������� ���� �� ������� �����
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
