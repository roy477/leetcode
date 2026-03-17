#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_MAX 100

typedef struct {
    int items[QUEUE_MAX];
    int top;
} MyStack;

typedef struct {
    MyStack s1; // push stack
    MyStack s2; // pop stack
} MyQueue;

void stackInit(MyStack* s) { s->top = -1; }
void stackPush(MyStack* s, int x) { s->items[++(s->top)] = x; }
int  stackPop(MyStack* s)         { return s->items[(s->top)--]; }
int  stackPeek(MyStack* s)        { return s->items[s->top]; }
bool stackEmpty(MyStack* s)       { return s->top == -1; }

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    stackInit(&q->s1);
    stackInit(&q->s2);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(&obj->s1, x);
}

int myQueuePop(MyQueue* obj) {
    if (stackEmpty(&obj->s2)) {
        while (!stackEmpty(&obj->s1))
            stackPush(&obj->s2, stackPop(&obj->s1));
    }
    return stackPop(&obj->s2);
}

int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(&obj->s2)) {
        while (!stackEmpty(&obj->s1))
            stackPush(&obj->s2, stackPop(&obj->s1));
    }
    return stackPeek(&obj->s2);
}

bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(&obj->s1) && stackEmpty(&obj->s2);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}