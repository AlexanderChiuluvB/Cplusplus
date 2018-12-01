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
typedef pair<double,int>idp;
typedef tuple<int,int,int,int> iiii;
typedef vector<iiii> viiii;

unsigned int seed;



double distance(int x1,int y1,int x2,int y2){
    return (pow(x1-x2,2)+pow(y1-y2,2));
}

int N;
bool onBoard(int x,int y){
    if(x>=0&&x<N&&y>=0&&y<N)
        return true;
    return false;
}
vector<ip>mv({{1,0},{-1,0},{0,1},{0,-1}});
void dfs(vector<vector<char>>&mtx,int x,int y){
    mtx[x][y]='F';
   // int size = mtx.size();
    for(int i=0;i<N;i++){
        int xx = x+mv[i].first;
        int yy = y+mv[i].second;
        if(onBoard(xx,yy)&&(mtx[xx][yy]=='x'||mtx[xx][yy]=='@')){
            dfs(mtx,xx,yy);
        }
    }
}

vector<int>colour;

bool checker(vector<vector<int>>&AL,int src,bool &result){
    colour[src] = 1;
    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto v:AL[top]){
            if(colour[v]==-1){
                colour[v] = 1-colour[top];
                q.push(v);
            }
            else if(colour[top]==colour[v]){
                result = false;
            }
        }
    }
    return result;
}



int n;
vector<int> status;
vector<int> visited;
void bfs(vector<vector<int>>&mtx,int src){

    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        visited[top] = 1;
        for(auto v:mtx[top]){
            if(status[v]==-1&&!visited[v]){
                status[v] = 1-status[top];
                q.push(v);
            }
        }
    }
}

int main(){

    int m;
    cin>>n>>m;
    vector<vector<int>> mtx(n+1);
    for(int i=0;i<m;i++){
        int from,to;
        cin>>from>>to;
        mtx[from].push_back(to);
        mtx[to].push_back(from);
    }
    bool can = true;
    status.assign(n+1,-1);
    visited.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(mtx[i].empty()){
            can = false;
            break;
        }
        if(!visited[i]){
            status[i] = 1;
            bfs(mtx,i);
        }
    }


    for(int i=1;i<=n;i++){
        bool valid = false;
        if(status[i]==1){
            for(auto v:mtx[i]){
                if(status[v]==0){
                    valid = true;
                    break;
                }
            }
        }
        else{
            for(auto v:mtx[i]){
                if(status[v]==1){
                    valid = true;
                    break;
                }
            }
        }
        if(!valid) {
            can = false;
            break;
        }
    }
    if(!can){
        cout<<"Impossible"<<endl;
    }else{
        for(int i=1;i<=n;i++){
            if(status[i]==0){
                cout<<"house ";
            }
            else{
                cout<<"pub ";
            }
        }
        cout<<endl;
    }
}