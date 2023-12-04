#include<stdio.h>
#include<stdlib.h>

//【145】二叉树的后序遍历
// 给你二叉树的根节点 root ，返回它节点值的 后序 遍历。

//定义二叉树结构
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//后序遍历：
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