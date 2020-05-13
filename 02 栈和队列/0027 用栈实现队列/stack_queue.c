#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stackQueue.h"
#include"stack.h"

// 两个栈的转换，static 类似 private 的用法
static void myQueueTransfer(Stack* from, Stack* to) {
	while (!stackIsEmpty(from))
		stackPush(to, stackPop(from));
}

MyQueue* myQueueCreate() {

	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	obj->stackIn = stackInit(QUEUE_SIZE);
	obj->stackOut = stackInit(QUEUE_SIZE);

	return obj;
}

void myQueuePush(MyQueue* obj, DataType x) {

	if (!myQueueFull(obj)) {
		stackPush(obj->stackIn, x);
	}
}


DataType myQueuePop(MyQueue* obj) {

	if (!myQueueEmpty(obj)) {
		if (!stackIsEmpty(obj->stackOut))
			return stackPop(obj->stackOut);

		myQueueTransfer(obj->stackIn, obj->stackOut);
		return stackPop(obj->stackOut);
	}
	else {
		exit(EXIT_FAILURE);
	}
}


DataType myQueuePeek(MyQueue* obj) {
	if (!myQueueEmpty(obj)) {
		if (!stackIsEmpty(obj->stackOut))
			return stackPeek(obj->stackOut);

		myQueueTransfer(obj->stackIn, obj->stackOut);
		return stackPeek(obj->stackOut);
	}
	else {
		exit(EXIT_FAILURE);
	}
}


bool myQueueEmpty(MyQueue* obj) {

	return stackSize(obj->stackIn) && stackSize(obj->stackOut);
}

bool myQueueFull(MyQueue* obj) {
	return stackSize(obj->stackIn) + stackSize(obj->stackOut) == QUEUE_SIZE;
}


void myQueueFree(MyQueue* obj) {

	stackDestory(obj->stackIn);
	stackDestory(obj->stackOut);
	obj->stackIn = obj->stackOut = NULL;
	free(obj);
}
