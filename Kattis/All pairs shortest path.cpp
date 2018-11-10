
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

int row,col;
vector<vector<char>> vec;
vector<vector<int>> dist;
vector<vector<int>> visit;
bool cornorDoor(int x,int y){
    if(vec[x][y]=='D'){
        if(x-1<0||x+1>=row||y-1<0||y+1>=col)
            return true;
    }
    return false;
}
bool inGraph(int x,int y){
    if(x>=0&&x<row&&y>=0&&y<col)
        return true;
    return false;
}

struct edge{

    int u,v;
    edge(int uu,int vv){
        u = uu;
        v = vv;
    }
    bool operator <(edge e)const{
        return v>e.v;
    }


};



int main() {

    int n,m,q;
    while(true){
        cin>>n>>m>>q;
        if(n==0)
            break;
        vector<pair<edge,int>>adj;
        vector<vector<int>> result;
        result.assign(n,vector<int>(n,0));
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj.push_back(make_pair(edge(u,v),w));
        }

        for(int i=0;i<n;i++){
           vector<int> dist;
           dist.assign(n+1,INF);
           dist[i] = 0;
            for(int j=0;j<n-1;j++){
                for(auto p:adj){
                    int uu = p.first.u;
                    int vv = p.first.v;
                    int ww = p.second;
                    if(dist[vv]>dist[uu]+ww&&dist[uu]!=INF){
                        dist[vv] = dist[uu]+ww;
                    }
                }
            }
            for(int j=0;j<n;j++){
                for(auto p:adj){
                    int uu = p.first.u;
                    int vv = p.first.v;
                    int ww = p.second;
                    if(dist[vv]>dist[uu]+ww&&dist[uu]!=INF){
                        dist[vv] = -INF;
                    }
                }
            }
            for(int j=0;j<n;j++){
                result[i][j]=dist[j];
            }
        }

        for(int i=0;i<q;i++){
            int s,e;
            cin>>s>>e;
            if(result[s][e]==INF)
                cout<<"Impossible"<<endl;
            else if(result[s][e]==-INF)
                cout<<"-Infinity"<<endl;
            else
                cout<<result[s][e]<<endl;
        }


        cout<<endl;
    }
}


