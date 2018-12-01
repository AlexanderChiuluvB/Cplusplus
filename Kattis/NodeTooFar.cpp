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


vector<int>visited;
vector<int>color;
int n;

void bfs(vector<vector<int>>&grid,int src,int TTL){
    queue<int>q;
    q.push(src);
    int qsize = 0;
    while(!q.empty()){
        if(qsize==0){
            qsize = q.size();
        }
        int top = q.front();
        q.pop();
        visited[top] = 1;
        for(auto v:grid[top]){
            if(!visited[v]){
                q.push(v);
            }
        }
        qsize--;
        if(qsize==0){
            TTL--;
        }
        if(TTL==0){
            break;
        }
    }

}


int main(){

    int NC;
    int t = 1;
    while(true){
        cin>>NC;
        if(NC==0){
            break;
        }
        map<int,int>mp;
        vector<vector<int>>grid(100);
        int idx=1;
        for(int i=1;i<=NC;i++){
            int from,to;
            cin>>from>>to;
            if(mp[from]==0)
                mp[from] = idx++;
            if(mp[to]==0)
                mp[to] = idx++;
            int fromidx = mp[from];
            int toidx = mp[to];
            grid[fromidx].push_back(toidx);
            grid[toidx].push_back(fromidx);
        }
        int start,TTL;
        int V = mp.size();
        while(true){
            cin>>start>>TTL;
            if(start==0&&TTL==0){
                break;
            }
            visited.assign(V+1,0);
            bfs(grid,mp[start],TTL+1);
            int count=0;
            for(int i=1;i<=V;i++){
                //cout<<t<<" "<<visited[i]<<" ";
                if(visited[i]==0&&i!=mp[start]){
                    count++;
                }
            }
            cout<<"Case "<<t<<": "<<count<<" nodes not reachable from node "<< start<<" with TTL = "<<TTL<<"."<<endl;
            t++;
        }
    }
}
