#include <stdio.h>
#include "./include/List_order.h"
#include "./include/List_node.h"

void testList();
void testNode();

int main(int argc,char* argv[])
{
    // testList();
    testNode();

    return 0;
}

void testList()
{
    List_order<int> L;

    printf("len = %d\n",L.getdata(0));

    int length;
    length = L.getlength();
    printf("len = %d\n",length);

    L.deleteElem(1);
    length = L.getlength();
    printf("len = %d\n",length);

    L.deleteElem(5);

    L.insertElem(7,2);

    for(int i = 0;i < L.getlength();i++)
    {
        printf("data = %d\n",L.getdata(i));
    }
}


void testNode()
{
    List_node<int>* list = new  List_node<int>();
    list->pushElem(1);
    list->pushElem(2);
    list->pushElem(3);
    list->pushElem(4);
    list->pushElem(5);
    list->pushElem(6);

    // printf("length = %d\n",list->getlength());
    // list->output();


    list->insertElem(10,0);
    list->insertElem(20,list->getlength());

    printf("length = %d\n",list->getlength());
    list->output();


    list->deleteElem(0);
    list->deleteElem(list->getlength()-1);
    printf("length = %d\n",list->getlength());
    list->output();

    printf("data = %d\n",list->getdata(0));
    printf("data = %d\n",list->getdata(list->getlength()-1));
    
}