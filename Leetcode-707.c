#include <stdio.h>
#include <stdlib.h>
// 【707】设计链表
// 你可以选择使用单链表或者双链表，设计并实现自己的链表。
// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
// 实现 MyLinkedList 类：
// MyLinkedList() 初始化 MyLinkedList 对象。
// int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
// void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
// void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
// void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。
//  如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
// void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。

typedef struct MyLinkedList {
    int val;
    struct MyLinkedList* next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newNode->next = NULL;
    return newNode;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0)
        return -1;
    MyLinkedList* current = obj->next;
    int i = 0;
    while(current){
        if(i == index){
            return current->val;
        }
        else{
            i++;
            current = current->next;
        }
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newNode->val = val;
    newNode->next = obj->next;
    obj->next = newNode;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newNode->next = NULL;
    newNode->val = val;
    MyLinkedList* current = obj;
    while(current->next)
    {
        current = current->next;
    }
    current->next = newNode;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0)
        return;
    MyLinkedList* newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newNode->next = NULL;
    newNode->val = val;
    MyLinkedList* current = obj;    
    int i = -1;
    while(current){
        if(i == index - 1){
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        else{
            i++;
            current = current->next;
        }
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0)
        return;
    MyLinkedList* current = obj->next;
    MyLinkedList* temp;
    if(index == 0){
        temp = obj->next;
        if(temp){
            obj->next = temp->next;
            free(temp);
        }
        return;
    }
    int i = 0;
    while(current && current->next){
        if(i == index - 1){
            temp = current->next;
            if(temp)
            {
                current->next = temp->next;
                free(temp);
            }         
            return;
        }
        else{
            i ++;
            current = current->next;
        }
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    while(obj){
        MyLinkedList* tmp = obj;
        obj = obj->next;
        free(tmp);
}
}

//打印链表数据元素
void printLinkedList(MyLinkedList* head) {
    MyLinkedList* current = head->next; 
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    } 
    printf("\n");
}
int main(void){
    MyLinkedList* head = myLinkedListCreate();
    myLinkedListAddAtHead(head, 0);
    myLinkedListAddAtIndex(head, 1, 1);
    myLinkedListAddAtTail(head, 2);
    printLinkedList(head);
    myLinkedListDeleteAtIndex(head, 0);
    printLinkedList(head);
    return 0;
}