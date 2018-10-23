//
// Created by 李春霖 on 2018/10/20.
//

#ifndef ALGORITHM_BST_CPP_H
#define ALGORITHM_BST_CPP_H
#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class BSTNode{
public:
    T key;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
    BSTNode(T v, BSTNode* l, BSTNode* r, BSTNode* p):
        key(v),left(l), right(r), parent(p){}
};

template<class T>
class BSTree{
private:
    BSTNode<T>* root;          //  根节点

public:
    BSTree();
    ~BSTree();

    // 前序遍历
    void preOrder() const ;

    // 中序遍历
    void inOrder() const ;

    // 后序遍历
    void postOrder() const;

    // 递归实现搜索
    BSTNode<T>* search(T key) const;

    // 非递归实现搜索
    BSTNode<T>* iterativeSearch(T key) const;

    // 最小值
    T minimum() const ;

    // 最大值
    T maximum() const;

    // 查找后继节点
    BSTNode<T>* successor(BSTNode<T>* node)const;

    // 查找前驱节点
    BSTNode<T>* predecessor(BSTNode<T>* node)const;

    // 插入节点值
    void insert(T key);

    // 删除节点
    void remove(T key);

    // 销毁二叉树
    void destroy();

    //  打印二叉树
    void print() const;

private:
    // 前序遍历 二叉树
    void preOrder(BSTNode<T>* tree) const;

    // 中序遍历 二叉树
    void inOrder(BSTNode<T>* tree) const;

    // 后序遍历 二叉树
    void postOrder(BSTNode<T>* tree) const;

    // 递归实现任意节点为根的二叉树查找
    BSTNode<T>* search(BSTNode<T>* x, T key) const;

    // 非递归实现任意节点为根的二叉树查找
    BSTNode<T>* iterativeSearch(BSTree<T>* tree, T key) const;

    // 查找最小结点：返回tree为根结点的二叉树的最小结点。
    BSTNode<T>* minimum(BSTNode<T>* tree) const;

    // 查找最大结点：返回tree为根结点的二叉树的最大结点。
    BSTNode<T>* maximum(BSTNode<T>* tree) const;

    //  插入"二叉树"节点
    void insert(BSTNode<T>* &tree, BSTNode<T>* z);

    // 删除二叉树(tree)中的结点(z)，并返回被删除的结点
    BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T> *z);

    // 销毁二叉树
    void destroy(BSTNode<T>* &tree);

    // 打印二叉树
    void print(BSTNode<T>* tree, T key, int direction) const;

};

template<class T>
BSTree<T>::BSTree():root(nullptr){};

template <class T>
BSTree<T>::~BSTree()
{
     destroy();
}

