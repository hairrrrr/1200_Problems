#ifndef QUEUE_STACK
#define QUEUE_STACK

#include"queue.h"
#include<stdbool.h>

typedef int DataType;

typedef struct {
	Queue q;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate();

/** Push element x onto stack. */
void myStackPush(MyStack* obj, DataType x);

/** Removes the element on top of the stack and returns that element. */
DataType myStackPop(MyStack* obj);

/** Get the top element. */
DataType myStackTop(MyStack* obj);

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj);

void myStackFree(MyStack* obj);

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * DataType param_2 = myStackPop(obj);

 * DataType param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

#endif
