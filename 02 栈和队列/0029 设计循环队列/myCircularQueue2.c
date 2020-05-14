#define _CRT_SECURE_NO_WARNINGS 1

#include"myCircularQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


MyCircularQueue* myCircularQueueCreate(DataType k) {

	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	obj->queue = (int*)malloc(sizeof(int) * (k + 1)); // 需要多一个元素用来判别队列空还是满
	// 注意：这里我们给 capacity 赋值是 k 而不是 k + 1，后面需要取模数组长度时需要注意
	obj->capacity = k;
	obj->front = obj->rear = 0;

	return obj;
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, DataType value) {
	
	if (myCircularQueueIsFull(obj))
		return false;

	obj->queue[obj->rear] = value;
	obj->rear = (obj->rear + 1) % (obj->capacity + 1);

	return true;
}


bool myCircularQueueDeQueue(MyCircularQueue* obj) {

	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->front = (obj->front + 1) % (obj->capacity + 1);


	return true;
}


DataType myCircularQueueFront(MyCircularQueue* obj) {
	
	if (myCircularQueueIsEmpty(obj))
		return -1;

	return obj->queue[obj->front];
	
}


DataType myCircularQueueRear(MyCircularQueue* obj) {

	if (myCircularQueueIsEmpty(obj))
		return -1;

	if(obj->rear - 1 < 0)
		return obj->queue[obj->capacity];
	return obj->queue[obj->rear - 1];
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}


bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return ((obj->rear + 1) % (obj->capacity + 1) == obj->front);
}


void myCircularQueueFree(MyCircularQueue* obj) {

	free(obj->queue);
	obj->queue = NULL;
	free(obj);
}

