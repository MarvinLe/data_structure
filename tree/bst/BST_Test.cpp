//
// Created by 李春霖 on 2018/10/21.
//

#include <iostream>
#include "bst_cpp.h"
using namespace std;

static int arr[]= {1,5,4,3,2,6};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i, ilen;
    BSTree<int>* tree=new BSTree<int>();

    cout << "== 依次添加: " << endl;
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        cout << arr[i] <<" ";
        tree->insert(arr[i]);
    }

    cout << "\n== 前序遍历: ";
    tree->preOrder();

    cout << "\n== 中序遍历: ";
    tree->inOrder();

    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;

    cout << "== 最小值: " << tree->minimum() << endl;
    cout << "== 最大值: " << tree->maximum() << endl;
    cout << "== 树的详细信息: " << endl;
    tree->print();
    BSTNode<int> *p = tree->search(arr[3]);
    int a = -1;
    if(p)
        a = p->key;
    cout << "== 搜索" << arr[3] << "=" << a << endl;
    cout << "\n== 删除根节点: " << arr[3];
    tree->remove(arr[3]);
    a = -1;
    p = tree->search(arr[3]);
    if(p)
        a = p->key;
    cout << "== 搜索" << arr[3] << "=" << a << endl;
    cout << "\n== 中序遍历: ";
    tree->inOrder();
    cout << endl;

    // 销毁二叉树
    tree->destroy();

    return 0;
}

