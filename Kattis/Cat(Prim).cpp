
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
typedef tuple<int,int,int,int> iiii;
typedef vector<iiii> viiii;

vector<vector<int>>visit;
vector<vector<int>>height;
int h,w;
vector<ip> mv({{0,-1},{0,1},{1,0},{-1,0}});
bool onBoard(int x,int y){
    if(x>=0&&y>=0&&x<h&&y<w)
        return true;
    return false;
}


//https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
int main(){

    int T;
    cin>>T;
    while(T--) {
        int milk,catNum;
        cin>>milk>>catNum;
        priority_queue<ip,vector<ip>,greater<ip>> pq;
        int src = 0;

        vector<vector<ip>> vec(catNum,vector<ip>(catNum));
        vector<int> key(catNum,INF);
        vector<int> parent(catNum,-1);
        vector<bool> inMST;
        inMST.assign(catNum,false);

        for(int i=0;i<catNum*(catNum-1)/2;i++){
            int from,to,weight;
            cin>>from>>to>>weight;
            vec[from].push_back(make_pair(to,weight));
            vec[to].push_back(make_pair(from,weight));
        }

        int w = 0;

        pq.push(make_pair(0,src));
        key[src] = 0;
        while(!pq.empty()){

            int u = pq.top().second;
            //w+=pq.top().first;
            pq.pop();

            //The algorithm discussed here can be modified so that decrease key is never required.
            //The idea is, not to insert all vertices in priority queue,
            //but only those which are not MST and have been visited through a vertex that has included in MST.

            inMST[u] = true;
            for(auto p:vec[u]){
                int v = p.first;
                int weight = p.second;

                if(inMST[v]==false&&key[v]>weight){
                    key[v] = weight;
                    pq.push(make_pair(key[v],v));
                    parent[v] = u;
                }
            }
        }
        for(int i=1;i<catNum;i++){
            int start = parent[i];
            int end = i;
            for(auto p:vec[start]){
                if(p.first==end){
                    w+=p.second;
                    break;
                }
            }

        }
        //cout<<w<<endl;
        if(milk-catNum-w>=0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;

    }
}

