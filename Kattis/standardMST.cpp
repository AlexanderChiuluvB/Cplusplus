
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef pair<int,int>ip;
struct edge{
    int from;
    int to;
    int weight;
};

bool cmp(edge&A, edge&B){
    return A.weight<B.weight;
}

bool cmp2(edge&A, edge&B){
    if(A.from!=B.from)
        return A.from<B.from;
    return A.to<B.to;
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
    d[y] = x;
}

int main(){

    int n,m;
    while(true){
        cin>>n>>m;
        vector<edge>EL;
        if(n==0)
            break;
        for(int i=0;i<m;i++){
            int from,to,weight;
            cin>>from>>to>>weight;
            if(from>to)
                swap(from,to);
            EL.push_back({from,to,weight});
        }
        sort(EL.begin(),EL.end(),cmp);
        vector<int>d(n,-1);
        vector<edge>edgeVec;
        int w = 0;
        for(auto e:EL){
            int xx = find(d,e.from);
            int yy = find(d,e.to);
            if(xx!=yy){
                edgeVec.push_back(e);
                join(d,e.from,e.to);
                w+=e.weight;
            }
        }
        //how to make sure spanning tree is connected?
        //check whether there are more then 1 connected components
        int cc=0;
        for(auto i:d){
            if(i<0)
                cc++;
        }
        if(cc>1)
            cout<<"Impossible"<<endl;
        else{
            cout<<w<<endl;
            sort(edgeVec.begin(),edgeVec.end(),cmp2);
            for(auto p:edgeVec){
                cout<<p.from<<" "<<p.to<<endl;
            }
        }
    }

    return 0;
}
