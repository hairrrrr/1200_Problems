#define _CRT_SECURE_NO_WARNINGS 1

#include"myCircularQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


MyCircularQueue* myCircularQueueCreate(DataType k) {

	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	obj->queue = (int*)malloc(sizeof(int) * k);
	obj->capacity = k;
	obj->front = obj->rear = 0;
	obj->queue_size = 0;

	return obj;
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, DataType value) {
	
	if (myCircularQueueIsFull(obj))
		return false;

	obj->queue[obj->rear] = value;
	obj->rear = (obj->rear + 1) % obj->capacity;
	obj->queue_size++;

	return true;
}


bool myCircularQueueDeQueue(MyCircularQueue* obj) {

	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->front = (obj->front + 1) % obj->capacity;

	obj->queue_size--;

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
		return obj->queue[obj->capacity - 1];
	return obj->queue[obj->rear - 1];
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

	return obj->queue_size == 0;
}


bool myCircularQueueIsFull(MyCircularQueue* obj) {

	return obj->queue_size == obj->capacity;
}


void myCircularQueueFree(MyCircularQueue* obj) {

	free(obj->queue);
	obj->queue = NULL;
	free(obj);
}

