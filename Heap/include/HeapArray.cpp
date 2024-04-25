/*数组实现最大堆*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <stack>
#include "HeapArray.h"


HeapArray* createheap(int cap)
{
    HeapArray* h = (HeapArray*)malloc(sizeof(HeapArray));
    h->capasize = cap;
    h->size = 0;
    h->data = (int*)malloc(sizeof(int)*cap+1);
    h->data[0] = MAXELEM;
    return h;
}


void Add(HeapArray* h,int elem)
{
    if(h->size == h->capasize)
    {
        return;
    }

    h->data[++h->size] = elem;

    std::stack<int> S;
    S.push(h->size);
    while(!S.empty())
    {
        int idx = S.top();
        S.pop();
        if(h->data[idx/2] < elem)
        {
            int tmp = h->data[idx/2];
            h->data[idx/2] = elem;
            h->data[idx] = tmp;
            S.push(idx/2);
        }
    }
}

int Delete(HeapArray* h)
{
    int ans = h->data[1];

    h->data[1] = h->data[h->size--];



    std::stack<int> S;
    S.push(h->size);
    while(!S.empty())
    {
        int idx = S.top();
        S.pop();
        if(h->data[idx/2] < h->data[idx])
        {
            int tmp = h->data[idx/2];
            h->data[idx/2] = h->data[idx];
            h->data[idx] = tmp;
            S.push(idx/2);
        }
    }

    return ans;
}

void LevelTrav(HeapArray* h)
{
    for(int i = 1;i <= h->size;i++)
    {
        printf("%d\n",h->data[i]);
    }
}
