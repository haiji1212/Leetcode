#include<stdio.h>
#include<stdlib.h>

//【02.07】链表相交
// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
// 如果两个链表没有交点，返回 null 。？
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

//不在本地ACM测试
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;
    //分别求出两个链表的长度
    int m = 0, n = 0, val;
    struct ListNode* temp1 = headA;
    struct ListNode* temp2 = headB;
    struct ListNode* fast;
    struct ListNode* slow;
    while(temp1)
    {
        m ++;
        temp1 = temp1->next;
    }
    while(temp2)
    {
        n ++;
        temp2 = temp2->next;
    }
    if(m >= n){
        fast = headA;
        slow = headB;
        val = m - n;
    }
    else{
        slow = headA;
        fast = headB;
        val = n - m;       
    }
    while(val--)
    {
        fast = fast->next;
    }
    while(fast && slow)
    {
        if(fast == slow)
            return fast;
        fast = fast->next;
        slow = slow->next;
    }
    return NULL;
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
    return 0;
}