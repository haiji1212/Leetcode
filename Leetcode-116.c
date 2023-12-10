#include<stdio.h>
#include<stdlib.h>

//【116】填充每个节点的下一个右侧节点指针
// 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// };
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
// 初始状态下，所有 next 指针都被设置为 NULL。

// void connectTwoNode (struct Node* a, struct Node* b){
//     if (a == NULL || b == NULL) return;
//     a->next = b;
//     connectTwoNode(a->left,a->right);  //连接a子树的左右结点
//     connectTwoNode(b->left,b->right);  //连接b子树的左右结点
//     connectTwoNode(a->right,b->left);  //连接相邻子树的相邻结点
// }
// struct Node* connect(struct Node* root) {
//     if (root == NULL) return NULL;
//     connectTwoNode(root->left,root->right);
//     return root;
// }