// 前序遍历  内部接口
template<class T>
void BSTree<T>::preOrder(BSTNode<T> *tree) const
{
    if(tree != nullptr)
    {
        cout << tree->key << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

// 中序遍历 内部接口
template<class T>
void BSTree<T>::inOrder(BSTNode<T> *tree) const
{
    if(tree != nullptr)
    {
        inOrder(tree->left);
        cout << tree->key << " ";
        inOrder(tree->right);
    }
}

// 后序遍历 内部接口
template<class T>
void BSTree<T>::postOrder(BSTNode<T> *tree) const
{
    if(tree != nullptr)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->key << " ";
    }
}

//  前序遍历 外部接口
template <class T>
void BSTree<T>::preOrder() const {
    preOrder(root);
}

// 中序遍历 外部接口
template<class T>
void BSTree<T>::inOrder() const
{
    inOrder(root);
}

// 后序遍历 外部接口
template<class T>
void BSTree<T>::postOrder() const
{
    postOrder(root);
}

// 递归实现 搜索 内部接口
template<class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T> *node, T key) const
{
    if(node == NULL || node->key == key)
        return node;
    if(key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

// 递归实现 搜索 外部接口
template<class T>
BSTNode<T>* BSTree<T>::search(T key) const
{
    return search(root, key);
}

// 非递归实现 搜索 内部接口
template<class T>
BSTNode<T>* BSTree<T>::iterativeSearch(BSTree<T> *tree, T key) const
{
    while(tree && tree->key != key )
    {
        if(key < tree->key)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}

// 非递归实现 搜索 对外接口
template<class T>
BSTNode<T>* BSTree<T>::iterativeSearch(T key) const
{
    return iterativeSearch(root, key);
}

// 查找最小值 内部接口
template<class T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T> *tree) const
{
    while(tree->left)
        tree = tree->left;

    return tree;
}

// 查找最小值 外部接口
template<class T>
T BSTree<T>::minimum() const
{
    BSTNode<T>* p = minimum(root);
    if(p != nullptr)
        return p->key;
    return (T)NULL;
}

// 查找最大值 内部接口
template <class T>
BSTNode<T>* BSTree<T>::maximum(BSTNode<T> *tree) const
{
    while (tree->right)
        tree = tree->right;

    return tree;
}

// 查找最大值 外部接口
template<class T>
T BSTree<T>::maximum() const
{
    BSTNode<T>* p = maximum(root);
    if(p != nullptr)
        return p->key;
    return (T)NULL;
}

// 前驱节点
template <class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *node)const
{
    // 如果有左子树
    if(node->left)
        return maximum(node->left);

    // 1） 如果node是右孩子， 前驱节点就是它的父节点
    // 2） 如果node是左孩子， 前驱节点就是它的最低一个祖父节点，并且node在这个祖父节点的右子树

    BSTNode<T> parent = node->parent;
    while(parent && node == parent->left)
    {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

// 后继节点
template <class T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T> *node) const
{
    // 如果有右子树
    if(node->right)
        return minimum(node->right);

    // 1) 如果node是左孩子， 后继节点就是它的父节点
    // 2）如果node是右孩子， 后继节点就是它的最低祖父节点，并且node在这个祖父节点的左子树

    BSTNode<T>* parent = node->parent;
    while(parent && node == parent->right)
    {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

//  插入 二叉树 节点 内部接口
template<class T>
void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T> *node)
{
    BSTNode<T>* pre = nullptr;
    BSTNode<T>* cur = tree;
    while(cur && (node->key != cur->key))
    {
        pre = cur;
        if(node->key < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
    }

    node->parent = pre;
    if(pre == nullptr)
        tree = node;
    else if(node->key < pre->key)
        pre->left = node;
    else
        pre->right = node;
}

// 插入 二叉树 节点值 外部接口
template<class T>
void BSTree<T>::insert(T key)
{
    BSTNode<T> *p = nullptr;

    if((p = new BSTNode<T>(key, nullptr, nullptr, nullptr)) == nullptr)
        return;
    insert(root, p);
}

// 删除节点 内部接口
template<class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T>* &tree, BSTNode<T> *node)
{
    BSTNode<T> *x= nullptr;     // 待删除的节点子节点
    BSTNode<T> *y= nullptr;     // 待删除的节点

    if ((node->left == nullptr) || (node->right == nullptr) )
        y = node;
    else
        y = successor(node);

    //  保存待删除节点的子节点
    if (y->left != nullptr)
        x = y->left;
    else
        x = y->right;

    if (x != nullptr)
        x->parent = y->parent;

    if (y->parent == nullptr)
        tree = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    //  y 是后继节点
    if (y != node)
        node->key = y->key;

    return y;
}

// 删除节点 外部接口
template<class T>
void BSTree<T>::remove(T key){
    BSTNode<T> *z, *node;
    if((z = search(root, key)) != nullptr){
        if((node = remove(root, z)) != nullptr)
            delete node;
    }
    return;
}


/*
 * 打印"二叉查找树"
 *
 * key        -- 节点的键值
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
template<class T>
void BSTree<T>::print(BSTNode<T> *tree, T key, int direction) const{
    if(tree != nullptr){
        if(direction==0)    // tree是根节点
            cout << setw(2) << tree->key << " is root" << endl;
        else
            cout << setw(2) << tree->key << " is " << setw(2) << key << "'s "  << setw(12) << (direction==1?"right child" : "left child") << endl;
        print(tree->left, tree->key, -1);
        print(tree->right, tree->key, 1);
    }
}

// 打印二叉树 对外
template <class T>
void BSTree<T>::print()const
{
    if(root != nullptr)
        print(root, root->key, 0);
}

//  销毁二叉树  对内接口
template<class T>
void BSTree<T>::destroy(BSTNode<T>* &tree)
{
    if(tree == nullptr)
        return;

    if(tree->left != nullptr)
        destroy(tree->left);
    if(tree->right != nullptr)
        destroy(tree->right);
    delete  tree;
    tree = nullptr;
}

//  销毁二叉树 对外接口
template<class T>
void BSTree<T>::destroy(){
    destroy(root);
}















#endif //ALGORITHM_BST_CPP_H
