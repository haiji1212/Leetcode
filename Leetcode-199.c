#include<stdio.h>
#include<stdlib.h>

//【199】二叉树的右视图
// 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#define MAXSIZE 100
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
int getHeight(struct TreeNode* root){   //计算二叉树的高度
    if(root == NULL)    return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (1 + (leftHeight > rightHeight ? leftHeight : rightHeight));
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(root == NULL){
        return NULL;
    }
    int height = getHeight(root);   //计算出二叉树的高度
    int* ret = (int*)malloc(sizeof(int) * height);
    SqQueue queue;
    if(!InitQueue(&queue))  return NULL;
    EnQueue(&queue, root);  //根结点入队
    while(!EmptyQueue(&queue)){     //队列不为空
        int levelSize = QueueLength(&queue);    //计算当前队列元素个数
        for(int i = 0; i < levelSize; i++){
            struct TreeNode* newNode = DeQueue(&queue);
            if(newNode->left != NULL)   EnQueue(&queue, newNode->left);
            if(newNode->right != NULL)  EnQueue(&queue, newNode->right);
            if(i == levelSize - 1){     //最右结点
                ret[(*returnSize)++] = newNode->val;
            }
        }
    }
    DestroyQueue(&queue);
    return ret;
}