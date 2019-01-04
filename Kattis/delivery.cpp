#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <cmath>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
typedef long long ll;

ll solve(vector<pair<ll,ll>>&vec,ll letters){
    ll left = letters;
    ll traveled = vec[vec.size()-1].first*2;
    for(int i=vec.size()-1;i>=0;i--){
        if(vec[i].second>left){
            vec[i].second-=left;
            break;
        }else{
            left -=vec[i].second;
            vec.pop_back();
        }
    }
    return traveled;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,K;
    cin>>N>>K;
    vector<pair<ll,ll>>pos;
    vector<pair<ll,ll>>neg;
    for(int i=0;i<N;i++){
        int loc,let;
        cin>>loc>>let;
        if(loc<0){
            neg.push_back({-loc,let});
        }else{
            pos.push_back({loc,let});
        }
    }
    sort(neg.begin(),neg.end());
    sort(pos.begin(),pos.end());
    long long ans = 0;
    while(neg.size()>0){
        ans+=solve(neg,K);
    }
    while(pos.size()>0){
        ans+=solve(pos,K);
    }


    cout<<ans<<endl;




}
