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
typedef pair<int,int>ip;
int N,M;
vector<int> visited;

void dfs(list<int>*&adj,int s,int &count,int &maxCount){

    visited[s] = 1;
    count++;
    for(auto p:adj[s]) {
        if(!visited[p]){
            dfs(adj,p,count,maxCount);
        }
    }
    if(count>maxCount)
        maxCount = count;

}

int main(){
    int c=0;
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        visited.assign(n+1,0);
        list<int>*adj = new list<int>[n+1];
        while(m--){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        int maxCount = 0;
        int count=0;
        for(int i=1;i<=n;i++){

            if(!visited[i]){
                dfs(adj,i,count,maxCount);
            }
        }
        //maxCount is num of nodes, we need edge so -1
        cout<<maxCount-1<<endl;
    }


}