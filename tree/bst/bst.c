//
// Created by 李春霖 on 2018/10/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "bst.h"


//  创建节点
static Node* create_bstree_node(Type key, Node* parent, Node* left, Node* right)
{
   Node* p;

   if((p = (Node*)malloc(sizeof(Node))) == NULL)
       return NULL;
   p->key  = key;
   p->parent = parent;
   p->left = left;
   p->right = right;
   return p;
}

// 前序递归遍历
void preorder_bstree(BSTree tree)
{
   if(tree != NULL)
   {
      printf("%d ", tree->key);
      preorder_bstree(tree->left);
      preorder_bstree(tree->right);
   }
}

// 中序递归遍历
void inorder_bstree(BSTree tree)
{
   if(tree != NULL)
   {
      inorder_bstree(tree->left);
      printf("%d ", tree->key);
      inorder_bstree(tree->right);
   }
}

// 后序递归遍历
void postorder_bstree(BSTree tree)
{
   if(tree != NULL)
   {
      postorder_bstree(tree->left);
      printf("%d ", tree->key);
      postorder_bstree(tree->right);
   }
}

// 查找 递归版
Node* bstree_search(BSTree tree, Type key)
{
   if(tree == NULL || tree->key == key)
      return tree;
   if(key < tree->key)
      return bstree_search(tree->left, key);
   else
      return bstree_search(tree->right, key);
}

// 查找 迭代版
Node* iterative_bstree_search(BSTree tree, key)
{
   while((tree != NULL) &&  (tree->key != key))
   {
      if(key < tree->key)
         tree = tree->left;
      else
         tree = tree->right;
   }
   return tree;
}

// 最大值
Node* bstree_maximum(BSTree tree)
{
   while(tree && tree->right)
      tree = tree->right;
   return tree;
}

// 最小值
Node* bstree_minimum(BSTree tree)
{
   while(tree && tree->left)
      tree = tree->left;
   return tree;
}

//  前驱节点: 中序遍历的前一个
Node* bstree_predecessor(Node *node)
{
    // 如果node存在左孩子，则"node的前驱结点"为 "以其左孩子为根的子树的最大结点"。
    if(node->left)
        return bstree_maximum(node->left);

    // 1) node是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
    // 2) node是"一个左孩子"，则查找"node的最低的祖父结点，并且node位于该祖父结点的右子树"，找到的这个"最低的祖父结点"就是"node的前驱结点"。
    Node* parent = node->parent;
    //while 既当作if(node左孩子)，又能循环找到第一个node在右边子树的祖父节点
    while(parent && node == parent->left)
    {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

//   后继节点: 中序遍历的后一个
Node* bstree_successor(Node *node)
{
    // 如果x存在左孩子，则"node的后继结点"为 "以右孩子为根的子树的最小结点"。
    if(node->right)
        return bstree_minimum(node->right);

    // 1) node是"一个左孩子"，则"x的前驱结点"为 "它的父结点"。
    // 2) node是"一个右孩子"，则查找"node的最低的祖父结点，并且node位于该祖父结点的左子树"，找到的这个"最低的祖父结点"就是"node的前驱结点"。

    Node* parent = node->parent;

    //while 既当作if(node右孩子)，又能循环找到第一个node在左边子树的祖父节点
    while(parent && node == parent->right)
    {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

//     内部插入 helper
static BSTree bstree_insert(BSTree tree, Node *node)
{
    Node* pos = NULL;
    Node* p = tree;
    while(p){
        // 此版本为可插入重复值
        pos = p;
        if(node->key < p->key)
            p = p->left;
        else
            p = p->right;
        // 此版本为不可重复值
//        if(node->key < tree->key)
//            tree = tree->left;
//        else if(node->key > tree->key)
//            tree = tree->right;
//        else
//        {
//            free(node);
//            return tree;
//        }
    }
    printf("here:%d\n",pos);
    node->parent = pos;
    if (pos == NULL)
        tree = node;
    else if (node->key < pos->key)
        pos->left = node;
    else
        pos->right = node;

    return tree;
}

//     外部插入节点
BSTree insert_bstree(BSTree tree, Type key)
{
    Node* p;
    if((p = create_bstree_node(key, NULL, NULL, NULL)) == NULL)
        return tree;

    return bstree_insert(tree, p);
}

//      内部删除节点
static BSTree bstree_delete(BSTree tree, Node *node)
{
    // 如果node左右子树为空
    if(!node->left && !node->right)
    {
        if(node->parent)
        {
            if(node->parent->left == node)
                node->parent->left = NULL;
            else
                node->parent->right = NULL;
        } else
        {
            free(node);
            return NULL;
        }

        free(node);
        return tree;
    }

    // 如果node左右子树有一个不为空
    if((node->left && !node->right) || (!node->left && node->right))
    {
       Node* next = node->left? node->left: node->right;
       if(node->parent)
       {
           if(node->parent->left == node)
               node->parent->left = next;
           else
               node->parent->right = next;
           next->parent = node->parent;
       } else
       {
           next->parent = NULL;
           free(node);
           return next;
       }
       free(node);
       return tree;
    }

    // 左右子树都不为空
    Node* next = bstree_successor(node);
    if(next->parent != node)
    {
        next->parent->left = next->right;
        next->left = node->left;
        next->right = node->right;
        // node不为根节点
        if(node->parent)
        {
            if(node == node->parent->left)
                node->parent->left = next;
            else
                node->parent->right = next;
            next->parent = node->parent;
            free(node);
            return tree;
        } else
        {
            next->parent = NULL;
            free(node);
            return next;
        }
    } else
    {
        next->left = node->left;
        if(node->parent)
        {
            if(node == node->parent->left)
                node->parent->left = next;
            else
                node->parent->right = next;
            next->parent = node->parent;
            free(node);
            return tree;
        } else
        {
            next->parent = NULL;
            free(node);
            return next;
        }
    }
}

// 外部删除
BSTree delete_bstree(BSTree tree, Type key)
{
    Node *z, *node;

    if ((z = bstree_search(tree, key)) != NULL)
        tree = bstree_delete(tree, z);
    return tree;
}


// 打印二叉树
void print_bstree(BSTree tree, Type key, int direction)
{
    if(tree != NULL)
    {
        if(direction==0)    // tree是根节点
            printf("%2d is root\n", tree->key);
        else                // tree是分支节点
            printf("%2d is %2d's %6s child\n", tree->key, key, direction==1?"right" : "left");

        print_bstree(tree->left, tree->key, -1);
        print_bstree(tree->right,tree->key,  1);
    }
}

// 销毁二叉树
void destroy_bstree(BSTree tree)
{
    if(tree == NULL)
        return;
    if(tree->left != NULL)
        destroy_bstree(tree->left);
    if(tree->right != NULL)
        destroy_bstree(tree->right);
    free(tree);
}








