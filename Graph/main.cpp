
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 8 10
// 1 2
// 1 5
// 1 8
// 2 3
// 3 4
// 4 5
// 5 6
// 4 7
// 4 8
// 7 8


void DFS(std::vector<std::vector<int> > graph,std::vector<int> &visited,int vertex);
void BFS(std::vector<std::vector<int> > graph,std::vector<int> &visited,int vertex);
std::vector<std::vector<int> > createGraph();

int main()
{
    std::vector<std::vector<int> > graph = createGraph();

    std::vector<int> visited;

    for(int i = 0;i < graph.size();i++)
    {
        visited.push_back(0);
    }

    std::cout<<"duqu over"<<std::endl;
    std::cout<<"input first vertex: ";

    int firstvertex;

    cin>>firstvertex;

    // DFS(graph,visited,firstvertex);

    BFS(graph,visited,firstvertex);


    return 0;
}

std::vector<std::vector<int> > createGraph()
{
    std::vector<std::vector<int> > matrix;

    int vertexnums,edgenums;
    cin>>vertexnums>>edgenums;

    for(int i = 0;i <vertexnums;i++)
    {
        std::vector<int> temp;
        for(int j = 0;j <vertexnums;j++)
        {
            temp.push_back(0);
        }
        matrix.push_back(temp);
    }

    for(int i = 0;i < edgenums;i++)
    {
        int idx1,idx2;
        cin>>idx1>>idx2;

        if(idx1 <= 0 || idx1 > vertexnums || idx2 <= 0 || idx2 > vertexnums)
        {
            std::cout<<"wrong index"<<std::endl;
            continue;
        }

        matrix[idx1-1][idx2-1] = 1;
        matrix[idx2-1][idx1-1] = 1;
    }

    return matrix;
}

void DFS(std::vector<std::vector<int> > graph,std::vector<int> &visited,int vertex)
{

    // for(int i = 0;i < graph.size();i++)
    // {
    //     visited[i] = 0;
    // }
    vertex = vertex -1;

    if(visited[vertex] != 1)
    {
        visited[vertex] = 1;
        std::cout<<"visited "<<vertex+1<<std::endl;
        for(int i = 0;i <graph.size();i++)
        {
            if(graph[vertex][i] == 1)
            {
                DFS(graph,visited,i+1);
            }
        }
    }


}

void BFS(std::vector<std::vector<int> > graph,std::vector<int> &visited,int vertex)
{

    // for(int i = 0;i < graph.size();i++)
    // {
    //     visited[i] = 0;
    // }
    vertex = vertex -1;
    std::queue<int> Q;

    Q.push(vertex);

    while(!Q.empty())
    {
        int ver = Q.front();
        Q.pop();

        if(visited[ver] != 1)
        {
            visited[ver] = 1;
            std::cout<<"visited "<<ver+1<<std::endl;
        }

        for(int i = 0;i < graph.size();i++)
        {
            if(graph[ver][i] == 1 && visited[i] == 0)
            {
                Q.push(i);
            }
        }
    }


}