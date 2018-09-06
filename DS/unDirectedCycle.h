//
// Created by AlexanderChiu on 2018/9/6.
//

#ifndef CYCLE_UNDIRECTEDCYCLE_H
#define CYCLE_UNDIRECTEDCYCLE_H



class Graph{

private:
    int V;
    list<int> *adj;
    bool isCycleUtil(int v,bool visited[],int parent);
public:
    Graph(int V);
    void addEdge(int v,int w);
    bool isCycle();

};

Graph::Graph(int V) {
    this->adj = new list<int> [V];
    this->V=V;

}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isCycleUtil(int v, bool *visited, int parent)
{

    visited[v] = true;

    for(auto w:adj[v]){
        if(!visited[w]){
            if(isCycleUtil(w,visited,v))
                return true;
        }
            //if an adj vertex is parent, then it has cycle
        else if(w!=parent)
            return true;
    }
    return false;
}

bool Graph::isCycle() {

    bool *visited = new bool [V];
    for(int i=0;i<V;i++)
        visited[i] = false;

    //traverse all the vertex and then find whether cycle exists
    for(int u=0;u<V;u++){
        if(!visited[u])
            if(isCycleUtil(u,visited,-1))
                return true;
    }

    return false;

}

#endif //CYCLE_UNDIRECTEDCYCLE_H
