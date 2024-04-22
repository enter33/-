#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./include/Heap.h"

bool compare(int,int);
void out(int data);

int main(int argc,char* argv[])
{
    Heap H;
    H.Add(1);
    H.Add(2);
    H.Add(3);
    H.Add(5);
    H.Add(8);
    H.Add(6);

    H.Delete();

    H.LevelTrav();


    return 0;
}