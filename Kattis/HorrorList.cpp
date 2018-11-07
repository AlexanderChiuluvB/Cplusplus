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
#include <unordered_map>
#include <deque>
using namespace std;
#define INF 0x3f3f3f3f
vector<int> dist;




void bfs(map<int,vector<int>>adj,int source){

    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto p:adj[top]){
            if(dist[p]>dist[top]+1) {
                dist[p] = dist[top] + 1;
                q.push(p);
            }
        }

    }

}



int main(){
    int c=0;

    int N,H,L;
    cin>>N>>H>>L;
    dist.assign(10001,INF);
    //vector<vector<int>> adj;
    map<int,vector<int>> adj;
    //adj.assign(N+1,vector<int>());
    vector<int> horrorMovies;
    while(H--){
        int horrorId;
        cin>>horrorId;
        horrorMovies.push_back(horrorId);
        dist[horrorId] = 0;
    }
    while(L--){
        int from,to;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for(int i=0;i<horrorMovies.size();i++){
        bfs(adj,horrorMovies[i]);
    }
    int max  =0;
    int maxIndex = 0;
    for(int i=0;i<N;i++){
        if(dist[i]>max){
            max = dist[i];
            maxIndex = i;
        }
    }
    if(horrorMovies.empty())
        cout<<0<<endl;
    else
        cout<<maxIndex<<endl;



}