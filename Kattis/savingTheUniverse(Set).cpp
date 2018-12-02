//
// Created by AlexanderChiu on 2018/12/2.
//

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
#include <math.h>
#include <deque>

using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int,int> ip;
typedef pair<double,double> dp;
typedef pair<int,double>idp;
typedef tuple<int,int,int,int> iiii;
typedef vector<iiii> viiii;

unsigned int seed;


vector<int>color;

vector<int>dist;
void dijkstra(vector<vector<ip>>&adjList,int src){
    priority_queue<ip,vector<ip>,greater<ip>>pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int u = top.second;
        for(auto p:adjList[u]){
            int v = p.first;
            int weight = p.second;
            if(dist[v]>dist[u]+weight){
                dist[v] = dist[u] +weight;
                pq.push({dist[v],v});
            }
        }
    }
}
int r,c;
vector<ip>mv({{1,0},{-1,0},{0,-1},{0,1}});
vector<vector<char>>adjList;
bool onBorder(int x,int y){
    if(x>=1&&y>=1&&x<=r&&y<=c)
        return true;
    return false;
}

bool exit(int x,int y){
    if(adjList[x][y]=='D'){
        for(int i=0;i<4;i++){
            int xx = x+mv[i].first;
            int yy = y+mv[i].second;
            if(!onBorder(xx,yy)){
                return true;
            }
        }
    }
    return false;
}
vector<vector<int>>superPower;
vector<double>ant;
double ans = -INF;
void bfs(vector<vector<idp>>&adjList,int src){

    queue<int>q;
    q.push(src);
    double dis = ant[src];
    //cout<<dis<<endl;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto p:adjList[top]){
            int v = p.first;
            //cout<<top<<"->"<<v<<endl;
            if(superPower[top][v]){
                dis=pow(dis,0.5);
                //cout<<dis<<endl;
            }
            //cout<<p.second;
            dis = dis/(p.second);
            //cout<<dis<<endl;
            q.push(v);
        }
    }
    ans = max(ans,dis);
}

int main(){

    //int r,c;

    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int N;
        cin>>N;
        int ans = 0;
        //int count=0;
        map<string,int>mp;
        string buff;
        getline(cin,buff);
        for(int i=1;i<=N;i++){
            string name;
            getline(cin,name);
            mp[name] = i;
            //cout<<name<<endl;
        }
        int Q;
        cin>>Q;
        set<int>st;
        getline(cin,buff);
        for(int i=0;i<Q;i++){
            string name;
            getline(cin,name);
            st.insert(mp[name]);
            //cout<<count<<" "<<st.size()<<endl;
            if(st.size()==N){
                ans++;
                st.clear();
                st.insert(mp[name]);
            }
        }
        cout<<"Case #"<<t<<":"<<" "<<ans<<endl;

    }


}