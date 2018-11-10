
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

#include <unordered_set>

#include <unordered_map>

#include <deque>

using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int,int> ip;

int num=0;
void dijkstra(vector<vector<pair<int,int>>> &adj,int source,vector<int>&ways,vector<int> &dist){

    dist[source] = 0;
    set<ip>pq;
    pq.insert(make_pair(0,source));
    ways[source] = 1;
    while(!pq.empty()){
        auto top= *pq.begin();
        pq.erase(top);
        for(auto p:adj[top.second]){
            int v =p.first;
            int w =p.second;
            if(dist[v]>dist[top.second]+w){
                pq.erase(make_pair(dist[v],v));
                dist[v] = dist[top.second]+w;
                ways[v] = ways[top.second];
                pq.insert(make_pair(dist[v],v));
            }
            else if(dist[v]==dist[top.second]+w){
                ways[v]+=ways[top.second];
            }

        }
    }
}

int main() {
    int V,E;
    cin>>V>>E;
    vector<vector<pair<int,int>>>adj(V+1);
    vector<int> dist;
    dist.assign(V+1,INF);
    vector<int> ways;
    ways.assign(V+1,0);
    for(int i=0;i<E;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        adj[from].push_back({to,weight});
    }
    int S,T;
    cin>>S>>T;
    //ways[S] = 0;
    dijkstra(adj,S,ways,dist);
    cout<<ways[T]<<endl;
}


