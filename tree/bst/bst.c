//
// Created by 李春霖 on 2018/10/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "bst.h"


//  创建节点
static Node* create_bstree_node(TYpe key, Node* parent, Node* left, Node* right)
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
      postorder_bstree(tree->right)
   }
}

// 查找 递归版
Node* bstree_search(BSTree tree, Type key)
{
   if(tree == NULL || tree->key = key)
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





