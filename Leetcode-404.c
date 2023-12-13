#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//【404】左叶子之和
// 给定二叉树的根节点 root ，返回所有左叶子之和。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int sumOfLeftLeaves(struct TreeNode* root){
    if(root == NULL)    return 0;
    if(root->left == NULL && root->right == NULL)   return 0;
    int leftleave = sumOfLeftLeaves(root->left);
    if(root->left && !root->left->left && !root->left->right)   leftleave = root->left->val;
    int rightleave = sumOfLeftLeaves(root->right);
    return leftleave + rightleave;
}
