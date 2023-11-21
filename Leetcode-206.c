#include<stdio.h>
#include<stdlib.h>

//【206】反转链表
// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
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
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* pre = NULL;
    struct ListNode* current = head;
    struct ListNode* temp;
    while(current){
        temp = current->next;
        current->next = pre;
        pre = current;
        current = temp;
    }
    return pre;
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
    int number[] = {0, 1, 2, 3, 4, 5};
    int size = sizeof(number) / sizeof(number[0]);
    struct ListNode* head = ListCreate(number, size);
    DBG(head);
    DBG(reverseList(head));
    return 0;
}