#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//【145】二叉树的后序遍历
// 给你二叉树的根节点 root ，返回它节点值的 后序 遍历。

//定义二叉树结构
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//后序遍历：递归
void postOrder(struct TreeNode* root, int* ret, int* returnSize) {
    if(root == NULL)    return;
    postOrder(root->left, ret, returnSize);
    postOrder(root->right, ret, returnSize);
    ret[(*returnSize)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 100);
    if(ret == NULL) return NULL;
    *returnSize = 0;
    postOrder(root, ret, returnSize);
    return ret;
}
//后序遍历：迭代
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

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(root == NULL)    return NULL;
    int* ret = (int*)malloc(sizeof(int) * 100);
    if(ret == NULL) return NULL;
    struct MyStack stack;
    if(!StackInit(&stack))  return NULL;
    struct TreeNode* current = root;
    Push(&stack, current);  //根结点入栈
    while(!Empty(&stack)){
        current = Pop(&stack);
        ret[(*returnSize)++] = current->val;
        if(current->left)   Push(&stack, current->left);    //左结点入栈
        if(current->right)  Push(&stack, current->right);   //右结点入栈
    }
    DestroyStack(&stack);
    int left = 0;
    int right = *(returnSize) - 1;
    while(left < right){
        int temp = ret[left];
        ret[left++] = ret[right];
        ret[right--] = temp;
    }
    return ret;
}