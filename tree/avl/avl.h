//
// Created by 李春霖 on 2018/10/21.
//

#ifndef ALGORITHM_AVL_H
#define ALGORITHM_AVL_H

typedef int Type;

typedef struct ALVTreeNode{
    Type  key;
    int height;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
} Node, *AVLTree;

// 找最小节点
static Node* avltree_minimum(AVLTree tree);

// 找最大节点
static Node* avltree_maximum(AVLTree tree);

//  创建树节点
static Node* avltree_create_node(Type key, Node* left, Node* right);

// 搜索节点
Node* avltree_search(AVLTree tree, Type key)

// 获取树高度
int avltree_height(AVLTree tree);

// LL 左单旋转
static Node* left_left_rotation(AVLTree tree);

// RR 右单旋转
static Node* right_right_rotation(AVLTree tree);

// LR:  需要两次旋转，先RR旋转左子树， 再LL旋转根
static Node* left_right_rotation(AVLTree tree);

// RL:  需要两次旋转,先LL旋转右子树， 再RR旋转根
static Node* right_left_rotation(AVLTree tree);

// 插入节点
Node* avltree_insert(AVLTree tree, Type key);


#endif //ALGORITHM_AVL_H
