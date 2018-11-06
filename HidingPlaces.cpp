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

map<pair<int,int>,int>mp;
void bfs(vector<vector<int>>&vec,int r,int c){

    queue<pair<int,int>>q;
    q.push(make_pair(r,c));
    vector<int> row({2,2,-2,-2,1,1,-1,-1});
    vector<int> col({1,-1,1,-1,2,-2,-2,2});
    while(!q.empty()){
        auto pair = q.front();
        int y = pair.first;
        int x = pair.second;
        vec[y][x] = 1;
        q.pop();
        for(int i=0;i<8;i++){
            int xx = x+col[i];
            int yy = y+row[i];
            if(xx>=1&&yy>=1&&xx<=8&&yy<=8&&vec[yy][xx]==0){
                 q.push(make_pair(yy,xx));
                 mp[make_pair(xx,yy)] = mp[make_pair(x,y)]+1;
            }
        }
    }
}


struct cmp{
    //xx,yy->col,row
    bool operator()(pair<int,int>&A,pair<int,int>&B){
        if(A.second!=B.second){
            return A.second>B.second;
        }
        return A.first<B.first;
    }
};

int main(){

    int T;
    cin>>T;
    while(T--){
        vector<vector<int>> vec;
        vector<pair<int,int>> temp;
        vec.assign(9,vector<int>(9,0));
        mp.clear();
        string command;
        cin>>command;
        int col = command[0]-'a'+1;
        //cout<<col<<endl;
        int row = stoi(command.substr(1,2));
        //cout<<row<<endl;
        bfs(vec,row,col);
        int maxCount = 0;
        for(auto p:mp){
            maxCount = max(maxCount,p.second);
        }
        for(auto p:mp){
            if(p.second==maxCount){
                auto pair = p.first;
                int xx = pair.first;
                int yy = pair.second;
                temp.push_back(make_pair(xx,yy));
            }
        }
        sort(temp.begin(),temp.end(),cmp());
        cout<<maxCount<<" ";
        for(auto p:temp){
            int coll = p.first;
            int roww = p.second;
            char t = (char)(p.first-1+'a');
            cout<<t<<roww<<" ";
        }
        cout<<endl;
    }
}