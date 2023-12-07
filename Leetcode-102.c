#include<stdio.h>
#include<stdlib.h>

//【102】二叉树的层序遍历
// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#define MAXSIZE 2000
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
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root == NULL){
        *returnSize = 0;
        *returnColumnSizes = NULL; 
        return NULL;
    }
    int height = getHeight(root);   //计算出二叉树的高度
    int** ret = (int**)malloc(height * sizeof(int*));   //创建二维数组
    *returnColumnSizes = (int*)malloc(height * sizeof(int));
    for(int i = 0; i < height; i++){    //初始化
        (*returnColumnSizes)[i] = 0;
    }
    SqQueue queue;
    if(!InitQueue(&queue))  return NULL;
    EnQueue(&queue, root); //根结点入队
    int level = 0;
    while(!EmptyQueue(&queue)){ //队列不为空
        int levelSize = QueueLength(&queue);   //计算当前队列元素个数
        ret[level] = (int*)malloc(levelSize * sizeof(int)); //分配当前层结点的数组空间
        (*returnColumnSizes)[level] = levelSize;
        for(int i = 0; i < levelSize; i ++){    //遍历当前队列元素
            struct TreeNode* newNode = DeQueue(&queue); //出队
            ret[level][i] = newNode->val;   //将结点的值存入结果数组
            if(newNode->left != NULL)   EnQueue(&queue, newNode->left);
            if(newNode->right != NULL)  EnQueue(&queue, newNode->right);
        }
        level ++;
    }
    *returnSize = level;
    DestroyQueue(&queue);
    return ret;
}