#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//【98】验证二叉搜索树
//给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool fun(struct TreeNode* root, long low, long high) {
    if (root == NULL) return true;
    long num = root->val;
    if (num <= low || num >= high) return false;
    return fun(root->left, low, num) && fun(root->right, num, high);
}
bool isValidBST(struct TreeNode* root){
    return fun(root, LONG_MIN, LONG_MAX);
}

