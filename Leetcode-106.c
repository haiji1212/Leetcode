#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//【106】从中序与后序遍历序列构造二叉树
// 给定两个整数数组 inorder 和 postorder ，
// 其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int linearSearch(int* arr, int arrSize, int key) {
    int i;
    for(i = 0; i < arrSize; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(inorderSize == 0 || postorderSize == 0)  return NULL;
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = postorder[postorderSize - 1];    //根结点必定是后序遍历最后一个结点
    int leftsize = linearSearch(inorder , inorderSize, postorder[postorderSize - 1]);  //定位根结点在中序遍历中的位置
    int rightsize = inorderSize - leftsize - 1;
    newNode->left = buildTree(inorder, leftsize, postorder, leftsize);
    newNode->right = buildTree(inorder + leftsize + 1, rightsize, postorder + leftsize, rightsize);
    return newNode;
}