#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//【105】从前序与中序遍历序列构造二叉树
// 给定两个整数数组 preorder 和 inorder ，
// 其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize == 0 || inorderSize == 0)   return NULL;
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = preorder[0];    //根结点必定是前序遍历第一个结点
    int leftsize;
    for(leftsize = 0;leftsize < inorderSize;leftsize++){
        if(inorder[leftsize] == preorder[0])
            break;
    }
    int rightsize = inorderSize - leftsize - 1;
    newNode->left = buildTree(preorder + 1, leftsize, inorder, leftsize);
    newNode->right = buildTree(preorder + 1 + leftsize, rightsize, inorder + leftsize + 1, rightsize);
    return newNode;
}

