#include<stdio.h>
#include<stdlib.h>

//【637】二叉树的层平均值
// 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
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
int getHeight(struct TreeNode* root){   //计算二叉树的高度
    if(root == NULL)    return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (1 + (leftHeight > rightHeight ? leftHeight : rightHeight));
}
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(root == NULL)     return NULL; 
    int height = getHeight(root);
    double* ret = (double*)malloc(height * sizeof(double));
    SqQueue queue;
    if(!InitQueue(&queue))  return NULL;
    EnQueue(&queue, root); //根结点入队
    while(!EmptyQueue(&queue)){
        int levelSize = QueueLength(&queue);
        double sum = 0;
        for(int i = 0; i < levelSize; i++){
            struct TreeNode* newNode = DeQueue(&queue);
            if(newNode->left != NULL)   EnQueue(&queue, newNode->left);
            if(newNode->right != NULL)  EnQueue(&queue, newNode->right);
            sum += newNode->val;
        }
        ret[(*returnSize)++] = sum / levelSize;
    }
    DestroyQueue(&queue);
    return ret;
}