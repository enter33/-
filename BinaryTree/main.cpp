#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./include/BinaryTree.h"

bool compare(int,int);
void out(int data);

int main(int argc,char* argv[])
{
    BinaryTree<int>* tree = new BinaryTree<int>();

    // printf("1\n");

    tree->Add(1);
    tree->Add(3);
    tree->Add(10);
    tree->Add(3);
    tree->Add(4);
    tree->Add(6);
    tree->Add(5);
 

    tree->setoutfunc(out);

    // tree->PreOrderTraversal();

    // tree->InOrderTraversal();

    // tree->PostOrderTraversal();

    // tree->LevelOrderTraversal();

    // tree->InOrderTraversal_stack();

    // tree->PreOrderTraversal_stack();

    // tree->PostOrderTraversal_stack();

    printf("%d\n",tree->getHeight());
}


bool compare(int a,int b)
{
    if(a > b)
    {
        return true;
    }

    return false;
}

void out(int data)
{
    printf("%d\n",data);
}