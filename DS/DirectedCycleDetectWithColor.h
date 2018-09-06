//
// Created by AlexanderChiu on 2018/9/6.
//

#ifndef CYCLE_DIRECTEDCYCLEDETECTWITHCOLOR_H
#define CYCLE_DIRECTEDCYCLEDETECTWITHCOLOR_H

#include <iostream>
#include <list>
#include <limits.h>

using namespace std;

enum Color {WHITE,GRAY,BLACK};

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool DFSUtil(int v, int color[]);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
};


bool Graph::isCyclic() {

    int *color = new int [V];
    for(int i=0;i<V;i++){
        color[i]=WHITE;
    }
    for(int u=0;u<V;u++){
        if(color[u]==WHITE){
            if(DFSUtil(u,color))
                return true;
        }
    }
    return false;
}

bool Graph::DFSUtil(int v, int color[]) {

    color[v] = GRAY;

    for(auto w:adj[v]){
        if(color[w]==GRAY)
            return true;
        else if(color[w]==WHITE && DFSUtil(w,color))
            return true;
    }
    //finish process
    color[v] =BLACK;
    return false;
}

Graph::Graph(int V){

    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {

    adj[v].push_back(w);
}





#endif //CYCLE_DIRECTEDCYCLEDETECTWITHCOLOR_H
