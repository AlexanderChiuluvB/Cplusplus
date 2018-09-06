//
// Created by AlexanderChiu on 2018/9/6.
//

#ifndef CYCLE_FINDSTRONGCOMPONENT_H
#define CYCLE_FINDSTRONGCOMPONENT_H
#include <stack>
#include <iostream>
using namespace std;

class Graph{
private:
    int V;
    list<int> *adj;
    //standard dfs
    void DFSUtil(int s,bool *visited);
public:
    Graph(int V);
    //first time dfs to save the dfs order in a stack
    void fillOrder(int s,bool *visited,stack<int>st);
    void addEdge(int v,int w);
    Graph getTranspose();
    void printSCCs();

};

void Graph::printSCCs() {

    //to save the first dfs path
    stack<int> Stack;

    bool* visited[V];
    for(int i=0;i<V;i++)
        visited[i]=false;

    for(int i=0;i<V;i++){
        fillOrder(i,visited,Stack);
    }

    for(int i=0;i<V;i++)
        visited[i]=false;

    Graph gr = this->getTranspose();


    //then following the path of the first time dfs to traverse the transposed graph

    while(!Stack.empty()){

        int top = Stack.top();
        Stack.pop();

        for(auto w:adj[top]){
            if(!visited[w]){
                //dfs for the transposed graph
                gr.DFSUtil(w,visited);
            }
        }

    }

}

Graph::Graph(int V){
    this->V=V;
    this->adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::fillOrder(int s, bool *visited, stack<int> st) {
    visited[s]=true;

    for(auto w:adj[s]){
        if(!visited[w]){
            fillOrder(w,visited,st);

        }
    }
    st.push(s);

}


Graph Graph::getTranspose() {

    Graph gr;
    for(int i=0;i<V;i++){
        for(auto w:adj[i])
            gr.adj[w].push_back(i);
    }

    return gr;
}

void Graph::DFSUtil(int s, bool *visited) {
    visited[s] = true;
    cout<< s<< " ";

    for(auto w:adj[s]){
        if(!visited[w]){
            DFSUtil(w,visited);
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();

    return 0;
}

#endif //CYCLE_FINDSTRONGCOMPONENT_H
