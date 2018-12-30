#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <sstream>
#include <list>
#include <cmath>
#include <queue>

using namespace std;
#define INF 0x3f3f3f3f

int MAX=1000;
typedef long long ll;

vector<int>tempSmaller;



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,s,r;
    unordered_map<int,int>mp;
    cin>>n>>s>>r;
    for(int i=1;i<=n;i++){
        mp[i] = 1;
    }

    int teamNum;
    while(s--){
       cin>>teamNum;
       mp[teamNum]=0;
    }

    while(r--){
        cin>>teamNum;
        if(mp[teamNum]==0){
            mp[teamNum]=2;
            continue;
        }else if(mp[teamNum]==1){
            if(teamNum-1>=1&&mp[teamNum-1]==0){
                mp[teamNum-1] = 2;
                continue;
            }
            if(teamNum+1<=n&&mp[teamNum+1]==0){
                mp[teamNum+1] = 2;
                continue;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(mp[i]==0){
            ans++;
        }
    }
    cout<<ans<<endl;
}

