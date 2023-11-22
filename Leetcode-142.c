#include<stdio.h>
#include<stdlib.h>

//【142】环形链表II
// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
// 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
// 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
// 不允许修改 链表。

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

//不作ACM模式练习
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL)
        return NULL;
    struct ListNode* fast = head;   //每次走两步
    struct ListNode* slow = head;   //每次走一步
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            struct ListNode* temp = fast;
            struct ListNode* currrent = head;
            while(currrent != temp){
                currrent = currrent->next;
                temp = temp->next;
            }
            return currrent;
        }
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