#include <stdio.h>
#include <stdlib.h>
// 单链表
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
//打印链表数据元素
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head; 
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    } 
    printf("\n");
}
//判断链表是否为空
int ListIsEmpty(struct ListNode* head) {
    struct ListNode* current = head;
    if(head)
        return 1;
    else
        return 0;
}
//链表的销毁
void DestroyListNode(struct ListNode* head){
    struct ListNode* current;
    while(head){
        current = head;
        head = current->next;
        free(current);
    }
    head = NULL;    //在函数调用之后需要head=NULL
} 
//链表的清空
void CLearListNode(struct ListNode* head){
    struct ListNode* current = head;
    struct ListNode* next;
    while(current){
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;    //在函数调用之后需要head=NULL
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
// 取值-取单链表中第i个元素的内容
int GetListNodeValue(struct ListNode* head, int loc){
    if(head == NULL || loc < 0 || loc > LengthOfListNode(head))
        return -1;
    struct ListNode* current = head;
    int i = 0, num = 0;;
    while(current != NULL && i++ < loc){
        current = current->next;
    }
    if(current == NULL)
        return -1;
    num = current->val;
    return num;
}
//按值查找-根据指定数据获取该数据所在的位置（地址）
struct ListNode* FindPos(struct ListNode* head, int val){
    if(head == NULL)
        return NULL;
    struct ListNode* current = head;
    while(current != NULL){
        if(current->val == val)
            return current;
        current = current->next;
    }
    return NULL;
}
//按值查找-根据指定数据获取该数据的位置序号
int FindIndex(struct ListNode* head, int val){
    if(head == NULL)
        return -1;
    struct ListNode* current = head;
    int p = 0;
    while(current != NULL){
        if(current->val == val)
            return p;
        current = current->next;
        p++;
    }
    return -1;
}
//插入-在第i个结点之前插入值为e的新结点
int InsertNode(struct ListNode* head, int i, int val){
    if(head == NULL || i > (LengthOfListNode(head)) || i < 0)
        return -1;
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->val = val;
    p->next = NULL;
    struct ListNode* current = head;
    if (i == 0) {
        p->next = head;
        head = p;
        return 0;
    }
    int j = 0;
    while(current && j < i-1){
        j ++;
        current = current->next;
    }
    if(current == NULL)
        return -1;
    p->next = current->next;
    current->next = p;
    return 0;
}
//删除-删除第i个结点
int DeleteNode(struct ListNode* head, int i){
    if(head == NULL || i > (LengthOfListNode(head)) || i < 0)
        return -1;
    if (i == 0) {
        struct ListNode* p = head;
        head = head->next;
        free(p);
        return 0;
    }
    struct ListNode* current = head;
    struct ListNode* p;
    int j = 0;
    while(current && j < i - 1){
        j++;
        current = current->next;
    }
    if(current == NULL)
        return -1;
    p = current->next;
    current->next = p->next;
    free(p);
    return 0;
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
    int values[] = {1,2,3};
    int size = sizeof(values)/sizeof(values[0]);
    struct ListNode* head = createLinkedList(values, size);
    ListNodeDBG(head);
    return 0;
}
