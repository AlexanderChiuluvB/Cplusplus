//
// Created by AlexanderChiu on 2018/9/6.
//

#ifndef CYCLE_DIRECYEDCYCLE_H
#define CYCLE_DIRECYEDCYCLE_H
#include <iostream>
#include <list>
#include <stack>
#include <limits.h>

using namespace std;

class Graph{

private:
    int V;
    list<int> *adj;
    bool isCycleUtil(int v,bool visited[],bool *recStack);
public:
    Graph(int V);
    void addEdge(int v,int w);
    bool IsCycle();

};

Graph::Graph(int V) {
    this->adj = new list<int> [V];
    this->V=V;

}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}


bool Graph::isCycleUtil(int v, bool *visited, bool *recStack) {

    if(visited[v]==false){
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for(i = adj[v].begin();i!=adj[v].end();i++){
            if(!visited[v] && isCycleUtil(*i,visited,recStack))
                return true;
            // 在栈中有点像在你的父节点的路上，如果一个有向图的一个顶点有指向其父节点系列道路上的边，则说明有环
            else if(recStack[*i])
                return false;
        }
    }

    recStack[v] = false;
    return false;

}

bool Graph::IsCycle() {

    bool *visited = new bool [V];
    bool *recStack = new bool [V];

    for(int i=0;i<V;i++){
        visited[i] = false;
        recStack[i] =false;
    }

    for(int u=0;u<V;u++){
        if(isCycleUtil(u,visited,recStack))
            return true;

    }
    return false;
}


#endif //CYCLE_DIRECYEDCYCLE_H
