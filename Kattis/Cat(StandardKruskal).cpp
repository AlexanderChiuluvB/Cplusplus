
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


//Kruskal

struct edge{
    int from,to,weight;
};

bool cmp(edge& e1,edge&e2){
    return e1.weight<e2.weight;
}

int find(vector<int>&vec,int d){
    if(vec[d]==-1)
        return d;
    return vec[d] = find(vec,vec[d]);
}

void join(vector<int>&vec,int x,int y){

    x = find(vec,x);
    y = find(vec,y);
    if(x==y)
        return;
    vec[x] = y;
}

int main(){

    int T;
    cin>>T;
    while(T--) {
        int milk,catNum;
        cin>>milk>>catNum;
        vector<edge>vec(catNum*(catNum-1)/2);
        for(int i=0;i<catNum*(catNum-1)/2;i++){
            int from,to,weight;
            cin>>from>>to>>weight;

            edge newEDGE;
            newEDGE.weight = weight;
            newEDGE.from = from;
            newEDGE.to = to;

            vec.push_back(newEDGE);
        }

        sort(vec.begin(),vec.end(),cmp);

        int w = 0;

        vector<int>d(catNum,-1);

        for(auto edge:vec){
            //union - find for cycle detection
            //if find(from)==find(to) ,means the edge's from and to belongs to
            //a connected component
            if(find(d,edge.from)!=find(d,edge.to)){
                join(d,edge.from,edge.to);
                w+=edge.weight;
            }
        }
        if(milk-catNum-w>=0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;

    }
}

