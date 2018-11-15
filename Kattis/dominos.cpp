/* CS1010E Final Examination                  */
/* AY 2018/19 Semester 1                      */

#include <stdio.h>
#include <stdbool.h>
#include <bits/stdc++.h>
#define M 50
#define N 50


using namespace std;
#define INF 0x3f3f3f3f
vector<int>visited;

vector<vector<int>>grid;

void dfs(vector<vector<int>>&grid,int source,int &count){

    visited[source]=1;
    count++;
    //cout<<source<<count<<endl;
    for(auto v:grid[source]){
        if(!visited[v]){
            dfs(grid,v,count);
        }
    }
}


int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,l;
        cin>>n>>m>>l;
        grid.assign(n+1,vector<int>());
        visited.assign(n+1,0);
        while(m--){
            int from,to;
            cin>>from>>to;
            grid[from].push_back(to);
        }
        int count=0;
        while(l--){
            int hand;
            cin>>hand;
            if(!visited[hand]){
                dfs(grid,hand,count);
            }
        }
        cout<<count<<endl;
    }
}
