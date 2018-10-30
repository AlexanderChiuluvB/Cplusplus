//
// Created by AlexanderChiu on 2018/10/30.
//


//https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/
#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int> ipair;


struct edge{
    int weight,src,dest;
};
class Graph{
private:
    int V;
    int E;
    list<ipair>*adj;

    //void dfs(int s,vector<bool>&visited,stack<int>&st);
public:
    Graph(int V,int E);
    //void addEdge(int u,int v,int w);
    void bellmanFord(int s);
    edge* Edge;
};

Graph::Graph(int V,int E) {
    this->V = V;
    this->E = E;
    this->Edge = new edge[E];
    adj = new list<ipair>[V];
}

void Graph::bellmanFord(int s) {

    //init
    vector<int> distTo(V,INF);
    distTo[s] = 0;

    //A simple shortest path from stc to any other vertex can have atmost |V-1| edges,so iterate V-1 times
    //relax all edges |V|-1 time

    for(int i=1;i<=V-1;i++){

        for(int j=0;j<E;j++){
            int weight = this->Edge[j].weight;
            int src = this->Edge[j].src;
            int dest = this->Edge[j].dest;
            //relax
            if(distTo[src]!=INF&&distTo[dest]>distTo[src]+weight){
                distTo[dest] = distTo[src]+weight;
            }
        }
    }
    
    //check for negative-weight cycles.
    //the above step guarantees shortest distancesif graph does not contain
    //negative weight cycle
    // if get a shorter path there is a cycle
    for(int j=0;j<E;j++) {
        int weight = this->Edge[j].weight;
        int src = this->Edge[j].src;
        int dest = this->Edge[j].dest;
        //relax
        if (distTo[src] != INF && distTo[dest] > distTo[src] + weight) {
            cout << "contain negative cycle" << endl;
        }
    }


    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, distTo[i]);

}


int main()
{
    /* Let us create the graph given in above example */
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    Graph graph(V,E);
    // add edge 0-1 (or A-B in above figure)
    graph.Edge[0].src = 0;
    graph.Edge[0].dest = 1;
    graph.Edge[0].weight = -1;

    // add edge 0-2 (or A-C in above figure)
    graph.Edge[1].src = 0;
    graph.Edge[1].dest = 2;
    graph.Edge[1].weight = 4;

    graph.Edge[2].src = 1;
    graph.Edge[2].dest = 2;
    graph.Edge[2].weight = 3;


    // add edge 1-3 (or B-D in above figure)
    graph.Edge[3].src = 1;
    graph.Edge[3].dest = 3;
    graph.Edge[3].weight = 2;



    // add edge 1-4 (or A-E in above figure)
    graph.Edge[4].src = 1;
    graph.Edge[4].dest = 4;
    graph.Edge[4].weight = 2;



    // add edge 3-2 (or D-C in above figure)
    graph.Edge[5].src = 3;
    graph.Edge[5].dest = 2;
    graph.Edge[5].weight = 5;


    // add edge 3-1 (or D-B in above figure)
    graph.Edge[6].src = 3;
    graph.Edge[6].dest = 1;
    graph.Edge[6].weight = 1;


    // add edge 4-3 (or E-D in above figure)
    graph.Edge[7].src = 4;
    graph.Edge[7].dest = 3;
    graph.Edge[7].weight = -3;
    graph.bellmanFord( 0);

    return 0;
}

