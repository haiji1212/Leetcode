#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 【450】删除二叉搜索树中的结点
// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
// 并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(root == NULL)    return NULL;
    if(root->val == key){
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }else if(root->left == NULL){
            struct TreeNode* newNode = root->right;
            free(root);
            return newNode;
        }else if(root->right == NULL){
            struct TreeNode* newNode = root->left;
            free(root);
            return newNode;
        }else{
            struct TreeNode* newNode = root->right;
            while(newNode->left != NULL){
                newNode = newNode->left;
            }
            newNode->left = root->left;
            struct TreeNode* temp = root;
            root = root->right;
            free(temp);
            return root;
        }
    }
    if(root->val > key){
        root->left = deleteNode(root->left, key);
    }else if(root->val < key){
        root->right = deleteNode(root->right, key);
    }
    return root;
}
