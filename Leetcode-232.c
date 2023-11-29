#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//【232】用栈实现队列
// 请你仅使用两个栈实现先入先出队列。
// 队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
// 实现 MyQueue 类：
// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false
// 当执行入队操作时，将元素压入输入栈中。
// 当执行出队操作时，首先检查输出栈是否为空，
// 如果为空，则将输入栈中的元素依次弹出并压入输出栈中（这样顺序就被倒转了），然后从输出栈弹出元素作为出队的结果。
// 如果输出栈不为空，则直接从输出栈中弹出元素作为出队的结果。
typedef struct {
    int stackInTop, stackOutTop;
    int stackIn[100], stackOut[100];    
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stackInTop = 0;
    queue->stackOutTop = 0;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stackIn[obj->stackInTop++] = x;
}

int myQueuePop(MyQueue* obj) {
    int stackInTop = obj->stackInTop;
    int stackOutTop = obj->stackOutTop;
    if(stackOutTop == 0){
        while(stackInTop > 0){
            obj->stackOut[stackOutTop++] = obj->stackIn[--stackInTop];
        }
    }
    int top = obj->stackOut[--stackOutTop];
    while(stackOutTop > 0){
        obj->stackIn[stackInTop++] = obj->stackOut[--stackOutTop];
    }
    obj->stackInTop = stackInTop;
    obj->stackOutTop = stackOutTop;
    return top;    
}

int myQueuePeek(MyQueue* obj) {
    return obj->stackIn[0];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->stackInTop == 0 && obj->stackInTop == 0;
}

void myQueueFree(MyQueue* obj) {
    obj->stackInTop = 0;
    obj->stackOutTop = 0;
}