#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>


#define MAX(a,b) a>b?a:b

class Heap
{
private:
    struct node
    {
        int data;
        node* left;
        node* right;
    };

    node* root;
    bool isempty;

    /*层序遍历找到应该插入的位置*/
    void change2heap(node*,std::stack<node*>&);
    
public:
    Heap(/* args */);
    ~Heap();
    void Add(int);
    void LevelTrav();
    int Delete();
};

Heap::Heap(/* args */)
{
    this->isempty = true;
    this->root = (node*)malloc(sizeof(node));
    this->root->left = NULL;
    this->root->right = NULL;
}

Heap::~Heap()
{
}

/*利用队列实现完全二叉树,使用栈对树进行调整,成最大堆*/

/*调整成堆的思路\
    首先层序遍历获得元素插入栈中(这样可以逆序调整)\
    对于获得的栈,分析其中元素和字节点的大小并进行调整,并将新调整的元素入栈
*/

void Heap::Add(int elem)
{
    if(this->isempty)
    {
        this->root->data = elem;
        this->isempty = false;
        return;
    }

    node* temp = (node*)malloc(sizeof(node));
    temp->data = elem;
    temp->left = NULL;
    temp->right = NULL;

    std::queue<node*> Q;
    std::stack<node*> S;
    Q.push(this->root);

    while(!Q.empty())
    {
        node* N = Q.front();
        S.push(N);/*元素入栈*/

        if(!N->left)
        {
            N->left = temp;
            break;
        }
        else
        {
            Q.push(N->left);
        }

        if(!N->right)
        {
            N->right = temp;
            break;
        }
        else
        {
            Q.push(N->right);
            Q.pop();
        }
    }


    /*调整完全二叉树为最大堆*/
    while(!S.empty())
    {
        node* N = S.top();
        S.pop();

        change2heap(N,S);
    }
}

void Heap::change2heap(node* N,std::stack<node*> &S)
{
    if(N->left)
    {
        if(N->right)
        {
            if(N->left->data > N->right->data)
            {
                if(N->data < N->left->data)
                {
                    int temp = N->data;
                    N->data = N->left->data;
                    N->left->data = temp;
                    S.push(N->left);
                }
            }
            else
            {
                if(N->data < N->right->data)
                {
                    int temp = N->data;
                    N->data = N->right->data;
                    N->right->data = temp;
                    S.push(N->right);
                }
            }
        }
        else
        {
            if(N->data < N->left->data)
            {
                int temp = N->data;
                N->data = N->left->data;
                N->left->data = temp;
                S.push(N->left);
            }
        }
    }

}

void Heap::LevelTrav()
{
    if(this->isempty)
    {
        return;
    }

    std::queue<node*> Q;
    Q.push(this->root);
    while(!Q.empty())
    {
        node* temp = Q.front();
        Q.pop();

        printf("%d\n",temp->data);

        if(temp->left != NULL)
        {
            Q.push(temp->left);
        }

        if(temp->right != NULL)
        {
            Q.push(temp->right);
        }
    }

}

int Heap::Delete()
{
    if(this->isempty)
    {
        return -1;
    }

    int ans = this->root->data;

    std::queue<node*> Q;
    std::stack<node*> S;
    Q.push(this->root);

    node* temp;

    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        if(temp->left || temp->right)
        {
            S.push(temp);
        }

        if(temp->left)
        {
            Q.push(temp->left);
        }

        if(temp->right)
        {
            Q.push(temp->right);
        }
    }

    this->root->data = temp->data;


    /*调整完全二叉树为最大堆*/
    node* N = S.top();
    if(N->right)
    {
        N->right = NULL;
    }
    else
    {
        N->left = NULL;
    }

    free(temp);


    while(!S.empty())
    {
        N = S.top();
        S.pop();

        change2heap(N,S);
    }

    return ans;

}

#endif /*__HEAP_H__*/