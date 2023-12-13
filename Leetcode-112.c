#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//【112】路径之和
// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
// 如果存在，返回 true ；否则，返回 false 。
// 叶子节点 是指没有子节点的节点。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool traversal(struct TreeNode* cur, int count){
    if(!cur->left && !cur->right && count == 0)  return true;    //叶子结点且计数为0
    if(!cur->left && !cur->right)   return false;   //叶子结点且不符合计数结果
    if(cur->left){  //左节点存在
        count -= cur->left->val;
        if(traversal(cur->left, count))     return true;
        count += cur->left->val;    //回溯
    }
    if(cur->right){  //右节点存在
        count -= cur->right->val;
        if(traversal(cur->right, count))     return true;
        count += cur->right->val;    //回溯
    }   
    return false;
}
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root == NULL)    return false;
    return traversal(root, targetSum - root->val);
}