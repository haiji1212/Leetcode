#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 【530】二叉搜索树的最小绝对差
//  给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
//  差值是一个正数，其数值等于两值之差的绝对值。
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void InOrder(struct TreeNode *root, int *last_value, int *min)
{
    int diff;
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left, last_value, min);
    diff = abs((*last_value) - root->val);
    *min = diff < *min ? diff : *min;
    *last_value = root->val;
    InOrder(root->right, last_value, min);
}

int getMinimumDifference(struct TreeNode *root)
{
    int last_value = INT_MAX;
    int min = INT_MAX;
    InOrder(root, &last_value, &min);
    return min;
}
