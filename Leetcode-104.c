#include<stdio.h>
#include<stdlib.h>

//【104】 二叉树的最大深度
// 给定一个二叉树 root ，返回其最大深度。二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#define MAXSIZE 10000
typedef struct{
    struct TreeNode** base;
    int front;
    int rear;
}SqQueue;   //循环队列
int InitQueue(SqQueue* Q){  //队列初始化
    Q->base = (struct TreeNode**)malloc(MAXSIZE * sizeof(struct TreeNode*));
    if(!Q->base){
        free(Q->base);
        return 0;
    }
    Q->front = Q->rear = 0;
    return 1;
}
int QueueLength(SqQueue* Q){    //求队列的长度
    return ((Q->rear - Q->front + MAXSIZE) % MAXSIZE);
}
int EnQueue(SqQueue* Q, struct TreeNode* Node){ //入队
    if((Q->rear + 1) % MAXSIZE == Q->front)     return 0;
    Q->base[Q->rear] = Node;
    Q->rear = (Q->rear + 1) % MAXSIZE;  //队尾指针加一
    return 1;
}
struct TreeNode* DeQueue(SqQueue* Q){ //出队
    if(Q->rear == Q->front) return NULL;
    struct TreeNode* Node = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;    //队头指针加一
    return Node;
}
struct TreeNode* GetHead(SqQueue* Q){   //取队头元素
    if(Q->front != Q->rear){
        return Q->base[Q->front];
    }
    else return NULL;
}
int EmptyQueue(SqQueue* Q){
    return Q->front == Q->rear;
}
void DestroyQueue(SqQueue* Q) {
    free(Q->base);
    Q->front = 0;
    Q->rear = 0;
}
int maxDepth(struct TreeNode* root) {
    if(root == NULL)    return 0;
    int deepth = 0;
    SqQueue queue;
    if(!InitQueue(&queue))  return NULL;
    EnQueue(&queue, root); //根结点入队
    while(!EmptyQueue(&queue)){
        deepth ++;
        int levelSize = QueueLength(&queue);
        for(int i = 0; i < levelSize; i++){
            struct TreeNode* newNode = DeQueue(&queue);
            if(newNode->left != NULL)   EnQueue(&queue, newNode->left);
            if(newNode->right != NULL)  EnQueue(&queue, newNode->right);            
        }
    }
    DestroyQueue(&queue);
    return deepth;
}