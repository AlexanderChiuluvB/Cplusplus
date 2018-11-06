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
vector<int> visited;
vector<double> dist;
map<int,int>leaveNeighbour;

void dfs(list<int>*&adj,int s){

    visited[s] = 1;
    for(auto p:adj[s]) {
        if(!visited[p]){
            leaveNeighbour[p]++;
            int psize = adj[p].size();
            if(psize%2==0&& leaveNeighbour[p]>=psize/2){
               dfs(adj,p);
            }
            else if(psize%2!=0&&leaveNeighbour[p]>psize/2){
                dfs(adj,p);
            }
        }
    }


}

void dijkstra(list<pair<int,double>>*adj,int source){
    dist[source] = 1;
    visited[source] = 1;
    priority_queue<pair<double,int>,vector<pair<double,int>> >pq;
    pq.push(make_pair(0,source));
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int vertex = top.second;
        for(auto pair:adj[vertex]){
            int v = pair.first;
            double w = pair.second;
            if(dist[v]<dist[vertex]*w) {
                dist[v] = dist[vertex] * w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}


int main(){

   int N,M;
   cin>>N>>M;
   while(N!=0&&M!=0){
        list<pair<int,double>>*adj = new list<pair<int,double>>[N];
        dist.assign(N,-1);
        visited.assign(N,0);
        for(int i=0;i<M;i++){
            int from,to;double weight;
            cin>>from>>to>>weight;
            adj[from].push_back(make_pair(to,weight));
            adj[to].push_back(make_pair(from,weight));
        }
        dijkstra(adj,0);
        cout<<fixed<<setprecision(4)<<dist[N-1]<<endl;
        cin>>N>>M;
   }
}