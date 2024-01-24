#include <stdio.h>
#include <stdlib.h>

// 【21】合并两个有序链表
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* t = head;
    while(list1 && list2){
        if(list1->val < list2->val){
            t->next = list1;
            list1 = list1->next;
        }else{
            t->next = list2;
            list2 = list2->next;
        }
        t = t->next;
    }
    if(list1)    t->next = list1;
    if(list2)    t->next = list2;
    return head->next;
}
