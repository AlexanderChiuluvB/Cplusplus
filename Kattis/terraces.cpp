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


vector<vector<int>> visited;

vector<vector<int>> dist;
int N,M;


//https://github.com/mpfeifer1/Kattis/blob/master/terraces.cpp
// use union find to group the points with same height

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}


int find(vector<int>&d,int a){
    if(d[a]==-1)
        return a;
    return  d[a] = find(d,d[a]);
}

void join(vector<int>&d,int a,int b){

    a = find(d,a);
    b = find(d,b);
    if(a==b)
        return;
    d[a] = b;
}

int spot(int i,int j){
    return i*M+j;
}
int main(){
    fast();
    int c=0;
    cin>>M>>N;
    vector<vector<int>> vec;
    vector<bool> works(N*M,true);
    vector<int> d(N*M,-1);
    vec.assign(N,vector<int>(M,0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; j++) {
            int num;
            cin>>num;
            vec[i][j] = num;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; j++) {

            if (i>0) {
                if (vec[i][j] == vec[i - 1][j])
                    join(d, spot(i, j), spot(i - 1, j));
                else if (vec[i][j] > vec[i - 1][j])
                    works[spot(i,j)] = false;
                else
                    works[spot(i-1,j)] = false;
            }

            if (j>0) {
                if (vec[i][j] == vec[i][j - 1])
                    join(d, spot(i, j), spot(i, j - 1));
                else if (vec[i][j] > vec[i][j - 1])
                    works[spot(i,j)]= false;
                else
                    works[spot(i,j-1)]= false;
            }


        }
    }


    int count=0;

    for(int i=0;i<N*M;i++){
        int head = find(d,i);
        if(!works[i])
            works[head] = false;
    }
    for(int i=0;i<N*M;i++){
        int head = find(d,i);
        if(works[head])
            count++;
    }
    cout<<count<<endl;


}