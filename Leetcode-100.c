#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//【101】相同的树
// 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL)   return true;    //左右结点都是空，则对称
    else if((p != NULL && q == NULL) || (q != NULL && p == NULL))     return false;    //左或右结点有一个为空，另一个不为空
    else if(p->val != q->val)    return false;   //左右结点不为空但值不相等
    //左右结点不为空且值相等
    bool result1 = isSameTree(p->left, q->left);
    bool result2 = isSameTree(p->right, q->right);
    bool issame = result1 && result2;
    return issame;   
}