#include<stdio.h>
#include<stdlib.h>

//【144】二叉树的前序遍历
// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

//定义二叉树结构
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//前序遍历：
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