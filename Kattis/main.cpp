#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct edge{
    int from;
    int to;
    int weight;
};

typedef pair<int,int> ip;
#define INF 0x3f3f3f3f

void dijkstra(vector<vector<ip>>&adj,vector<int>&dist,int source){

    priority_queue<ip,vector<ip>,greater<ip>> q;
    q.push({0,source});
    dist[source] = 0;
    while(!q.empty()){
        auto top = q.top();
        q.pop();
        int u = top.second;
        for(auto p:adj[u]){
            int v = p.first;
            int weight = p.second;
            if(dist[v]==INF||dist[v]>dist[u]+weight){
                dist[v] = dist[u]+weight;
                q.push(make_pair(dist[v],v));
            }
        }
    }
}

int main(){

    int P,T;
    cin>>P>>T;
    vector<vector<ip>> adj(P);
    vector<vector<ip>> parent(P);
    vector<int>distStart(P,INF);
    vector<int>distEnd(P,INF);
    vector<tuple<int,int,int>>edgeVec;

    for(int i=0;i<T;i++){
        int from,to,w;
        cin>>from>>to>>w;
        edgeVec.push_back(make_tuple(from,to,w));
        adj[from].push_back(make_pair(to,w));
        adj[to].push_back(make_pair(from,w));
    }

    dijkstra(adj,distStart,0);
    dijkstra(adj,distEnd,P-1);

    int shortestPath = distStart[P-1];
    int ans=0;
    for(int i=0;i<T;i++){
        int from = get<0>(edgeVec[i]);
        int to = get<1>(edgeVec[i]);
        int weight = get<2>(edgeVec[i]);

        if(distStart[to]+distEnd[from]+weight==shortestPath||
        distStart[from]+distEnd[to]+weight==shortestPath){
            ans+=weight;
        }

    }

    cout<<ans*2;

    return 0;
}