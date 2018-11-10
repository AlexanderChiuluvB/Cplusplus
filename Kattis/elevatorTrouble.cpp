
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

typedef pair<int,int>ip;

int N,M;

vector<int> visited;

vector<double> dist;

map<int,int>leaveNeighbour;





unordered_map<string,vector<string>> adj;

unordered_map<string,int> numList;

unordered_map<string,int> visitList;

vector<string> vec;



void bfs( unordered_map<string,vector<string>>&adj,const string &source){



    queue<string>q;

    q.push(source);

    numList[source] = 0;
    visitList[source] = 1;
    while(!q.empty()){
        string top = q.front();
        q.pop();

        for(auto &name:adj[top]){
            if(!visitList[name]) {
                visitList[name] = 1;
                numList[name] = numList[top] + 1;
                q.push(name);

            }

        }

    }

}

bool isPrime(int n){
    for(int i=2;i<n/2;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
map<int,int>mp;

void bfs(int num1,int num2,int &count){

    if(num1==num2){
        return;
    }



}


int main(){

   int f,s,g,u,d;
   cin>>f>>s>>g>>u>>d;
   vector<int>level(f+1,INF);
   queue<int>q;
   q.push(s);
   level[s]=0;
   while(!q.empty()){
       int cur =q.front();
       q.pop();

       if(cur+u<=f&&level[cur+u]>level[cur]+1){
           level[cur+u] = level[cur]+1;
           q.push(cur+u);
       }
       if(cur-d>=1&&level[cur-d]>level[cur]+1){
           level[cur-d] = level[cur]+1;
           q.push(cur-d);
       }

   }

   if(level[g]==INF){
       cout<<"use the stairs"<<endl;
       return 0;
   }
   else
       cout<<level[g]<<endl;

}

