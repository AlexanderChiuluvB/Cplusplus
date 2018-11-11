
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

//https://blog.csdn.net/litmxs/article/details/78241850
vector<vector<int>>visit;
vector<vector<int>>height;
int h,w;
vector<ip> mv({{0,-1},{0,1},{1,0},{-1,0}});
bool onBoard(int x,int y){
    if(x>=0&&y>=0&&x<h&&y<w)
        return true;
    return false;
}

int main(){

    int T;
    cin>>T;
    while(T--){
        cin>>w>>h;
        int out = 0;
        int ans = 0;
        char t;
        vector<vector<char>>adj(h,vector<char>(w,' '));
        queue<ip> fire,players;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>t;
                if(t=='*')
                    fire.push(make_pair(i,j));
                else if(t=='@')
                    players.push(make_pair(i,j));
                adj[i][j]=t;
            }
            cin>>ws;
        }
        //考虑了多个玩家的情况
        while(!players.empty()){
            int playerSize = players.size();
            int fireSize = fire.size();
            while(fireSize--){
                ip top = fire.front();
                int x = top.first;
                int y = top.second;
                fire.pop();
                for(int i=0;i<4;i++){

                    int xx=x+mv[i].first;

                    int yy=y+mv[i].second;

                    if(!onBoard(xx,yy)||adj[xx][yy]=='#'||adj[xx][yy]=='*')
                        continue;
                    else{
                        adj[xx][yy] = '*';
                        fire.push({xx,yy});
                    }
                }
            }
            while(playerSize--){
                ip top = players.front();
                int x = top.first;
                int y = top.second;
                players.pop();
                for(int i=0;i<4;i++){
                    int xx=x+mv[i].first;
                    int yy=y+mv[i].second;
                    if(xx<0||yy<0||xx>=h||yy>=w)
                    {
                        out=1;
                        players = queue<ip>();//clear
                        break;
                    }
                    else if(adj[xx][yy]=='.'){
                        adj[xx][yy] = '@';
                        players.push({xx,yy});
                    }
                }
                if(players.size()==0)
                    break;
            }
            ans++;

        }
        if(out)cout<<ans<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
}

