#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <cmath>
#include <queue>

using namespace std;
#define INF 0x3f3f3f3f


int c;
vector<int>res;
vector<int>cur;
vector<int>visited;
bool first;
unordered_map<int,set<int>>mp;
unordered_map<string,int>c2ID;
unordered_map<int,string>ID2c;
int ways;

void dfs(int p){
    if(p==c){
        ways++;
        if(!first){
            for(int i=0;i<c;i++){
                res[i] = cur[i];
            }
            first = true;
        }
    }

    for(int i=0;i<c;i++){
        if(visited[i])continue;
        if(cur.empty()||mp[cur.back()].find(i)==mp[cur.back()].end()){
            cur.push_back(i);
            visited[i] = 1;
            dfs(p+1);
            cur.pop_back();
            visited[i] = 0;
        }
    }

}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ways = 0;
        first = false;
        cin>>c;
        res.resize(c);
        visited.resize(c,0);
        cur.clear();
        mp.clear();
        c2ID.clear();
        ID2c.clear();

        string color;
        for(int i=0;i<c;i++){
            cin>>color;
            c2ID[color]=i;
            ID2c[i] = color;
        }

        int M;
        cin>>M;

        while(M--){
            string colorA,colorB;
            cin>>colorA>>colorB;
            mp[c2ID[colorA]].insert(c2ID[colorB]);
            mp[c2ID[colorB]].insert(c2ID[colorA]);
        }


        dfs(0);

        cout<<ways<<endl;
        for(int i=0;i<res.size();i++){
            cout<<ID2c[res[i]]<<" ";
        }
        cout<<endl;


    }
}
