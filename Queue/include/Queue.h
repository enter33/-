#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*用顺序存储实现队列*/

#define MAXSIZE 2000

template<typename T>
class Queue
{
private:
    T* data;
    int capasize;
    int head;
    int tail;
public:
    Queue(/* args */);

    Queue(int capasize);
    
    ~Queue();

    /*判断队列是否已满*/
    int IsFull();

    /*判断队列是否为空*/
    int IsEmpty();

    /*插入数据*/
    void Add(T elem);

    /*删除队列头部数据并返回*/
    T Delete();

};

template<typename T>
Queue<T>::Queue(/* args */)
{
    this->capasize = MAXSIZE;
    this->data = new T(this->capasize);
    this->head = 0;
    this->tail = 0;
}

template<typename T>
Queue<T>::Queue(int capasize)
{
    this->capasize = capasize;
    this->data = new T(this->capasize);
    this->head = 0;
    this->tail = 0;
}

template<typename T>
Queue<T>::~Queue()
{
    delete this->data;
}

/*判断队列是否已满*/
template<typename T>
int Queue<T>::IsFull()
{
    if((this->tail - this->head) == this->capasize)
    {
        return 1;
    }
    return 0;
}


template<typename T>
int Queue<T>::IsEmpty()
{
    if(this->head == this->tail)
    {
        return 1;
    }
    return 0;
}


template<typename T>
void Queue<T>::Add(T elem)
{
    if(this->IsFull())
    {
        perror("Queue is full");
        return;
    }
    this->data[this->tail++%this->capasize] = elem;

    return;
}


template<typename T>
T Queue<T>::Delete()
{
    if(this->IsEmpty())
    {
        perror("Queue is empty\n");
        return NULL;
    }

    return this->data[this->head++%this->capasize];
}

#endif /*__QUEUE_H__*/