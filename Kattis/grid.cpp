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


vector<vector<int>> visited;

vector<vector<int>> dist;
int N,M;


void dfs(vector<vector<int>>&vec,int x,int y,int &count,int &minCount){

    if(x<0||y<0||x>=vec.size()||y>=vec[0].size()||visited[x][y]){
        return;
    }
    if(x==N-1&&y==M-1){
        if(count<minCount)
            minCount = count;
        return;
    }
    visited[x][y] = 1;
    count++;
    int step = vec[x][y];
    dfs(vec,x,y-step,count,minCount);
    dfs(vec,x,y+step,count,minCount);
    dfs(vec,x-step,y,count,minCount);
    dfs(vec,x+step,y,count,minCount);

}


bool inGraph(int x,int y){

    if(x>=0&&y>=0&&x<N&&y<M)
        return true;
    return false;


}

void bfs(vector<vector<int>>&vec,int x,int y) {

    queue<pair<int,int>>q;
    q.push(make_pair(x,y));
    dist[x][y] = 0;
    while(!q.empty()){
        auto pa = q.front();
        q.pop();
        int xx = pa.first;
        int yy = pa.second;
        int step  = vec[xx][yy];
        if(inGraph(xx+step,yy)){
            if(dist[xx+step][yy]>dist[xx][yy]+1){
                dist[xx+step][yy] = dist[xx][yy]+1;
                q.push(make_pair(xx+step,yy));
            }
        }
        if(inGraph(xx-step,yy)){
            if(dist[xx-step][yy]>dist[xx][yy]+1){
                dist[xx-step][yy] = dist[xx][yy]+1;
                q.push(make_pair(xx-step,yy));
            }
        }
        if(inGraph(xx,yy-step)){
            if(dist[xx][yy-step]>dist[xx][yy]+1){
                dist[xx][yy-step] = dist[xx][yy]+1;
                q.push(make_pair(xx,yy-step));
            }
        }
        if(inGraph(xx,yy+step)){
            if(dist[xx][yy+step]>dist[xx][yy]+1){
                dist[xx][yy+step] = dist[xx][yy]+1;
                q.push(make_pair(xx,yy+step));
            }
        }

    }
}

int main(){
    int c=0;
    cin>>N>>M;
    vector<vector<int>> vec;
    vec.assign(N,vector<int>(M,0));
    dist.assign(N,vector<int>(M,INF));
    for (int i = 0; i < N; ++i) {
        for(int j=0;j<M;j++){
            char temp;
            cin>>temp;
            vec [i] [j] = temp-'0';
        }
    }
    int count=0;

    bfs(vec,0,0);
    if(dist[N-1][M-1]==INF)
        cout<<-1<<endl;
    else
        cout<<dist[N-1][M-1]<<endl;
}