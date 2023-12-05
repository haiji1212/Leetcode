#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//【144】二叉树的前序遍历
// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

//定义二叉树结构
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//前序遍历：递归
void preOrder(struct TreeNode* root, int* ret, int* returnSize) {
    if(root == NULL)    return;
    ret[(*returnSize)++] = root->val;
    preOrder(root->left, ret, returnSize);
    preOrder(root->right, ret, returnSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 100);
    if(ret == NULL) return NULL;
    *returnSize = 0;
    preOrder(root, ret, returnSize);
    return ret;
}
//前序遍历：迭代
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

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    int* ret = (int*)malloc(sizeof(int) * 101);
    if (ret == NULL) return NULL;

    struct MyStack stack;
    if (!StackInit(&stack)) return NULL;

    Push(&stack, root);

    while (!Empty(&stack)) {
        struct TreeNode* node = Pop(&stack);
        ret[(*returnSize)++] = node->val;

        if (node->right) Push(&stack, node->right);
        if (node->left) Push(&stack, node->left);
    }

    DestroyStack(&stack);

    return ret;
}