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

   int N;
   cin>>N;
   map<set<int>,int>mp;
   auto resultit = mp.begin();
   for(int j=0;j<N;j++){
       set<int> temp;
       for(int i=0;i<5;i++){
           int num;
           cin>>num;
           temp.insert(num);
       }
       mp[temp]++;
   }
    auto it = mp.begin();
    int max = 0;
    for(it;it!=mp.end();it++){
        if(it->second>max){
            max = it->second;
        }
    }
    int count=0;
    it = mp.begin();
    for(it;it!=mp.end();it++){
        if(it->second==max)
            count+=it->second;
    }
    cout<<count<<endl;
}