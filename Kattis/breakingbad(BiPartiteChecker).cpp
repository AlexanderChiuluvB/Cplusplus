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
#include <math.h>
#include <deque>

using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int,int> ip;
typedef pair<double,double> dp;
typedef pair<double,int>idp;
typedef tuple<int,int,int,int> iiii;
typedef vector<iiii> viiii;

unsigned int seed;



double distance(int x1,int y1,int x2,int y2){
    return (pow(x1-x2,2)+pow(y1-y2,2));
}

int N;
bool onBoard(int x,int y){
    if(x>=0&&x<N&&y>=0&&y<N)
        return true;
    return false;
}
vector<ip>mv({{1,0},{-1,0},{0,1},{0,-1}});
void dfs(vector<vector<char>>&mtx,int x,int y){
    mtx[x][y]='F';
   // int size = mtx.size();
    for(int i=0;i<N;i++){
        int xx = x+mv[i].first;
        int yy = y+mv[i].second;
        if(onBoard(xx,yy)&&(mtx[xx][yy]=='x'||mtx[xx][yy]=='@')){
            dfs(mtx,xx,yy);
        }
    }
}

vector<int>colour;

bool checker(vector<vector<int>>&AL,int src,bool &result){
    colour[src] = 1;
    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto v:AL[top]){
            if(colour[v]==-1){
                colour[v] = 1-colour[top];
                q.push(v);
            }
            else if(colour[top]==colour[v]){
                result = false;
            }
        }
    }
    return result;
}

int main(){

    cin>>N;
    map<string,int> mp;
    map<int,string> mp2;
    for(int i=1;i<=N;i++){
        string name;
        cin>>name;
        mp[name] = i;
        mp2[i] = name;
    }

    int M;
    cin>>M;
    vector<vector<int>>vec(N+1);
    int fromidx,toidx;
    vector<int> fromVec;
    for(int i=1;i<=M;i++){
        string from,to;
        cin>>from>>to;
        fromidx = mp[from];
        toidx = mp[to];
        fromVec.push_back(fromidx);
        vec[fromidx].push_back(toidx);
        vec[toidx].push_back(fromidx);
    }
    bool canDivide = true;
    colour.assign(N+1,-1);
    for(auto idx:fromVec){
        if(colour[idx]==-1)
            checker(vec,idx,canDivide);
    }
    vector<string>st1;
    vector<string>st2;
    if(!canDivide){
        cout<<"impossible"<<endl;
    }
    else{
        for(int i=1;i<=N;i++){
            //cout<<colour[i]<<endl;
            if(colour[i]==0){
                st1.push_back(mp2[i]);
            }
            else{
                st2.push_back(mp2[i]);
            }
        }
        for(auto str:st1){
            cout<<str<<" ";
        }
        cout<<endl;
        for(auto str:st2){
            cout<<str<<" ";
        }
        cout<<endl;
    }



}
