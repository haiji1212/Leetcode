#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 【501】二叉搜索树中的众数
// 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
// 如果树中有不止一个众数，可以按 任意顺序 返回。
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int base, count, maxCount;
int *answer, answerSize;

void update(int x)
{
    if (x == base)
    {
        ++count;
    }
    else
    {
        count = 1;
        base = x;
    }
    if (count == maxCount)
    {
        answer[answerSize++] = base;
    }
    if (count > maxCount)
    {
        maxCount = count;
        answerSize = 0;
        answer[answerSize++] = base;
    }
}

int *findMode(struct TreeNode *root, int *returnSize)
{
    struct TreeNode *cur = root, *pre = NULL;
    answer = malloc(sizeof(int) * 5001);
    answerSize = count = maxCount = 0;
    while (cur)
    {
        if (!cur->left)
        {
            update(cur->val);
            cur = cur->right;
            continue;
        }
        pre = cur->left;
        while (pre->right && pre->right != cur)
        {
            pre = pre->right;
        }
        if (!pre->right)
        {
            pre->right = cur;
            cur = cur->left;
        }
        else
        {
            pre->right = NULL;
            update(cur->val);
            cur = cur->right;
        }
    }
    *returnSize = answerSize;
    return answer;
}
