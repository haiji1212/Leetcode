#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 【538】把二叉搜索树转换为累加树
// 给出二叉 搜索 树的根节点，该树的节点值各不相同，
// 请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode * root, int * sum)//更新每一个节点值
{
    if(root != NULL)//递归结束条件，遍历到叶子结点
    {
        dfs(root->right, sum);//先更新右节点
        root->val += *sum;//再更新自己
        *sum = root->val;//保存一下最新累加值
        dfs(root->left, sum);//再更新左节点
    }
    return;
}

struct TreeNode* convertBST(struct TreeNode* root){
    int sum = 0;
    dfs(root, &sum);//dfs搜索整个树节点
    return root;
}
