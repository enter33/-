#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./include/Queue.h"
#include "./include/Queue_list.h"


void testqueue();
void testqueue_list();


int main(int argc,char *argv[])
{
    // testqueue();
    testqueue_list();

    return 0;
}

void testqueue()
{
    Queue<int> queue(5);


    queue.Add(1);
    queue.Add(2);
    queue.Add(3);
    queue.Add(4);
    // queue.Delete();
    queue.Add(5);
    queue.Add(6);

    int res;
    while(res = queue.Delete())
    {
        printf("data = %d\n",res);
    }

}


void testqueue_list()
{
    Queue_list<int> queue;

    queue.Add(1);
    queue.Add(2);
    queue.Add(3);
    queue.Add(4);
    queue.Delete();
    queue.Add(5);
    queue.Add(6);

    int res;
    while(res = queue.Delete())
    {
        printf("data = %d\n",res);
    }
}