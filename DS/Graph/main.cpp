#include <stdio.h>
#include <stdbool.h>
#include <bits/stdc++.h>
#define M 50
#define N 50
using namespace std;

//https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/


//return true if there is a path from source 's' to sink 't' in residual graph,
//also fills parent[] to store the path

#define V 505
int n;
int graph[V][V];
int rGraph[V][V];
int parent[V];
int f[V];
int m,s,t,u,v,w,path_flow;


//Using BFS, we can find out if there is a path from source to sink.
// BFS also builds parent[] array. Using the parent[] array,
// we traverse through the found path and find possible flow through this path
// by finding minimum residual capacity along the path.
//We later add the found path flow to overall flow.
int bfs(int s,int t){

    bool visited[n];
    memset(visited,0,sizeof(visited));


    queue<int>q;
    q.push(s);
    parent[s] = -1;
    f[s] = INT_MAX;
    while(!q.empty()){

        int u = q.front();
        q.pop();

        for(int v=0;v<V;v++){
            if(visited[v]==false&&rGraph[u][v]>0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                f[v] = min(f[u],rGraph[u][v]);
            }
        }

    }
    return (visited[t]==true?f[t]:0);

}

void fordFulkerson(int s,int t){

    int u,v;


    //create the residual graph given the original graph


    while(path_flow = bfs(s,t)){

        //find minimun residual capacity
        //path filled by BFS.

        //update residual capacities of the edges and reverse edges
        for(v=t;v!=s;v = parent[v]){

            u = parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }

        //max_flow+=path_flow;
    }

    //above is the usual ford-fukerson

    int total = 0;
    stack<int>ss;
    ss.push(s);
    bool marked[n];
    memset(marked,false,sizeof(marked));
    while(!ss.empty()){
        int i = ss.top();
        ss.pop();
        marked[i] = true;
        total++;
        for(int j=0;j<n;j++){
            if(rGraph[i][j]>0&&!marked[j]){
                marked[j] = true;
                ss.push(j);
            }
        }
    }
    cout<<total<<endl;
    for(int i=0;i<n;i++){
        if(marked[i]){
            cout<<i<<endl;
        }
    }


    //return max_flow;
}

int main(){
    cin>>n>>m>>s>>t;
    memset(graph,0,sizeof(graph));
    memset(rGraph,0,sizeof(rGraph));
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        graph[u][v]=rGraph[u][v]= w;
    }
    fordFulkerson(s,t);
    return 0;
}