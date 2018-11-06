#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <stack>
#include <iterator>
#include <string.h>
#include <sstream>
#include <string>
#include <queue>
#include <list>
#include <iomanip>
#include <unordered_map>
#include <deque>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int>ip;
int N,M;
//vector<int> visited;
vector<int> dist;
map<int,int>leaveNeighbour;
unordered_map<string,int>visited;
list<string> result;
map<string,string> route;

void dijkstra(list<ip>*adj,int source){
    dist[source] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<ip>>pq;
    pq.push(make_pair(0,source));
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int vertex = top.second;
        for(auto pair:adj[vertex]){
            int v = pair.first;
            int w = pair.second;
            if(dist[v]>dist[vertex]+w) {
                dist[v] = dist[vertex]+w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}

void dfs(map<string,list<string>> &adj,string &source,string &dest){

    visited[source]=1;
    if(source==dest)
        return;
    for(auto p:adj[source]){

        if(visited[p]==0){
            result.push_back(p);
            dfs(adj,p,dest);
        }


    }
}


void bfs(map<string,list<string>> &adj,string &source){

    queue<string>q;
    q.push(source);
    while(!q.empty()){
        string top = q.front();
        q.pop();
        for(auto &target:adj[top]){
            if (route.count(target)==0){
                q.push(target);
                route[target] = top;
            }
        }
    }
}

int main(){

    int N,M,Q,S;
    cin>>N;
    //list<string>*adj = new list<string>[N+1];
    map<string,list<string>> adj;
    getchar();
    for(int i=0;i<N;i++){
        string line,from,to;
        getline(cin,line);
        stringstream ss(line);
        getline(ss,from,' ');
        while(getline(ss,to,' ')){
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

    }
    string src,dest;
    cin>>src>>dest;
    route[src]="NULL";

    bfs(adj,src);
    vector<string> result;
    if(route.count(dest)==0)
        cout<<"no route found"<<endl;
    else{
        while(dest!="NULL"){
            result.push_back(dest);
            dest = route[dest];
        }
    }
    for(auto it = result.rbegin();it!=result.rend();it++){
        cout<<*it<<" ";
    }

}