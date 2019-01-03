#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <malloc.h>
#include <math.h>
//---------------------------------------------------------------------------//
/*
				Лабораторная работа № 14
учебной группы 61391
Волкова А.А.
Дата выполнения: 28.11.2018
Тема работы: «Разработка, отладка и испытание программ обработки стеков и очередей»
Задание: Заполнить стек N случайными числами из интервала [-10;80].
Найти количество чисел, которые при делении на 5 дают в остатке 3.
*/
//---------------------------------------------------------------------------//
typedef struct Stack {
	int data[100];
	int size;
	int maxSize;
} Stack;
// Функция заполнения стека
void fillStack(Stack*);
// Функция добавления элемента в стек
void push(Stack*, int);
// Функция изъятия элемента из стек
int pop(Stack*);
// Функция вывода элементов стека в консоль
void printStack(Stack*);
// Функция вывода элементов стека в консоль, которые при делении на 5 дают в остатке 3
void findItems(Stack);
// Функция 
void reverseStack(Stack*);
// Функция создания стека
Stack* createStack(int);

void main(int argc, char* argv[]) {
	// Добавляем кириллицу в консоль
	setlocale(0, "Russian");
	int n;
	do { // Считывание размера стека
		printf("Введите размер стека(меньше 100)\n");
		scanf("%d", &n);
	} while (n > 100 || n < 0);
	Stack* stack = createStack(n);
	// Заполнение стека
	fillStack(stack);
	// Вывод элементов стека в консоль
	printStack(stack);
	// Вывод элементов массива, которые при делении на 5 дают в остатке 3
	findItems(*stack);
	getch();
}
// Функция создания стека
Stack * createStack(int maxSize)
{
	Stack* stack = malloc(sizeof(Stack));
	stack->maxSize = maxSize;
	stack->data[0] = -10 + rand() % 91;
	stack->size = 0;
	return stack;
}
// Функция добавления элемента в стек
void push(Stack* stack, int value) {
	if (stack->maxSize > stack->size) {
		stack->data[stack->size++] = value;
	}
}
// Функция изъятия элемента из стек
int pop(Stack* stack) {
		return stack->size > 0 ? stack->data[--(stack->size)] : 0;
}
// Функция заполнения стека
void fillStack(Stack* stack){
	stack->size = 0;
	for (int i = 0; i < stack->maxSize; i++) {
		int value = -10 + rand() % 91;
		push(stack, value);
	}
}
// Функция вывода элементов стека в консоль
void printStack(Stack* stack) {
	Stack * new = createStack(stack->maxSize);
	int value;
	printf("\nСтек:\n\n");
	for (int i = stack->size; i > 0; i--) {
		value = pop(stack);
		printf("элемент стека[%d]:%d\n", i, value);
		push(new, value);
	}
	printf("\n");
	reverseStack(new);
	*stack = *new;
}
// Функция вывода элементов стека в консоль, которые при делении на 5 дают в остатке 3
void findItems(Stack stack) {
	printf("Элементы стейка, которые при делении на 5 дают в остатке 3:\n\n");
	for (int i = stack.size; i > 0; i--) {
		int value = pop(&stack);
		if((value % 5) == 3){
		printf("элемент стека[%d]:%d\n", i, value);
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
