#include <stdio.h>
#include <stdbool.h>
#include <bits/stdc++.h>
#define M 50
#define N 50
using namespace std;

//https://www.geeksforgeeks.org/dinics-algorithm-maximum-flow/


struct Edge {

    int to;
    unsigned long rev;//store index of reverse edge in adjacency
    int flow, cap;//cap is capacity
};

class Dinic {
    using AdjacencyList=vector< vector<Edge> >;

    bool bfs() {
        queue<int> q;
        q.push(source);
        fill(begin(levels), end(levels), -1);
        levels[source] = 0;
        while (!q.empty()) {
            const auto now = q.front(); q.pop();
            for (const auto& e : adjList[now]) {
                if (levels[e.to] == -1 && e.flow < e.cap) {
                    q.push(e.to);
                    levels[e.to] = levels[now] + 1;
                }
            }
        }
        return levels[sink] != -1;
    }

    //a dfs based function to send flow after BFS
//has figured out that there is a possible flow
//and constructed levels.This function called multiple times for a
//a single call of BFS
//flow: current flow sent by parent function call


    int dfs(int v, int flow) {
        if (flow == 0) return 0;
        if (v == sink) return flow;
        for (int & i = currentEdge[v]; i < (int) adjList[v].size(); ++i) {
            Edge& edge = adjList[v][i];
            if (levels[v] + 1 == levels[edge.to]) {
                const auto minimalFlow = dfs(edge.to, min(flow, edge.cap - edge.flow));
                if (minimalFlow > 0) {
                    //add flow to current edge
                    edge.flow += minimalFlow;
                    //subtract flow from reverse edge
                    adjList[edge.to][edge.rev].flow -= minimalFlow;
                    return minimalFlow;
                }
            }
        }
        return 0;
    }

    vector<int> levels, currentEdge;

public:

    int source, sink;
    AdjacencyList adjList;

    void AddEdge(int a, int b, int cap) {
        //ADJList动态变化，节省空间
        if (max(a, b) >= (int) adjList.size()) {
            adjList.resize(max(a, b) + 1);
            levels.resize(max(a, b) + 1);
            currentEdge.resize(max(a, b) + 1);
        }
        const auto rev_a = adjList[b].size();
        const auto rev_b = adjList[a].size();
        adjList[a].push_back({b, rev_a, 0, cap});
        adjList[b].push_back({a, rev_b, 0, 0});
    }

    int MaxFlow(int s, int t) {
        source = s;
        sink = t;
        int flow = 0;
        //augment the flow while there is path
        //from source to sink
        for (;;) {
            int m = bfs();
            if (!m) break;
            fill(begin(currentEdge), end(currentEdge), 0);
            while (int pushed = dfs(source, INT_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }

};

int main(){

    int n,m,s,t;
    cin>>n>>m>>s>>t;
    Dinic d;
    d.sink =s;
    d.source = t;
    vector<vector<int>>flow(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        //flow[u][v] = c;
        d.AddEdge(u,v,c);
    }
    cout<<n<<" "<<d.MaxFlow(s,t)<<" ";
    //SIZE is the number of edges used in the solution
    //
    int size = 0;
    vector<tuple<int,int,int>>ans;
    for(int i=0;i<n;i++){
        for(auto &e:d.adjList[i]){
            if(e.flow>0)
            {
                size++;
                ans.push_back({i,e.to,e.flow});
            }
        }
    }
    cout<<size<<endl;
    for(auto &t:ans){
        int from = get<0>(t);
        int to = get<1>(t);
        int f = get<2>(t);
        cout<<from<<" "<<to<<" "<<f<<endl;
    }

}


