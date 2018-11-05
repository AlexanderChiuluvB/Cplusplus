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
    cin>>N;
    while(N--){
        int M;
        cin>>M;
        list<int>*adj = new list<int>[M];

        visited.assign(M,0);

        int R;
        cin>>R;
        while(R--){
            int from,to;
            cin>>from>>to;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        int count=0;
        for(int i=0;i<M;i++){
            if(!visited[i]){
                count++;
                dfs(adj,i);
            }
        }
        cout<<count-1<<endl;
    }


}