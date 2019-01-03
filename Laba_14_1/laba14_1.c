#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
//---------------------------------------------------------------------------//
/*
				������������ ������ � 14
������� ������ 61391
������� �.�.
���� ����������: 28.11.2018
���� ������: �����������, ������� � ��������� �������� ��������� ������ � ��������
�������: ��������� ���� N ���������� ������� �� ��������� [-10;80].
����� ���������� �����, ������� ��� ������� �� 5 ���� � ������� 3.
*/
//---------------------------------------------------------------------------//
typedef struct Stack {
	int data[100];
	int size;
	int maxSize;
} Stack;
// ������� ���������� �����
void fillStack(Stack*);
// ������� ���������� �������� � ����
void push(Stack*, int);
// ������� ������� �������� �� ����
int pop(Stack*);
// ������� ������ ��������� ����� � �������
void printStack(Stack*);
// ������� ������ ��������� ����� � �������, ������� ��� ������� �� 5 ���� � ������� 3
void findItems(Stack);
// ������� 
void reverseStack(Stack*);
// ������� �������� �����
Stack* createStack(int);

void main(int argc, char* argv[]) {
	// ��������� ��������� � �������
	setlocale(0, "Russian");
	int n;
	do { // ���������� ������� �����
		printf("������� ������ �����(������ 100)\n");
		scanf("%d", &n);
	} while (n > 100 || n < 0);
	Stack* stack = createStack(n);
	// ���������� �����
	fillStack(stack);
	// ����� ��������� ����� � �������
	printStack(stack);
	// ����� ��������� �������, ������� ��� ������� �� 5 ���� � ������� 3
	findItems(*stack);
	getch();
}
// ������� �������� �����
Stack * createStack(int maxSize)
{
	Stack* stack = malloc(sizeof(Stack));
	stack->maxSize = maxSize;
	stack->data[0] = -10 + rand() % 91;
	stack->size = 0;
	return stack;
}
// ������� ���������� �������� � ����
void push(Stack* stack, int value) {
	if (stack->maxSize > stack->size) {
		stack->data[stack->size++] = value;
	}
}
// ������� ������� �������� �� ����
int pop(Stack* stack) {
		return stack->size > 0 ? stack->data[--(stack->size)] : 0;
}
// ������� ���������� �����
void fillStack(Stack* stack){
	stack->size = 0;
	for (int i = 0; i < stack->maxSize; i++) {
		int value = -10 + rand() % 91;
		push(stack, value);
	}
}
// ������� ������ ��������� ����� � �������
void printStack(Stack* stack) {
	Stack * new = createStack(stack->maxSize);
	int value;
	printf("\n����:\n\n");
	for (int i = stack->size; i > 0; i--) {
		value = pop(stack);
		printf("������� �����[%d]:%d\n", i, value);
		push(new, value);
	}
	printf("\n");
	reverseStack(new);
	*stack = *new;
}
// ������� ������ ��������� ����� � �������, ������� ��� ������� �� 5 ���� � ������� 3
void findItems(Stack stack) {
	printf("�������� ������, ������� ��� ������� �� 5 ���� � ������� 3:\n\n");
	for (int i = stack.size; i > 0; i--) {
		int value = pop(&stack);
		if((value % 5) == 3){
		printf("������� �����[%d]:%d\n", i, value);
		}
	}
}
void reverseStack(Stack*stack) {
	Stack * new = createStack(stack->maxSize);
	int value;
	int size = stack->size;
	for (int i = 0; i < size; i++) {
		value = pop(stack);
		push(new, value);
	}
	*stack = *new;
}
