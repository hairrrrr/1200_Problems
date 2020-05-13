#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stack.h"

typedef struct Stack
{
	DataType* array;
	size_t size;
	size_t capacity;
}Stack;

Stack* stackInit(size_t n) {

	Stack* s = (Stack*)malloc(sizeof(Stack));

	s->array = (DataType*)malloc(sizeof(DataType) * n);

	if (s->array == NULL) {
		exit(EXIT_FAILURE);
	}

	s->size = 0;
	s->capacity = n;

	return s;
}

void stackPush(Stack* s, DataType data) {
	
	if (stackIsFull(s) == true) {
		s->capacity *= 2;
		s->array = (DataType*)realloc(s->array, s->capacity * sizeof(DataType));
	}

	s->array[s->size++] = data;
}

DataType stackPop(Stack* s) {

	if (stackIsEmpty(s) == true) {
		exit(EXIT_FAILURE);
	}

	return s->array[--s->size];
}

DataType stackPeek(Stack* s) {
	return s->array[s->size - 1];
}

size_t stackSize(Stack* s) {

	return s->size;
}

bool stackIsEmpty(Stack* s) {
	if (s->size == 0)
		return true;
	return false;
}

bool stackIsFull(Stack* s) {
	if (s->size == s->size)
		return true;
	return false;
}

void stackDestory(Stack* s) {

	free(s->array);
	s->array = NULL;
	s->capacity = s->size = 0;
}
