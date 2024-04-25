#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>

class Graph
{
private:

    struct vertex
    {
        int index;
        int flag;
    };
    

    struct edge
    {
        vertex* v1;
        vertex* v2;
        int weight;
    };

    vertex* V_array;
    edge* E_array;

    int vertex_nums;
    int edge_nums;


public:
    Graph(int,int);
    Graph();
    ~Graph();

    void addVertex(int);
    void addEdge(int,int);
};

Graph::Graph(int vertexnums,int edgenums)
{
    this->vertex_nums = vertexnums;
    this->edge_nums = edgenums;
    this->V_array = (vertex*)malloc(sizeof(vertex)*this->vertex_nums);
    this->E_array = (edge*)malloc(sizeof(edge)*this->edge_nums);
}

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::addVertex(int index)
{
    vertex v;
    v.index = index;
    v.flag = 0;
    this->V_array[index] = v;
}

void Graph::addEdge(int v1,int v2)
{
    //判断v1,v2是否合理


    edge e;
    e.v1 = &(this->V_array[v1]);
    e.v2 = &(this->V_array[v2]);
    e.weight = 0;
    // this->E_array[]

}



#endif /*__GRAPH_H__*/