#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./include/Queue.h"


int main(int argc,char *argv[])
{
    Queue<int> queue(5);


    queue.Add(1);
    queue.Add(2);
    queue.Add(3);
    queue.Add(4);
    queue.Delete();
    queue.Add(5);
    queue.Add(6);


    for(int i = 0;i < 5;i++)
    {
        int res = queue.Delete();

        printf("data = %d\n",res);
    }


    return 0;
}