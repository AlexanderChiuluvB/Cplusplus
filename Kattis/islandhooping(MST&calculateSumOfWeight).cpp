
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

double dis(double x1,double y1,double x2,double y2){
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
int main(){

    int T;
    cin>>T;

    while(T--){
        int N;
        cin>>N;
        vector<vector<pair<int,double>>>mtx(N);
        vector<dp> point;
        vector<double> key(N,INF);
        vector<bool> inMST(N,false);
        vector<int> parent(N,-1);
        for(int i=0;i<N;i++){
            double x,y;
            cin>>x>>y;
            point.push_back(make_pair(x,y));
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j){
                    mtx[i].push_back(make_pair(j,dis(point[i].first,point[i].second,
                    point[j].first,point[j].second)));
                }
            }
        }

        priority_queue<idp,vector<idp>,greater<idp>> pq;
        pq.push(make_pair(0,0));
        parent[0] = -1;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;
            for(auto p:mtx[u]){
                int v = p.first;
                double weight = p.second;

                if(inMST[v]==false && key[v]>weight){
                    pq.push(make_pair(weight,v));
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }
        double result=0;
        for(int i=1;i<N;i++){
            int start = parent[i];
            int end = i;
            for(auto p:mtx[start]){
                if(p.first ==end){
                    result+=p.second;
                    break;
                }
            }
        }
        cout<<fixed;
        cout.precision(4);
        cout<<result<<endl;
    }
}

