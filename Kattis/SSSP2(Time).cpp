
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
typedef tuple<int,int,int,int> iiii;
typedef vector<iiii> viiii;

vector<int>dist;
void dijkstra(vector<viiii>&adj,int s){

    dist[s] = 0;
    priority_queue<ip,vector<ip>,greater<ip>> pq;
    pq.push(make_pair(0,s));

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int v = top.second;

        for(auto p:adj[v]){
            int to = get<0>(p);
            int beginTime = get<1>(p);
            int interval = get<2>(p);
            int cost = get<3>(p);

            if(top.first<=beginTime&&dist[to]>beginTime+cost){
                dist[to] = beginTime+cost;
                pq.push(make_pair(dist[to],to));
            }
            else if(interval>0){
                int watingTime = interval - (top.first-beginTime)%interval;
                if(watingTime ==interval)
                    watingTime = 0;
                if(dist[to]>top.first+watingTime+cost){
                    dist[to] = top.first+watingTime+cost;
                    pq.push(make_pair(dist[to],to));
                }
            }
        }
    }
}


int main(){


    int n,m,q,s;
    while(true){
        cin>>n>>m>>q>>s;
        if(n==0)
            break;
        vector<viiii> adj(n);
        for(int i=0;i<m;i++){
            int u,v,t,P,d;
            cin>>u>>v>>t>>P>>d;
            adj[u].push_back(make_tuple(v,t,P,d));
        }
        dist.assign(n,INF);
        dijkstra(adj,s);
        while(q--){
            int num;
            cin>>num;
            if(dist[num]==INF)
                cout<<"Impossible"<<endl;
            else
                cout<<dist[num]<<endl;
        }
        cout<<endl;

    }
}

