#include<stdio.h>
#include<stdlib.h>

//【19】删除链表中的倒数第N个结点
// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
// 进阶：你能尝试使用一趟扫描实现吗？
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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode)); //设置虚拟头结点
    newNode->next = head;
    struct ListNode* fast = newNode;    //设置双节点-fast
    struct ListNode* slow = newNode;    //设置双结点-slow
    int i = 0;
    while(i <= n && fast)   //先走n+1步
    {
        fast = fast->next;
        i++;
    }       
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode* temp = slow->next;
    slow->next = temp->next;
    free(temp);
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
    int number[] = {0, 1, 2, 3, 4, 5};
    int size = sizeof(number) / sizeof(number[0]);
    struct ListNode* head = ListCreate(number, size);
    DBG(head);
    DBG(removeNthFromEnd(head, 2));
    return 0;
}