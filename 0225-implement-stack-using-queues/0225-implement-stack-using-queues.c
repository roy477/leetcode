#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int q[100];
    int front;
    int rear;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->front = 0;
    obj->rear = -1;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    obj->q[++obj->rear] = x;

    int size = obj->rear - obj->front + 1;
    for(int i = 0; i < size-1; i++){
        obj->q[++obj->rear] = obj->q[obj->front++];
    }
}

int myStackPop(MyStack* obj) {
    return obj->q[obj->front++];
}

int myStackTop(MyStack* obj) {
    return obj->q[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->front > obj->rear;
}

void myStackFree(MyStack* obj) {
    free(obj);
}