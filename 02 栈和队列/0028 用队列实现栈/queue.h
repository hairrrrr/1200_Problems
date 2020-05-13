#ifndef QUEUE
#define QUEUE

#include<stdbool.h>

typedef int DataType;

typedef struct Node
{
	struct Node* next;
	DataType data;
}Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
	int size;
}Queue;

void queueInit(Queue* q);
// 创建队列结点
Node* creatNode(DataType data);
// 入队
void queuePush(Queue* q, DataType data);
// 出队
DataType queuePop(Queue* q);

DataType queuePeek(Queue* q);

DataType queueSize(Queue* q);

// 判空
bool queueIsEmpty(Queue* q);
// 销毁
void queueDestory(Queue* q);

#endif
