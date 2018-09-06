//
// Created by AlexanderChiu on 2018/9/6.
//

#ifndef CYCLE_KAHNTOPOLOGICALSORT_H
#define CYCLE_KAHNTOPOLOGICALSORT_H
#include <list>
#include <stack>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

class Graph{

private:
    list<int> *adj;
    int V;

public:
    Graph(int V);
    void topological();
    void addEdge(int v,int w);
};

void Graph::topological() {

    vector<int> inDegree(V,0);

    for(int i=0;i<V;i++){
        for(auto u:adj[i]){
            inDegree[u]++;
        }
    }

    queue<int> qu;
    for(int u=0;u<V;u++){
        if(inDegree[u]==0)
            qu.push(u);
    }

    int cnt=0;

    vector<int> result;
    while(!qu.empty()){
        int temp = qu.front();
        qu.pop();
        result.push_back(temp);
        for(auto v:adj[temp]){
            if(--inDegree[v]==0){
                qu.push(v);
            }

            cnt++;
        }

    }
    if(cnt!=V) {
        cout << "Cycle";
        return;
    }
    for(int i=0;i<V;i++)
        cout<<result[i]<<" ";
    cout<<endl;
}



Graph::Graph(int V) {
    this->V=V;
    adj = new list<int>[V];
}


void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}






#endif //CYCLE_KAHNTOPOLOGICALSORT_H
