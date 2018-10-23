//
// Created by 李春霖 on 2018/10/21.
//

#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

#define HEIGHT(p)    ( (p==NULL) ? 0 : (((Node *)(p))->height) )
#define MAX(a,b)    ((a) > (b) ? (a):(b))


// 创建节点 本文件可见
static Node* avltree_create_node(Type key, Node* left, Node* right)
{
    Node* p;
    if((p = (Node*)malloc(sizeof(Node))) == NULL)
        return NULL;

    p->key  = key;
    p->left = left;
    p->right = right;
    p->height = 0;
    return p;
}

// 获取树高度
int avltree_height(AVLTree tree)
{
    return HEIGHT(tree);
}


// LL 旋转 左单旋转
static Node* left_left_rotation(AVLTree tree){
    Node* root = tree->left;
    tree->left = root->right;
    root->right = tree;

    root->height = MAX(HEIGHT(root->left), HEIGHT(root->right)) + 1;
    tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;
    return root;
}

// RR 右单旋转
static Node* right_right_rotation(AVLTree tree)
{
    Node* root = tree->right;
    tree->right = root->left;
    root->left = tree;


    root->height = MAX(HEIGHT(root->left), HEIGHT(root->right)) + 1;
    tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;
    return root;
}

// LR:  需要两次旋转，先RR旋转左子树， 在LL旋转根
static Node* left_right_rotation(AVLTree tree)
{
    tree->left = right_right_rotation(tree->left);
    return left_left_rotation(tree);
}

// RL:  需要两次旋转,先LL旋转右子树， 再RR旋转根
static Node* right_left_rotation(AVLTree tree)
{
    tree->right = left_left_rotation(tree->right);
    return right_right_rotation(tree);
}

// 插入节点
// 返回值 根节点
Node* avltree_insert(AVLTree tree, Type key)
{
    if(tree == NULL)
    {
        tree = avltree_create_node(key,NULL,NULL);
        if(tree == NULL)
        {
            printf("ERROR: create avltree node failed!\n");
            return NULL;
        }
    } else if(key < tree->key)
    {
        tree->left = avltree_insert(tree->left, key);
        if(HEIGHT(tree->left) - HEIGHT(tree->right) == 2)
        {
            if(key < tree->left->key)
                tree = left_left_rotation(tree);
            else
                tree = left_right_rotation(tree);
        }
    } else if(key > tree->key)
    {
        tree->right = avltree_insert(tree->right, key);
        if(HEIGHT(tree->right) - HEIGHT(tree->left) == 2)
        {
            if(key < tree->right->key)
                tree = right_left_rotation(tree);
            else
                tree = right_right_rotation(tree);
        }
    }   else //(key == tree->key)
    {
        printf("添加失败：不允许添加相同的节点！\n");
    }
    tree->height = MAX( HEIGHT(tree->left), HEIGHT(tree->right)) + 1;
    return tree;
}

//







