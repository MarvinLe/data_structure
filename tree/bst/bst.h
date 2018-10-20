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
static Node* create_bstree_node(Type key, Node* parent, Node* left, Node* right);

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

// 查找 前驱节点;;    前驱节点:左子树中最大的节点
Node* bstree_predecessor(Node *node);

// 查找 后继节点;;    后继节点:右子树中最小的节点
Node* bstree_successor(Node *node);

// 内部插入 helper
static BSTree bstree_insert(BSTree tree, Node *z);

// 外部插入节点
BSTree insert_bstree(BSTree tree, Type key);

//  内部删除 helper
static BSTree bstree_delete(BSTree tree, Node *z);

// 外部删除
BSTree delete_bstree(BSTree tree, Type key);

// 打印二叉树
void print_bstree(BSTree tree, Type key, int direction);

// 销毁
void destroy_bstree(BSTree tree);


#endif //ALGORITHM_BST_H
