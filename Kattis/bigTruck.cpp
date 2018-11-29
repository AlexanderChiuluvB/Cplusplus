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
typedef pair<int,int> ip;
typedef pair<double,double> dp;
typedef pair<double,int>idp;
typedef tuple<int,int,int,int> iiii;
typedef vector<iiii> viiii;

unsigned int seed;



int main(){

    int N;
    cin>>N;
    vector<int> items(N+1);

    for(int i=1;i<=N;i++){
        cin>>items[i];
    }

    int E;
    cin>>E;
    vector<vector<int>> dist(N+1,vector<int>(N+1,INF));
    for(int i=1;i<=E;i++){
        int a,b,d;
        cin>>a>>b>>d;
        dist[a][b] = d;
        dist[b][a] = d;
    }

    vector<pair<int,int>> visited(N+1,{INF,INF});


    //pq.push({0,1});
    visited[1] = {0,items[1]};
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=1;i<=N;i++){
            if(visited[u].first+dist[u][i]<visited[i].first){
                visited[i].first = visited[u].first+dist[u][i];
                visited[i].second = visited[u].second+items[i];
                q.push(i);
            }

            else if(visited[u].first+dist[u][i]==visited[i].first&&visited[i].second<visited[u].second+items[i]){
                visited[i].first = visited[u].first+dist[u][i];
                visited[i].second = visited[u].second+items[i];
                q.push(i);
            }

        }


    }

    if(visited[N].first==INF){
        cout<<"impossible"<<endl;
    }
    else{
        cout<<visited[N].first<<" "<<visited[N].second<<endl;
    }
}
