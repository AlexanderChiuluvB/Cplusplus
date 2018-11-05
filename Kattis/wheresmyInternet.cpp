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

void dfs(list<int>*&adj,int s){

    visited[s] = 1;
    for(auto p:adj[s]){
        if(!visited[p])
            dfs(adj,p);
    }
}

int main(){
    int c=0;
    int N;
    cin>>N>>M;
    visited.assign(N+1,0);
    list<int>*adj = new list<int>[N+1];

    while(M--) {
        int from,to;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    dfs(adj,1);
    bool connected = true;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            connected = false;
            cout << i << endl;
        }
    }
    if(connected)
        cout<<"Connected"<<endl;
}