#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//【101】对称二叉树
// 给你一个二叉树的根节点 root ， 检查它是否轴对称。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool Compare(struct TreeNode* left, struct TreeNode* right){
    if(left == NULL && right == NULL)   return true;    //左右结点都是空，则对称
    else if((left != NULL && right == NULL) || (right != NULL && left == NULL))     return false;    //左或右结点有一个为空，另一个不为空
    else if(left->val != right->val)    return false;   //左右结点不为空但值不相等
    //左右结点不为空且值相等
    bool result1 = Compare(left->left, right->right);
    bool result2 = Compare(left->right, right->left);
    bool issame = result1 && result2;
    return issame;
}
bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)    return NULL;
    return Compare(root->left, root->right);
}