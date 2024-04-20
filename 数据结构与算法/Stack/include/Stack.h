#ifndef __STACK_H__
#define __STACK_H__

/*用数组实现堆栈*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXSIZE 2000 /*栈容量*/

/*用单向链表实现堆栈,不能用链尾当作栈顶,pop操作找不到新的栈顶*/

template<typename T>
class Stack
{
private:
    T data[MAXSIZE];
    int pos;//栈顶位置

public:
    Stack()
    {
        this->pos = 0;
    }
    ~Stack()
    {

    }

    int IsFull();/*判断栈是否已满*/
    void Push(T elem);/*入栈*/
    int IsEmpty();/*判断栈是否为空*/
    T Pop();/*出栈*/
    int len();/*栈内元素数量*/

};

/*判断栈是否已满*/
template<typename T>
int Stack<T>::IsFull()
{
    if(this->pos == MAXSIZE)
    {
        return 1;
    }

    return 0;
}

/*判断栈是否为空*/
template<typename T>
int Stack<T>::IsEmpty()
{
    if(this->pos == 0)
    {
        // exit(0);
        return 1;
    }

    return 0;
}

/*入栈*/
template<typename T>
void Stack<T>::Push(T elem)
{
    /*判断是否已满*/
    if(this->IsFull())
    {
        printf("stack is full\n");
        return;
    }
    this->data[this->pos++] = elem;
}

/*出栈*/
template<typename T>
T Stack<T>::Pop()
{
    /*判断是否为空*/
    if(this->IsEmpty())
    {
        printf("stack is empty\n");
        // exit(0);
        return NULL;
    }

    return this->data[--this->pos];
}

/*栈内元素数量*/
template<typename T>
int Stack<T>::len()
{
    return this->pos;
}


#endif /*__STACK_H__*/