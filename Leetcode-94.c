#include<stdio.h>
#include<stdlib.h>

//【144】二叉树的中序遍历
// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

//定义二叉树结构
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//中序遍历：
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