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
#include <iterator>
#include <ctype.h>
using namespace std;
#define INF 0x3f3f3f3f3f

typedef pair<int,int>iPair;

/*
 *
 * ) Initialize distances of all vertices as infinite.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or
   distance) is used used as first item  of pair
   as first item is by default used to compare
   two pairs

3) Insert source vertex into pq and make its
   distance as 0.

4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq.
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do
       following for every vertex v.

           // If there is a shorter path to v
           // through u.
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)

5) Print distance array dist[] to print all shortest
   paths.
 * */


class Graph{
private:
    int V;

    list<pair<int,int>> *adj;

public:
    Graph(int V);

    void addEdge(int u,int v,int w);
    //single source shortest path
    void shortestPath(int s);

};


Graph::Graph(int V) {
    this->V =V;
    adj = new list<pair<int,int> >[V];
}

//这里有向图的话要删掉第二句
void Graph::addEdge(int u, int v, int w) {
    this->adj[u].emplace_back(make_pair(v,w));
    this->adj[v].emplace_back(make_pair(u,w));

}

void Graph::shortestPath(int s) {
    //1.init

    vector<int> distTo(V,INF);
    vector<int> edgeTo(V,0);
    distTo[s] = 0;
    priority_queue<iPair,vector<iPair>,greater<iPair> > pq;
    pq.push(make_pair(0,s));

    //2.
    while(!pq.empty()){

        auto top = pq.top();
        pq.pop();

        //int weight = top.first;
        int u = top.second;

        //this->adj[v] is pair<vertex,weight>，与pq是反过来的
        for(auto p:this->adj[u]){
            int weight = p.second;
            int v = p.first;
            //if there is shortest path from v to u
            if(distTo[v]>distTo[u]+weight){
                //update distance of v
                distTo[v] = distTo[u]+weight;
                //edgeTo[v] = u;
                pq.push(make_pair(distTo[v],v));
            }
        }
    }

    printf("Vertex-EdgeTo-Distance\n");
    for(int i=0;i<distTo.size();i++){
        cout<<i<<"-"<<edgeTo[i]<<"-"<<distTo[i]<<endl;
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

    g.shortestPath(2);



    return 0;
}