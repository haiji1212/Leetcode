#include<stdio.h>
#include<stdlib.h>

//【24】两两交换链表中的结点
// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
//你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* createNode(int value){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}
struct ListNode* ListCreate(int* nums, int size){
    if(size == 0)
        return NULL;
    struct ListNode* head = createNode(nums[0]);
    struct ListNode* current = head;
    for(int i = 1; i < size; i ++){
        struct ListNode* newNode = createNode(nums[i]);
        current->next = newNode;
        current = current->next;
    }
    return head;
}
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));   //设置虚拟头结点
    newNode->next = head;
    struct ListNode* current = newNode;
    while(current->next && current->next->next){
        struct ListNode* temp1 = current->next;
        struct ListNode* temp2 = current->next->next->next;
        current->next = current->next->next;
        current->next->next = temp1;
        current->next->next->next = temp2;

        current = current->next->next;
    }
    return newNode->next;
}
void DBG(struct ListNode* head){
    if(head == NULL)
        return;
    struct ListNode* current = head;
    while(current){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    int number[] = {0, 1, 2, 3, 4};
    int size = sizeof(number) / sizeof(number[0]);
    struct ListNode* head = ListCreate(number, size);
    DBG(head);
    DBG(swapPairs(head));
    return 0;
}