#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__

#include <stdlib.h>
#include <stdio.h>

/*用指针实现链表*/

template<typename T>
class List_node
{
private:
    T data;
    List_node* next;
    List_node(T data);
public:
    List_node(/* args */);
    
    ~List_node();

     /*链表元素数量*/
    int getlength();

    /*给链表的尾部插入数据*/
    int pushElem(T data);

    /*给链表的index位置插入元素*/
    int insertElem(T data,int index);

    // int deleteElem(T data);

    /*删除链表index位置的元素*/
    int deleteElem(int index);

    /*获取链表index位置的元素*/
    T getdata(int index);

    void output();

};

// template<typename T>
// using List = List_node<T>;



template<typename T>
List_node<T>::List_node(/* args */)
{
    this->next = NULL;
}

template<typename T>
List_node<T>::List_node(T data)
{
    this->next = NULL;
    this->data = data;
}


template<typename T>
List_node<T>::~List_node()
{
    // delete this->data;
}


template<typename T>
int List_node<T>::getlength()
{
    int len = 0;
    if(this->next == NULL)
    {
        return 0;
    }

    List_node* temp = this;

    while(temp->next)
    {
        len++;
        temp = (temp->next);
    }

    return len;
}

template<typename T>
int List_node<T>::pushElem(T data)
{
    List_node* temp = this;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = new List_node<T>(data);
    return 0;
}


/*给链表的index位置插入元素*/
template<typename T>
int List_node<T>::insertElem(T data,int index)
{
    if(index < 0 || index > this->getlength())
    {
        return -1;
    }

    List_node* node = new List_node<T>(data);

    if(index == 0)
    {
        node->next = this->next;
        this->next = node;
        return 0;
    }

    List_node* temp = this->next;
    for(int i = 0;i < index-1;i++)
    {
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next = node;
    return 0;

}

// int deleteElem(T data);

/*删除链表index位置的元素*/
template<typename T>
int List_node<T>::deleteElem(int index)
{
    if(index < 0 || index >= this->getlength())
    {
        return -1;
    }

    if(index == 0)
    {
        List_node* temp = this->next;
        this->next = this->next->next;
        delete temp;
        return 0;
    }

    List_node* temp = this->next;
    for(int i = 0;i < index-1;i++)
    {
        temp = temp->next;
    }

    List_node* temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;

    return 0;
}

/*获取链表index位置的元素*/
template<typename T>
T List_node<T>::getdata(int index)
{
    if(index < 0 || index >= this->getlength())
    {
        return NULL;
    }

    List_node* temp = this->next;
    for(int i = 0;i < index;i++)
    {
        temp = temp->next;
    }

    return temp->data;
}

template<>
void List_node<int>::output()
{
    if(this->next == NULL)
    {
        return;
    }

    printf("data\n");
    List_node* temp = this->next;
    while(1)
    {
        printf("%d\n",temp->data);
        if(temp->next)
        {
            temp = temp->next;
        }
        else
        {
            break;
        }
    }
}



#endif /*__LIST_NODE_H__*/