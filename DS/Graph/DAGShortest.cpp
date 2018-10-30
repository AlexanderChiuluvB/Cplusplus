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
 *
 * 1) Initialize dist[] = {INF, INF, ….} and dist[s] = 0 where s is the source vertex.
    2) Create a toplogical order of all vertices.
    3) Do following for every vertex u in topological order.
………..   Do following for every adjacent vertex v of u
………………      if (dist[v] > dist[u] + weight(u, v))
………………………       dist[v] = dist[u] + weight(u, v)
 * 
 *
 * */

//不确定是否正确
class Graph{
private:
    int V;
    unordered_map<int,int> in;
    list<pair<int,int>> *adj;

public:
    Graph(int V);

    void addEdge(int u,int v,int w);
    //single source shortest path
    void shortestPath(int s);
    queue<int>topologicalSort();
};


Graph::Graph(int V) {
    this->V =V;
    //pair<v,weight>
    adj = new list<pair<int,int> >[V];
}

//这里有向图的话要删掉第二句
void Graph::addEdge(int u, int v, int w) {
    this->adj[u].emplace_back(make_pair(v,w));
    this->adj[v].emplace_back(make_pair(u,w));
    in[v]++;
}
queue<int> Graph::topologicalSort() {
    queue<int>zero;
    queue<int> result;
    for(int i=0;i<V;i++){
        if(in[i]==0){
            zero.push(i);
        }
    }
    while(!zero.empty()){
        int front = zero.front();
        zero.pop();
        result.push(front);
        for(auto p:this->adj[front]){
            //int weight = p.second;
            int v = p.first;
            in[v]--;
            if(in[v]==0)
                zero.push(v);
        }
    }
    return result;


}
void Graph::shortestPath(int s) {
    //1.init
    queue<int> pq = topologicalSort();
    vector<int> distTo(V,INF);
    vector<int> edgeTo(V,0);
    distTo[s] = 0;
    //priority_queue<iPair,vector<iPair>,greater<iPair> > pq;
    //pq.push(make_pair(0,s));

    //2.
    while(!pq.empty()){

        int u= pq.front();
        pq.pop();

        //int weight = top.first;
        //this->adj[v] is pair<vertex,weight>，与pq是反过来的
        for(auto p:this->adj[u]){
            int weight = p.second;
            int v = p.first;
            //if there is shortest path from v to u
            if(distTo[v]>distTo[u]+weight){
                //update distance of v
                distTo[v] = distTo[u]+weight;
                //edgeTo[v] = u;
            }
        }
    }

    printf("Vertex-EdgeTo-Distance\n");
    for(int i=0;i<distTo.size();i++){
        cout<<i<<"-"<<distTo[i]<<endl;
    }

}

int main()
{

    // create the graph given in above fugure



    //  making above shown graph
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.shortestPath(0);


    return 0;
}