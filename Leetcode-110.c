#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//【110】平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树。
// 本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int height(struct TreeNode* root){
    if(root == NULL)    return 0;
    int leftheight = height(root->left);
    if(leftheight == -1)    return -1;
    int rightheight = height(root->right);
    if(rightheight == -1)   return -1;
    int max = leftheight > rightheight ? leftheight : rightheight;
    return abs(leftheight - rightheight) > 1 ? -1 : 1 + max;
}

bool isBalanced(struct TreeNode* root) {
    return height(root) == -1 ? false : true;
}
