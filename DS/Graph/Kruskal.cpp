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

typedef pair<int,int> iPair;

class Graph{

private:

    int V,E;
    //pair<weight,<v,w>>
    vector< pair<int,iPair> > edges;


public:
    Graph(int V,int E){
        this->V = V;
        this->E = E;

    }

    void addEdge(int u,int v,int w){
        edges.push_back(make_pair(w,make_pair(u,v)));
    }

    int kruskalMST();

};

//union by Rank
//https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
class disjointSets{

private:
    int *parent,*rank;
    int n;
public:
    disjointSets(int n){
        this->n = n;
        this->parent = new int [n+1];
        this->rank = new int [n+1];
        //initially all vertices are in different sets and have 0 rank
        for(int j=0;j<=n;j++){
            rank[j] = 0;
            parent[j] = j;
        }
    }

    //递归向上寻找根节点
    //所有的点分属于不同的parent，就是分属于不同的组
    int find(int u){

        if(u!=parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    //rank比较低的树成为rank比较高的树的子树
    void Union(int x,int y){

        x = find(x);
        y = find(y);

        if(rank[x]<rank[y])
            parent[x] = y;
        else
            parent[y] = x;
        if(rank[x]==rank[y])
            rank[y]++;
    }
};


//optimization if vertex == V-1 can stop loop !
int Graph::kruskalMST() {

    int mst_result = 0;
    int edgeCount = 0;
    sort(edges.begin(),edges.end());

    disjointSets unionFind(V);

    auto it = edges.begin();
    for(;it!=edges.end();++it){
        if(edgeCount==V-1)
            break;
        //u,v 分别为两个set
        int u = unionFind.find((*it).second.first);
        int v = unionFind.find((*it).second.second);

        if(u!=v){
            cout<<u<<"->"<<v<<endl;
            edgeCount++;
            mst_result+=(*it).first;
            unionFind.Union(u,v);
        }

    }
    return mst_result;

}



int main()
{
    /* Let us create above shown weighted
       and unidrected graph */
    int V = 9, E = 14;
    Graph g(V, E);

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

    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();

    cout << "\nWeight of MST is " << mst_wt;

    return 0;
}