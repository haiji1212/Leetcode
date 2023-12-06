#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//【144】二叉树的中序遍历
// 给你二叉树的根节点 root ，返回它节点值的 中序 遍历。

//定义二叉树结构
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//中序遍历：递归
void inOrder(struct TreeNode* root, int* ret, int* returnSize) {
    if(root == NULL)    return;
    inOrder(root->left, ret, returnSize);
    ret[(*returnSize)++] = root->val;
    inOrder(root->right, ret, returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 100);
    if(ret == NULL) return NULL;
    *returnSize = 0;
    inOrder(root, ret, returnSize);
    return ret;
}
//中序遍历：迭代
struct MyStack {
    struct TreeNode** top;
    struct TreeNode** base;
    int stacksize;
};

int StackInit(struct MyStack* s) {
    s->base = (struct TreeNode**)malloc(101 * sizeof(struct TreeNode*));
    if (!s->base) return 0;
    s->top = s->base;
    s->stacksize = 101;
    return 1;
}

int Push(struct MyStack* s, struct TreeNode* node) {
    if (s->top - s->base == s->stacksize) return 0;
    *(s->top++) = node;
    return 1;
}

struct TreeNode* Pop(struct MyStack* s) {
    if (s->base == s->top) return NULL;
    struct TreeNode* node = *(--(s->top));
    return node;
}

bool Empty(struct MyStack* s) {
    return s->top == s->base;
}

void DestroyStack(struct MyStack* s) {
    free(s->base);
    s->base = NULL;
    s->top = NULL;
    s->stacksize = 0;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(root == NULL)    return NULL;
    int* ret = (int*)malloc(sizeof(int) * 100);
    if(ret == NULL) return NULL;
    struct MyStack stack;
    if(!StackInit(&stack))  return NULL;
    struct TreeNode* current = root;    //从根结点开始
    int flag = 0;
    while(!flag){   //flag 为 1， 即遍历结束
        if(current != NULL){
            Push(&stack, current);  //当前元素入栈
            current = current->left;    //遍历左叶子结点
        }else{
            if(!Empty(&stack)){ //栈不为空
                current = Pop(&stack);
                ret[(*returnSize)++] = current->val;
                current = current->right;
            }else{  //栈空，即元素遍历完成
                flag = 1;   //退出遍历
            }
        }
    }
    return ret;
}