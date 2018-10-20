//
// Created by 李春霖 on 2018/10/20.
//

#ifndef ALGORITHM_BST_H
#define ALGORITHM_BST_H

typedef int Type;

typedef struct BSTreeNode{
    Type key;                   //  值
    struct BSTreeNode* left;    //  左孩子
    struct BSTreeNode* right;   //  右孩子
    struct BSTreeNode* parent;  //  父亲节点
} Node, *BSTree;

// 创建节点函数，本文件可见
static Node* create_bstree_node(TYpe key, Node* parent, Node* left, Node* right);

// 前序递归遍历
void preorder_bstree(BSTree tree);

// 中序递归遍历
void inorder_bstree(BSTree tree);

// 后序递归遍历
void postorder_bstree(BSTree tree);

// 查找 递归版
Node* bstree_search(BSTree tree, Type key);

// 查找 迭代版
Node* iterative_bstree_search(BSTree tree, key);

// 查找 最大值
Node* bstree_maximum(BSTree tree);

// 查找 最小值
Node* bstree_minimum(BSTree tree);

#endif //ALGORITHM_BST_H
