/* CS1010E Final Examination                  */
/* AY 2018/19 Semester 1                      */

#include <stdio.h>
#include <stdbool.h>
#include <bits/stdc++.h>
#define M 50
#define N 50


using namespace std;
#define INF 0x3f3f3f3f

vector<vector<int>>grid;
vector<int>inDegree;
int A,B,E;
vector<int>visited;
unordered_map<int,int>mpA;
unordered_map<int,int>mpB;
vector<int>parent;
int way = 0;
void dfs(int num,vector<vector<int>>&grid){

    if(num==E-1){
        way++;
        for(int i=0;i<A;i++){
            mpA[parent[i]]++;
        }
        for(int i=0;i<B;i++){
            mpB[parent[i]]++;
        }
    }
    for(int i=0;i<E;i++){
        if(inDegree[i]==0&&!visited[i]){
            for(int j=0;j<E;j++){
                if(grid[i][j]){
                    inDegree[j]--;
                    visited[i]=1;
                    parent[num] = i;
                    dfs(num+1,grid);
                }
            }
            for(int j=0;j<E;j++){
                if(grid[i][j]){
                    inDegree[j]++;
                    visited[i] = 0;
                }
            }
        }

    }

}


int main(){
    int P;
    cin>>A>>B>>E>>P;
    vector<vector<int>>vec(E,vector<int>(E,0));
    inDegree.assign(E,0);
    visited.assign(E,0);
    parent.assign(E,0);
    while(P--){
        int from,to;
        cin>>from>>to;
        vec[from][to]=1;
        inDegree[to]++;
    }
    dfs(0,vec);
    int countA=0;
    int countB=0;
    int countC=0;
    for(auto e:mpA){
        //cout<<e.first<<" "<<e.second<<endl;
        if(e.second==way){
            countA++;
        }
    }
    for(auto e:mpB){
        if(e.second==way){
            countB++;
        }
    }
    cout<<countA<<endl;
    cout<<countB<<endl;
    for(int i=0;i<E;i++){
        if(mpB[i]==0)
            countC++;
    }
    cout<<countC<<endl;

}
