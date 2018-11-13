#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct edge{
    int from;
    int to;
    int weight;
};

bool cmp(edge&A, edge&B){
    return A.weight<B.weight;
}
int find(vector<int>&d,int x){
    if(d[x]<0)
        return x;
    return d[x] = find(d,d[x]);
}

void join(vector<int>&d,int x,int y){

    x = find(d,x);
    y = find(d,y);

    if(x==y){
        return;
    }
    if(d[x]>d[y]){
        swap(x,y);
    }
    d[x]+=d[y];
    d[y] = x;
}

int main(){

    int N;
    vector<edge>EL;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int weight;
            cin>>weight;
            if(i>j){
                EL.push_back({i,j,weight});
            }
        }
    }

    sort(EL.begin(),EL.end(),cmp);

    vector<int>d(N,-1);
    for(auto e:EL){
        int u = find(d,e.from);
        int v = find(d,e.to);
        if(u!=v){
            cout<<e.to+1<<" "<<e.from+1<<endl;
            join(d,e.from,e.to);
        }
    }
    return 0;
}