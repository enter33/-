#ifndef __QUEUE_LIST_H__
#define __QUEUE_LIST_H__

#define MAXSIZE 2000

template<typename T>
struct node
{
    T data;
    node* next;
};

template<typename T>
class Queue_list
{
private:
    node<T>* head;
    node<T>* tail;
    int capacity;
    int getlen();
public:
    Queue_list(/* args */);
    ~Queue_list();

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
Queue_list<T>::Queue_list(/* args */)
{
    this->head = NULL;
    this->tail = NULL;
    this->capacity = MAXSIZE;
}

template<typename T>
Queue_list<T>::~Queue_list()
{

}


template<typename T>
int Queue_list<T>::getlen()
{
    if(this->IsEmpty())
    {
        return 0;
    }

    node<T>* temp = this->head;

    int len = 1;

    while(temp->next)
    {
        len ++;
        temp = temp->next;
    }

    return len;
}


/*判断队列是否已满*/
template<typename T>
int Queue_list<T>::IsFull()
{
    if(this->getlen() == this->capacity)
    {
        return 1;
    }
    return 0;
}

/*判断队列是否为空*/
template<typename T>
int Queue_list<T>::IsEmpty()
{
    if(this->head == NULL)
    {
        return 1;
    }
    return 0;
}

/*插入数据*/
template<typename T>
void Queue_list<T>::Add(T elem)
{
    if(this->IsFull())
    {
        perror("queue is full");
        return;
    }

    if(this->IsEmpty())
    {
        node<T>* temp = (node<T>*)malloc(sizeof(node<T>));
        temp->data = elem;
        temp->next = this->head;
        this->head = temp;
        this->tail = temp;
        return;
    }

    node<T>* temp = (node<T>*)malloc(sizeof(node<T>));
    temp->data = elem;
    this->tail->next = temp;
    this->tail = temp;

    return;
}

/*删除队列头部数据并返回*/
template<typename T>
T Queue_list<T>::Delete()
{
    if(this->IsEmpty())
    {
        perror("queue is empty");
        return NULL;
    }

    T ret = this->head->data;

    if(this->getlen() == 1)
    {
        this->tail = NULL;
        this->head = NULL;
        return ret;
    }

    this->head = head->next;

    return ret;
}



#endif /*__QUEUE_LIST_H__*/