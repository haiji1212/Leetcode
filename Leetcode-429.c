#include<stdio.h>
#include<stdlib.h>

//【429】N叉树的层序遍历
// 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
// 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
struct Node {
    int val;
    int numChildren;    //孩子个数
    struct Node** children; //孩子结点。可以理解成孩子数组
};
#define MAXSIZE 10000
typedef struct{
    struct Node** base;
    int front;
    int rear;
}SqQueue;   //循环队列
int InitQueue(SqQueue* Q){  //队列初始化
    Q->base = (struct Node**)malloc(MAXSIZE * sizeof(struct Node*));
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
int EnQueue(SqQueue* Q, struct Node* Node){ //入队
    if((Q->rear + 1) % MAXSIZE == Q->front)     return 0;
    Q->base[Q->rear] = Node;
    Q->rear = (Q->rear + 1) % MAXSIZE;  //队尾指针加一
    return 1;
}
struct Node* DeQueue(SqQueue* Q){ //出队
    if(Q->rear == Q->front) return NULL;
    struct Node* Node = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;    //队头指针加一
    return Node;
}
struct Node* GetHead(SqQueue* Q){   //取队头元素
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
int maxDepth(struct Node* root) {   //求结点的最大高度
    if (root == NULL)
        return 0;   
    int max_child_depth = 0;
    for (int i = 0; i < root->numChildren; i++) {
        int child_depth = maxDepth(root->children[i]);
        if (child_depth > max_child_depth)
            max_child_depth = child_depth;
    }  
    return max_child_depth + 1;
}
int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    if(root == NULL){
        *returnSize = 0;
        *returnColumnSizes = NULL; 
        return NULL;
    }
    int height = maxDepth(root);   //计算出N叉树的高度
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
            struct Node* newNode = DeQueue(&queue); //出队
            ret[level][i] = newNode->val;   //将结点的值存入结果数组
            for(int j = 0; j < newNode->numChildren; j ++){
                EnQueue(&queue, newNode->children[j]);
            }
        }
        level ++;
    }
    *returnSize = level;
    DestroyQueue(&queue);
    return ret;
}