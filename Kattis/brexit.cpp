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

int main(){

    int C,P,X,L;
    cin>>C>>P>>X>>L;
    visited.assign(C+1,0);
    list<int>*adj = new list<int>[C+1];
    while(P--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(adj,L);
    if(visited[X]){
        cout<<"leave"<<endl;
    }
    else{
        cout<<"stay"<<endl;
    }

}