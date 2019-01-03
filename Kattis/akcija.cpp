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




int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int T;
    cin>>T;
    long long ans = 0;
    vector<long long>vec;
    long long p;
    for(int i=0;i<T;i++){
        cin>>p;
        vec.push_back(p);
    }
    sort(vec.begin(),vec.end(),greater<int>());
    int i=0;
    if(T%3==0){
        while(i<T){
            ans+=vec[i];
            ans+=vec[i+1];
            i+=3;
        }
    }

    else if(T%3==1){
        while(i<T-1){
            ans+=vec[i];
            ans+=vec[i+1];
            i+=3;
        }
        ans+=vec[T-1];
    }
    else{
        while(i<T-2){
            ans+=vec[i];
            ans+=vec[i+1];
            i+=3;
        }
        ans+=vec[T-1];
        ans+=vec[T-2];
    }

    cout<<ans<<endl;
}
