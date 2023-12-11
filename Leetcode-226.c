#include<stdio.h>
#include<stdlib.h>

//【226】翻转二叉树
// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* swapNode(struct TreeNode* root){
    if(root == NULL)    return NULL;
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL)    return NULL;
    swapNode(root);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}