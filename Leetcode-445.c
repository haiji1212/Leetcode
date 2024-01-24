#include <stdio.h>
#include <stdlib.h>

// 【445】两数相加II
// 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。
// 它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct LinkStack{
    struct ListNode *ptr;  // 链表结点指针
    struct LinkStack *next;  // 链栈指针
}StackNode, *StackPtr;

void push(StackPtr *stack, struct ListNode *node) {
    StackPtr q = (StackPtr)malloc(sizeof(StackNode));
    q->ptr = node;
    q->next = *stack;
    *stack = q;  // 头指针改变
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (!l1 || !l2) return l1 ? l1 : (l2 ? l2 : NULL);
    StackPtr stack1 = NULL, stack2 = NULL;
    while (l1) {
        push(&stack1, l1);
        l1 = l1->next;
    }
    while (l2) {
        push(&stack2, l2);
        l2 = l2->next;
    }

    struct ListNode *prev = NULL, *curr;
    int carry = 0;
    while (stack2 || stack1 || carry) {
        carry += (stack1 ? stack1->ptr->val : 0) + (stack2 ? stack2->ptr->val : 0);
        curr = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->val = carry % 10;
        carry /= 10;
        curr->next = prev;
        prev = curr;
        stack1 = stack1 ? stack1->next : 0;
        stack2 = stack2 ? stack2->next : 0;
    }
    return prev;
}
