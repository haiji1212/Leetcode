#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//【222】完全二叉树的结点个数
// 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int countNodes(struct TreeNode* root) {
    if(root == NULL)    return NULL;
    int leftcount = countNodes(root->left);
    int rightcount = countNodes(root->right);
    return leftcount+rightcount+1;
}