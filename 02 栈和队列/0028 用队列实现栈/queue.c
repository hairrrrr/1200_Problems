#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdbool.h>
#include"queue.h"

void queueInit(Queue* q) {

	// 初始化空队列
	q->front = q->rear = NULL;
	q->size = 0;
}


Node* creatNode(DataType data) {

	Node* new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL) {
		exit(EXIT_FAILURE);
	}

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}


void queuePush(Queue* q, DataType data) {

	Node* new_node = creatNode(data);

	if (queueIsEmpty(q) == true) {
		q->front = q->rear = new_node;
	}
	else {
		q->rear->next = new_node;
		q->rear = new_node;
	}
	q->size++;
}


DataType queuePop(Queue* q) {

	DataType ret;
	Node* ele_pop;

	if (queueIsEmpty(q) == true) {
		exit(EXIT_FAILURE);
	}

	ele_pop = q->front;
	ret = ele_pop->data;
	q->front = ele_pop->next;
	free(ele_pop);

	if (queueIsEmpty(q) == true) {
		q->rear = NULL;
	}

	q->size--;

	return ret;
}

DataType queuePeek(Queue* q) {

	if (!queueIsEmpty(q))
		return q->front->data;
	else
		return -1;
}

DataType queueSize(Queue* q) {
	
	return q->size;
}

bool queueIsEmpty(Queue* q) {

	if (q->front == NULL)
		return true;
	return false;
}


void queueDestory(Queue* q) {

	Node* cur = q->front;

	for (; cur != NULL; cur = q->front) {
		q->front = cur->next;
		free(cur);
	}

	q->front = q->rear = NULL;
	q->size == 0;
}
