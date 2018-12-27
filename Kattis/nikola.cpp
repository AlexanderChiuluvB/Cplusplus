#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <sstream>
#include <list>
#include <cmath>
#include <queue>

using namespace std;
#define INF 1e18

int MAX=1000;
typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin>>N;
    int cost[N+1];
    for(int i=1;i<=N;i++){
        cin>>cost[i];
    }
    //i:current_pos j:jump_step
    ll dp[N+1][N+1];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            dp[i][j] = INF;
        }
    }

    typedef pair<ll,pair<int,int>> state;
    priority_queue<state,vector<state>,greater<state>>pq;
    pq.push({0,make_pair(1,0)});

    dp[1][0] = 0LL;
    ll ans = INF;
    while(!pq.empty()){

        auto top = pq.top();
        pq.pop();
        ll currentCost = top.first;
        int currentPos = top.second.first;
        int previousJump = top.second.second;

        if(currentPos==N){
            ans = min(ans,currentCost);
        }

        if(currentPos+1+previousJump<=N){
            int idx  = currentPos+1+previousJump;
            ll newCost = currentCost+cost[idx];
            if(newCost<dp[idx][previousJump+1]){
                dp[idx][previousJump+1] = newCost;
                pq.push({newCost,make_pair(idx,previousJump+1)});
            }
        }

        if(currentPos-previousJump>=1){
            int idx  = currentPos-previousJump;
            ll newCost = currentCost+cost[idx];
            if(newCost<dp[idx][previousJump]){
                dp[idx][previousJump] = newCost;
                pq.push({newCost,make_pair(idx,previousJump)});
            }
        }

    }

    cout<<ans<<endl;

}

