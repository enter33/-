/*数组实现最大堆*/

#ifndef __HEAPARRAY_H__
#define __HEAPARRAY_H__

#define MAXELEM 99999

struct HeapArray
{
    int* data;
    int capasize;
    int size;
};

HeapArray*  createheap(int);

void Add(HeapArray*,int);

int Delete(HeapArray*);

void LevelTrav(HeapArray* h);

#endif /*__HEAPARRAY_H__*/