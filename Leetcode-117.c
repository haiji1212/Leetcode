#include<stdio.h>
#include<stdlib.h>

//【116】填充每个节点的下一个右侧节点指针 II
// 给定一个二叉树：
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
// 初始状态下，所有 next 指针都被设置为 NULL 。

// struct Node *find_next(struct Node *root) {
//     while (root) {
//         if (root->left)
//             return root->left;
//         if (root->right)
//             return root->right;
//         root = root->next;
//     }
//     return NULL;
// }
// struct Node* connect(struct Node* root) {
//     if (!root)
//         return NULL;
//     if (root->right)
//         root->right->next = find_next(root->next);
//     if (root->left)
//         root->left->next = root->right ? root->right : find_next(root->next);
      
//     connect(root->right);
//     connect(root->left);
//     return root;
// }
