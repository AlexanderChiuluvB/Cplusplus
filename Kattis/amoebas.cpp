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
#include <unordered_map>
#include <deque>
using namespace std;
#define INF 0x3f3f3f3f




int N,M;


void dfs(vector<vector<char>>&vec,int x,int y,int &count){
    if(x<0||y<0||x>=vec.size()||y>=vec[0].size()||vec[x][y]=='.'){
        return;
    }
    vec[x][y]='.';
    dfs(vec,x,y-1,count);
    dfs(vec,x,y+1,count);
    dfs(vec,x-1,y,count);
    dfs(vec,x+1,y,count);
    dfs(vec,x+1,y+1,count);
    dfs(vec,x+1,y-1,count);
    dfs(vec,x-1,y+1,count);
    dfs(vec,x-1,y-1,count);
}

int main(){
    int c=0;
    while(cin>>N>>M){

        vector<vector<char>> vec;
        vec.assign(N,vector<char>(M,' '));
        for (int i = 0; i < N; ++i) {
            for(int j=0;j<M;j++){
                char temp;
                cin>>temp;
                vec [i] [j] = temp;
            }
        }
        int count=0;
        for(int i=0;i<N;++i){
            for(int j=0;j<M;j++){
                if(vec[i][j] =='#'){
                    count++;
                    dfs(vec,i,j,count);
                }
            }
        }
        cout<<count<<endl;
    }



}