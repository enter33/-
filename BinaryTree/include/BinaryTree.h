#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <queue>
#include <stack>

template<typename T>
class BinaryTree
{
private:
    struct node
    {
        T data;
        node* left;
        node* right;
    };

    node* root;

    bool (*compare)(T t1,T t2);

    void (*output)(T);

    void PreOrder(node*);

    void InOrder(node*);

    void PostOrder(node*);

    void LevelOrder(std::queue<node*>);

    void LevelAdd(node*);

    bool isempty;

    std::queue<node*> leafnode;
    
public:
    BinaryTree(/* args */);
    BinaryTree(bool(*compare)(T,T));
    ~BinaryTree();

    bool IsEmpty();

    void Add(T elem);

    void setoutfunc(void(*output)(T));

    /*前序遍历*/
    void PreOrderTraversal();

    /*中序遍历*/        
    void InOrderTraversal();

    /*后序遍历*/    
    void PostOrderTraversal();

    /*层序遍历*/
    void LevelOrderTraversal();

    /*栈实现中序遍历,无需递归*/
    void InOrderTraversal_stack();

    /*栈实现前序遍历,无需递归*/
    void PreOrderTraversal_stack();

    /*栈实现后序遍历,无需递归*/
    void PostOrderTraversal_stack();
};

template<typename T>
BinaryTree<T>::BinaryTree(/* args */)
{
    this->root = (node*)malloc(sizeof(node));
    this->isempty = true;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{

}

template<typename T>
BinaryTree<T>::BinaryTree(bool(*Compare)(T,T))
{
    this->root = (node*)malloc(sizeof(node));
    this->root->left = NULL;
    this->root->right = NULL;
    this->compare = Compare;
    this->isempty = true;
}


template<typename T>
bool BinaryTree<T>::IsEmpty()
{
    if(this->isempty)
    {
        return true;
    }
    
    return false;
}

template<typename T>
void BinaryTree<T>::Add(T elem)
{
    node* Elem = (node*)malloc(sizeof(node));
    
    Elem->data = elem;
    Elem->left = NULL;
    Elem->right = NULL;
    
    if(this->IsEmpty())
    {
        // printf("ok\n");
        this->root->data = elem;
        free(Elem);
        this->isempty = false;
        this->leafnode.push(this->root);
        
        return;
    }

    if(compare != NULL)
    {
        node* temp = root;
        // printf("ok\n");
        while(1)
        {
            if(compare(elem,temp->data))
            {
                if(temp->right == NULL)
                {
                    temp->right = Elem;
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                if(temp->left == NULL)
                {
                    temp->left = Elem;
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
        }
    }

    else
    {
        LevelAdd(Elem);
    }
}


template<typename T>
void BinaryTree<T>::setoutfunc(void(*Output)(T))
{
    this->output = Output;
}


template<typename T>
void BinaryTree<T>::PreOrderTraversal()
{
    if(this->output == NULL)
    {
        return;
    }

    if(this->IsEmpty())
    {
        return;
    }

    node* temp = this->root;

    PreOrder(temp);
}

template<typename T>
void BinaryTree<T>::InOrderTraversal()
{
    if(this->output == NULL)
    {
        return;
    }

    if(this->IsEmpty())
    {
        return;
    }

    node* temp = this->root;

    InOrder(temp);
}

template<typename T>
void BinaryTree<T>::PostOrderTraversal()
{
    if(this->output == NULL)
    {
        return;
    }

    if(this->IsEmpty())
    {
        return;
    }

    node* temp = this->root;

    PostOrder(temp);
}

template<typename T>
void BinaryTree<T>::LevelOrderTraversal()
{
    if(this->output == NULL)
    {
        return;
    }

    if(this->IsEmpty())
    {
        return;
    }

    std::queue<node*> Q;
    Q.push(this->root);

    LevelOrder(Q);
}

template<typename T>
void BinaryTree<T>::PreOrder(node* elem)
{
    if(elem == NULL)
    {
        return;
    }
    this->output(elem->data);
    PreOrder(elem->left);
    PreOrder(elem->right);
}

template<typename T>
void BinaryTree<T>::InOrder(node* elem)
{
    if(elem == NULL)
    {
        return;
    }
    InOrder(elem->left);
    this->output(elem->data);
    InOrder(elem->right);
}

template<typename T>
void BinaryTree<T>::PostOrder(node* elem)
{
    if(elem == NULL)
    {
        return;
    }
    PostOrder(elem->left);
    
    PostOrder(elem->right);
    
    this->output(elem->data);
}


template<typename T>
void BinaryTree<T>::LevelOrder(std::queue<node*> Qelems)
{
    if(Qelems.empty())
    {
        return;
    }

    std::queue<node*> Q;

    while(!Qelems.empty())
    {
        node* elem = Qelems.front();
        Qelems.pop();
        this->output(elem->data);

        if(elem->left)
        {
            Q.push(elem->left);
        }

        if(elem->right)
        {
            Q.push(elem->right);
        }
    }

    LevelOrder(Q);

}


template<typename T>
void BinaryTree<T>::LevelAdd(node* Elem)
{
    node* elem = this->leafnode.front();

    if(elem->left == NULL)
    {
        elem->left = Elem;
        this->leafnode.push(elem->left);
        return;
    }
    else if(elem->right == NULL)
    {
        elem->right = Elem;
        this->leafnode.pop();
        this->leafnode.push(elem->right);
        return;
    }
}


template<typename T>
void BinaryTree<T>::InOrderTraversal_stack()
{
    if(this->isempty)
    {
        return;
    }

    std::stack<node*> S;

    node* temp = this->root;
    while(temp || !S.empty())
    {
        while(temp)
        {
            S.push(temp);
            temp = temp->left;
        }

        temp = S.top();
        S.pop();
        this->output(temp->data);
        temp = temp->right;
    }

}


template<typename T>
void BinaryTree<T>::PreOrderTraversal_stack()
{
    if(this->isempty)
    {
        return;
    }

    std::stack<node*> S;

    node* temp = this->root;
    while(temp || !S.empty())
    {
        while(temp)
        {
            this->output(temp->data);
            S.push(temp);
            temp = temp->left;
        }

        temp = S.top();
        S.pop();
        temp = temp->right;
    }

}


template<typename T>
void BinaryTree<T>::PostOrderTraversal_stack()
{
    if(this->isempty)
    {
        return;
    }

    std::stack<node*> S;

    node* temp = this->root;
    node* last;
    while(temp || !S.empty())
    {
        while(temp)
        {
            S.push(temp);
            temp = temp->left;
        }

        temp = S.top();
        
        if(temp->right && temp->right != last)
        {
            temp = temp->right;
        }
        else
        {
            this->output(temp->data);
            S.pop();
            last = temp;
            temp = NULL;
        }
        

        // sleep(1);
    }

}

#endif /*__BINARYTREE_H__*/