//
// Created by AlexanderChiu on 2018/10/27.
//

#include <iostream>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <list>
#include <sstream>
#include <functional>
#include <stack>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int> iPair;

class Graph{
private:
    int V;
    //pair<vertex,weight>
    list<pair<int,int>> *adj;
public:
    Graph(int V);
    void addEdge(int u,int v,int w);
    void primMST();
};

Graph::Graph(int V) {
    this->V = V;
    this->adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w) {
    this->adj[u].push_back(make_pair(v,w));
    this->adj[v].push_back(make_pair(u,w));
}

void Graph::primMST() {

    //这里的pair是<weight,vertex> 因为pq默认按第一个数据排序
    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;

    int source = 0;

    //check whether v in MST
    vector<bool> inMST(V,false);
    //parent of v
    vector<int> parent(V,-1);
    //weight of the edges that contain v
    vector<int> key(V,INF);

    //insert source itself
    pq.push(make_pair(0,source));
    key[source] = 0;

    int count=0;
    while(!pq.empty()){
        auto pair = pq.top();
        pq.pop();
        //vertex label
        int top = pair.second;
        inMST[top] = true;
        count++;
        auto it = this->adj[top].begin();
        for(;it!=adj[top].end();++it){
            int v = it->first;
            int weight = it->second;
            //如果点不在MST当中并且v的对应新的边权重小于原来v在堆中对应的边权重则更新
            if(!inMST[v]&&weight<key[v]){
                parent[v] = top;
                key[v] = weight;
                pq.push(make_pair(weight,v));
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        cout<<parent[i]<<" "<<i<<endl;
    }

}

int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.primMST();

    return 0;
}