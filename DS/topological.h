//
// Created by AlexanderChiu on 2018/9/6.
//

#ifndef CYCLE_TOPOLOGICAL_H
#define CYCLE_TOPOLOGICAL_H
#include <list>
#include <stack>
#include <iostream>
using namespace std;

class Graph{

private:
    list<int> *adj;
    int V;
    bool topologicalSortUtil(int s,bool visited[],stack<int> &St);
public:
    Graph(int V);
    void topological();
    void addEdge(int v,int w);


};

Graph::Graph(int V) {
    this->V=V;
    adj = new list<int>[V];
}

void Graph::topological() {

    bool *visited = new bool[V];
    stack<int> st(V);
    for(int i=0;i<V;i++){
        visited[i] = false;
    }

    for(int u=0;u<V;u++){
        if(!visited[u])
            topologicalSortUtil(u,visited,st);
    }

    while(!st.empty()) {
        cout << st.top()<<" ";
        st.pop();
    }

}


bool Graph::topologicalSortUtil(int s, bool *visited, stack<int>&St) {

    visited[s]=true;

    for(auto w:adj[s]){
        if(!visited[w]){
            topologicalSortUtil(w,visited,St);
        }
    }

    St.push(s);


}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}



#endif //CYCLE_TOPOLOGICAL_H
