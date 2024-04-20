#ifndef __LIST_ORDER_H__
#define __LIST_ORDER_H__

//使用数组实现链表

#include <stdlib.h>
#include <stdio.h>

template<typename T>
class List_order
{
private:
    T* data;
    int length;
public:
    List_order(int len = 1);
    ~List_order();

    // int initList();
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
};

template<typename T>
List_order<T>::List_order(int len)
{
    this->data = (T*)malloc(sizeof(T)*len);
    this->length = 0;
}

template<typename T>
List_order<T>::~List_order()
{
    delete[] this->data;
}


// template<typename T>
// int List_order<T>::initList()
// {

//     this->List_order();

//     return 0;
// }


template<typename T>
int List_order<T>::getlength()
{
    return this->length;
}


template<typename T>
int List_order<T>::pushElem(T data)
{
    this->data[this->length++] = data;
    return 0;
}

template<typename T>
int List_order<T>::insertElem(T data,int index)
{
    //非法索引判断
    if(index < 0 || index > length)
    {
        printf("error index\n");
        return -1;
    }

    for(int i = index;i < this->length;i++)
    {
        this->data[i+1] = this->data[i];
    }

    this->data[index] = data;
    this->length ++;

    return 0;
}

template<typename T>
int List_order<T>::deleteElem(int index)
{
    //非法索引判断
    if(index < 0 || index >= length)
    {
        printf("error index\n");
        return -1;
    }

    for(int i = index;i < this->length;i++)
    {
        this->data[i] = this->data[i+1];
    }

    this->length--;

    return 0;
}

// template<typename T>
// int List_order<T>::deleteElem(T data)
// {
//     return 0;
// }


template<typename T>
T List_order<T>::getdata(int index)
{
    //非法索引判断
    if(index < 0 || index >= length)
    {
        printf("error index\n");
        exit(0);
    }

    return this->data[index];
}




#endif /*__LIST_ORDER_H__*/