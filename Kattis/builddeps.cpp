
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

int row,col;
vector<vector<char>> vec;
vector<vector<int>> dist;
vector<vector<int>> visit;

void fast() {

    ios::sync_with_stdio(false);

    cin.tie(NULL); cout.tie(NULL);

}


void split(vector<string>&ans,string &s){
    ans.push_back("");
    for(auto ch:s){
        if(ch==' ')
            ans.push_back("");
        else
            ans.back().push_back(ch);
    }
}


int main() {

    int N;
    cin>>N;
    map<string,int>id;
    vector<vector<int>> adj(N);
    map<int,string> rev;
    cin.ignore();
    int idx = 0;
    for(int i=0;i<N;i++){
        string line;
        getline(cin,line);
        vector<string> v;
        split(v,line);
        v[0].pop_back();
        for(auto name:v){
            if(id.find(name)==id.end())
            {
                id[name] = idx;
                rev[idx] = name;
                idx++;
            }
        }
        int n = id[v[0]];
        for(int j=1;j<v.size();j++){
            adj[id[v[j]]].push_back(n);
        }
    }

    string start;
    getline(cin,start);
    int startidx = id[start];


    vector<int> inDegree(N+1,0);
    for(int i=0;i<N;i++){
        for(auto j:adj[i]){
            inDegree[j]++;
        }
    }

    queue<int>q;
    for(int i=0;i<N;i++){
        if(inDegree[i]==0&&i!=startidx){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto j:adj[top]){
            inDegree[j]--;
            if(inDegree[j]==0&&j!=startidx){
                q.push(j);
            }
        }
    }
    q.push(startidx);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        cout<<rev[top]<<endl;
        for(auto j:adj[top]){
            inDegree[j]--;
            if(inDegree[j]==0){
                q.push(j);
            }
        }
    }

}


