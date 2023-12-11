#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//【572】相同的树
// 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
// 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
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
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if(root == NULL) return false;
    return compare(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
}