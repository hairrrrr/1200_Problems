#define _CRT_SECURE_NO_WARNINGS 1

#include"queue_stack.h"
#include"queue.h"
#include<stdlib.h>
#include<stdbool.h>

MyStack* myStackCreate() {
	
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	queueInit(&obj->q);

	return obj;
}


void myStackPush(MyStack* obj, DataType x) {
	
	queuePush(&obj->q, x);
}


DataType myStackPop(MyStack* obj) {
	
	DataType size = queueSize(&obj->q);
	// 让队尾前的元素出队然后入队，最后让队尾出队
	while (size > 1) {
		int front = queuePop(&obj->q);
		queuePush(&obj->q, front);
		size--;
	}
	
	return queuePop(&obj->q);
}


DataType myStackTop(MyStack* obj) {
	return queuePeek(&obj->q);
}


bool myStackEmpty(MyStack* obj) {
	return queueIsEmpty(&obj->q);
}


void myStackFree(MyStack* obj) {
	queueDestory(&obj->q);
	free(obj);
}
