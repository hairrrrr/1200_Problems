#ifndef STACK_QUEUE
#define STCK_QUEUE

#include"stack.h"

#define QUEUE_SIZE 50

typedef int DataType;

typedef struct {
	Stack* stackIn;
	Stack* stackOut;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate();

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, DataType x);

/** Removes the element from in front of queue and returns that element. */
DataType myQueuePop(MyQueue* obj);

/** Get the front element. */
DataType myQueuePeek(MyQueue* obj);

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj);

bool myQueueFull(MyQueue* obj);

void myQueueFree(MyQueue* obj);

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * DataType param_2 = myQueuePop(obj);

 * DataType param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

#endif
