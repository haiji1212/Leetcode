#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//【654】最大二叉树
// 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
// 创建一个根节点，其值为 nums 中的最大值。
// 递归地在最大值 左边 的 子数组前缀上 构建左子树。
// 递归地在最大值 右边 的 子数组后缀上 构建右子树。
// 返回 nums 构建的 最大二叉树 。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* travelsal(int* nums, int left, int right){
    if(left >= right)    return NULL;
    int max = left;
    for(int i = left + 1; i < right; i ++){
        if(nums[i] > nums[max])
            max = i;
    }
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = nums[max];
    newNode->left = travelsal(nums, left, max);
    newNode->right = travelsal(nums, max + 1, right);
    return newNode;
}
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if(nums == NULL)    return NULL;
    return travelsal(nums, 0, numsSize);
}

