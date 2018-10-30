//
// Created by AlexanderChiu on 2018/10/30.
//

// A C++ program to find single source longest distances
// in a DAG
#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int> ipair;
class Graph{
private:
    int V;
    list<ipair>*adj;
    void dfs(int s,vector<bool>&visited,stack<int>&st);
public:
    Graph(int V);
    void addEdge(int u,int v,int w);
    void longestPath(int s);

};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<ipair>[V];
}

void Graph::addEdge(int u, int v, int w) {
    this->adj[u].push_back(make_pair(v,w));
    //this->adj[v].push_back(make_pair(u,w));
}

void Graph::dfs(int s,vector<bool>&visited,stack<int>&st){

    visited[s] = true;

    for(auto p:this->adj[s]){
        if(!visited[p.first]){
           dfs(p.first,visited,st);
        }
    }
    st.push(s);

}

void Graph::longestPath(int s) {

    vector<bool> visited(V,false);
    stack<int> st;
    //注意这里初始值设置为INT_MAX
    vector<int> distTo(V,INF);
    distTo[s] = 0;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,visited,st);
        }
    }
    //Topological order is the reverse of dfs sequence
    while(!st.empty()){
        //get the next vertex from topological order
        int top = st.top();
        st.pop();
        if(distTo[top]!=INF){

            for(auto p:this->adj[top]){
                int v = p.first;
                int weight = p.second;
                //negate all the weight
                if(distTo[v]>distTo[top]+weight*-1)
                    distTo[v] = distTo[top]+weight*-1;
            }
        }
    }



    for (int i = 0; i < V; i++)
    {
        if (distTo[i] == INF)
            cout << "INT_MIN ";
        else
            cout << (distTo[i] * -1) << " ";
    }


}


int main(){
    Graph g(6);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;

    cout << "Following are longest distances from "
         << "source vertex " << s << " \n";
    g.longestPath(s);

    return 0;
}



