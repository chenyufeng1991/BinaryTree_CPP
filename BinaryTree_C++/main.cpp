//
//  main.c
//  BinaryTree
//
//  Created by chenyufeng on 16/3/10.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct BTNode{
    int data;
    struct BTNode *lChild;
    struct BTNode *rChild;
}BiTNode;

//先序创建二叉树
void CreateBiTree(BiTNode **T)
{
    int ch;
    cin >> ch;
    if (ch == -1)
    {
        *T = NULL;
        return;
    }
    else
    {
        *T = new BiTNode;
        if (T == NULL)
        {
            cout << "failed" << endl;
            return;
        }
        else
        {
            (*T)->data = ch;
            cout << "输入" << ch << "的左子节点:";
            CreateBiTree(&((*T)->lChild));
            cout << "输入" << ch << "的右子节点:";
            CreateBiTree((&(*T)->rChild));
        }
    }

    return;
}

//先序遍历二叉树
void PreOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        cout << T->data << " ";
        PreOrderBiTree(T->lChild);
        PreOrderBiTree(T->rChild);
    }
}

//中序遍历二叉树
void MiddleOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        MiddleOrderBiTree(T->lChild);
        cout << T->data << " ";
        MiddleOrderBiTree(T->rChild);
    }
}

//后续遍历二叉树
void PostOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        PostOrderBiTree(T->lChild);
        PostOrderBiTree(T->rChild);
        cout << T->data << " ";
    }
}

//二叉树的深度
int TreeDeep(BiTNode *T)
{
    int deep = 0;
    if (T != NULL)
    {
        int leftdeep = TreeDeep(T->lChild);
        int rightdeep = TreeDeep(T->rChild);
        deep = leftdeep >= rightdeep?leftdeep+1:rightdeep+1;
    }

    return deep;
}

//叶子节点个数
int LeafCount(BiTNode *T)
{
    static int count;
    if (T != NULL)
    {
        if (T->lChild == NULL && T->rChild == NULL)
        {
            count++;
        }

        LeafCount(T->lChild);
        LeafCount(T->rChild);
    }

    return count;
}

//主函数
int main(int argc,const char *argv[])
{
    BiTNode *T;
    int depth,leafCount = 0;
    cout << "请输入第一个节点的值，-1表示没有叶节点：" << endl;
    CreateBiTree(&T);

    cout << "先序遍历二叉树：";
    PreOrderBiTree(T);
    cout << endl;

    cout << "中序遍历二叉树：";
    MiddleOrderBiTree(T);
    cout << endl;

    cout << "后续遍历二叉树：" ;
    PostOrderBiTree(T);
    cout << endl;

    depth = TreeDeep(T);
    cout << "树的深度为：" << depth << endl;

    leafCount = LeafCount(T);
    cout << "叶子节点个数:" << leafCount << endl;
    
    return 0;
}
