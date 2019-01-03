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

    int l,d,n;
    cin>>l>>d>>n;
    int pos;
    set<int>st;
    for(int i=0;i<n;i++){
        cin>>pos;st.insert(pos);
    }
    int ans =0;
    int curlen = 6;

    for(auto pos:st){
        while(true){
            if(pos-curlen>=d){
                ans++;
                curlen+=d;
            }else{
                curlen=pos+d;
                break;
            }
        }
    }

    while(curlen<=l-6){
        curlen+=d;
        ans++;

    }
    cout<<ans<<endl;







}