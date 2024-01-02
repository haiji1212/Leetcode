#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//【700】二叉搜索树中的搜索
// 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
// 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if(root == NULL || root->val == val)    return root;    //根结点为空或者根结点为目标值，直接返回
    struct TreeNode* newNode = NULL;
    if(root->val < val)
        newNode = searchBST(root->right, val);
    else if(root->val > val)
        newNode = searchBST(root->left, val);
    return newNode;
}

