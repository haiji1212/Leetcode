#include <stdio.h>
#include <stdlib.h>
// 【203】移除链表元素
// 给你一个链表的头节点 head 和一个整数 val ，
//请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

//  定义链表结构体
 struct ListNode {
    int val;
    struct ListNode *next;
};
//创建并返回一个新的链表结点
struct ListNode* createNode(int value){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}
//创建链表，并返回头节点的指针
struct ListNode* createLinkedList(int* values, int size)
{
    if(size == 0)
        return NULL;
    struct ListNode* head = createNode(values[0]);
    struct ListNode* current = head;
    for(int i = 1; i < size; i++){
        struct ListNode* newNode = createNode(values[i]);
        current->next = newNode;
        current = current->next;
    }
    return head;
}
//判断链表是否为空
int ListIsEmpty(struct ListNode* head) {
    struct ListNode* current = head;
    if(head)
        return 1;
    else
        return 0;
}
//求链表的表长
int LengthOfListNode(struct ListNode* head){
    if(head == NULL){
        return 0;
    }
    int length = 0;
    struct ListNode* current = head;
    while(current){
        length ++;
        current = current->next;
    }
    return length;
}
//打印链表
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head; 
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    } 
    printf("\n");
}
//移除链表元素
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL)
        return NULL;
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->next = head;
    head = p;
    struct ListNode* current = head;
    struct ListNode* a;
    while(current->next){
        if(current->next->val == val){
            a = current->next;
            current->next = a->next;
            free(a);
        }
        else{
            current = current->next;  
        }      
    }
    head = head->next;
    free(p);
    return head;
}
//DBG
void ListNodeDBG(struct ListNode* head){
    printLinkedList(head);
    if(ListIsEmpty(head)) printf("ListNode Is Not Empty!\n");
    else    printf("ListNode Is Empty!\n");
    int length = LengthOfListNode(head);
    printf("Length is %d\n",length);
}
int main(void){
    int values[] = {2,2};
    int size = sizeof(values)/sizeof(values[0]);
    struct ListNode* head = createLinkedList(values, size);
    ListNodeDBG(head);
    struct ListNode* test_head = removeElements(head, 2);
    ListNodeDBG(test_head);
    return 0;
}
