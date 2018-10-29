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

/*
 *id[] 数组存储着每个点分别属于哪一个strong connected components
 *
 * https://www.geeksforgeeks.org/strongly-connected-components/
 * reference as above
 */


class Graph{

private:
    int V;
    list<int>*adj;

    //int *id;
    //fill the postorder sequence to the stack
    //the top of the stack has maximum finishing time
    void fillOrder(int v,bool visited[],stack<int>&Stack);

    void dfsUtil(int v,bool visited[],int& count,int id[]);

public:
    Graph(int V);

    void addEdge(int v,int w);

    void printSCC(int& count,int id[]);

    void printID(int id[]);

    Graph getTranspose();

};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
    //count=0;
    //id = new int[V];
    //for(int i=0;i<V;i++)
      //  this->id[i] = 0;

}

void Graph::addEdge(int v, int w) {
    this->adj[v].push_back(w);
}

Graph Graph::getTranspose() {

    Graph g(V);
    for(int i=0;i<V;i++){
        for(int v:this->adj[i]){
            g.adj[v].push_back(i);
        }
    }
    return g;
}

void Graph::dfsUtil(int v, bool *visited,int& count,int id[]) {

    visited[v] = true;
    cout<<v<<" ";
    id[v] = count;
    for(auto u:this->adj[v]){
        if(!visited[u])
        {
            dfsUtil(u,visited,count,id);
        }
    }

}

void Graph::fillOrder(int v, bool *visited, stack<int> &Stack) {


    visited[v] = true;
    //cout<<v<<" ";
    for(auto u:this->adj[v]){
        if(!visited[u])
        {
            fillOrder(u,visited,Stack);
        }
    }
    //不能放在for循环前面，否则栈顶就是最早结束的点，而不是最晚结束的点
    Stack.push(v);
}


void Graph::printSCC(int &count,int id[]) {

    stack<int> Stack;

    bool *visited = new bool [V];
    for(int i=0;i<V;i++)
        visited[i] = false;

    for(int i=0;i<V;i++){
        if(!visited[i])
            fillOrder(i,visited,Stack);
    }

    Graph transposed = getTranspose();

    //remember to initialize again
    for(int i=0;i<V;i++)
        visited[i] = false;

    while(!Stack.empty()){
        int top = Stack.top();
        Stack.pop();
        if(!visited[top]) {
            transposed.dfsUtil(top, visited,count,id);
            count++;
            cout<<endl;
        }
    }
}


void Graph::printID(int id[]) {
    for(int i=0;i<V;i++){
        cout<<i<<" "<<id[i]<<endl;
    }
}

int main(){
    //int count=0;
    int id[100]= {0};

    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Following are strongly connected components in "
            "given graph \n";
    int count=0;
    g.printSCC(count,id);

    cout<<"following is id[]"<<endl;

    g.printID(id);





}