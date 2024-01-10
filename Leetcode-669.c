#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 【669】修剪二叉搜索树
// 给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。
// 通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
// 修剪树 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 唯一的答案 。
// 所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    if(root == NULL)    return NULL;
    if(root->val < low){
        struct TreeNode* right = trimBST(root->right, low, high);
        return right;
    }
    if(root->val > high){
        struct TreeNode* left = trimBST(root->left, low, high);
        return left;
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}
