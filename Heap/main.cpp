#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./include/Heap.h"
#include "./include/HeapArray.h"
#include <iostream>
#include <vector>

bool compare(int,int);
void out(int data);
int findset(std::vector<int>,int);
void unionfindset();


int main(int argc,char* argv[])
{
    // Heap H;
    // H.Add(1);
    // H.Add(2);
    // H.Add(3);
    // H.Add(5);
    // H.Add(8);
    // H.Add(6);

    // H.Delete();

    // H.LevelTrav();

    // HeapArray* h = createheap(10);
    // Add(h,1); 
    // Add(h,3); 
    // Add(h,4); 
    // Add(h,5); 

    // LevelTrav(h);

    unionfindset();

    return 0;
}

/*并查集*/
void unionfindset()
{
    std::vector<int> V;

    int n;
    std::cin>>n;

    for(int i = 0;i < n;i++)
    {
        V.push_back(-1);
    }

    for(;;)
    {
        char operation;
        int mac1,mac2;
        std::cin>>operation;
        if(operation == 'c')
        {
            std::cin>>mac1>>mac2;
            if(findset(V,mac1-1) == findset(V,mac2-1))
            {
                std::cout<<"yes"<<std::endl;
            }
            else
            {
                std::cout<<"no"<<std::endl;
            }
        }
        else if(operation == 'i')
        {
            std::cin>>mac1>>mac2;
            if(V[mac2-1] == -1)
            {
                V[mac2-1] = mac1-1;
            }
            else
            {
                V[findset(V,mac2-1)] = mac1-1;
            }
        }

        else
        {
            break;
        }
    }
}

int findset(std::vector<int> V,int elem)
{
    if(V[elem] == -1)
    {
        return elem;
    }

    while(1)
    {
        if(V[elem] != -1)
        {
            elem = V[elem];
        }
        else
        {
            break;
        }
    }
    return elem;
}