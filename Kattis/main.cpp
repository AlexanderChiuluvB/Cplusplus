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


    int N,K;
    cin>>N>>K;
    vector<int>vec;

    int time=0;
    int penalty = 0;
    int numAC = 0;

    for(int i=0;i<N;i++){
        int t;cin>>t;
        if(i!=K){
            vec.push_back(t);
        }else{
            if(time+t<=300){
                numAC++;
                time+=t;
                penalty+=t;
            }else{
                cout<<"0 0"<<endl;
                return 0;
            }
        }
    }


    sort(vec.begin(),vec.end());

    for(int i=0;i<N-1;i++){
        if(time+vec[i]<=300){
            numAC++;
            time+=vec[i];
            penalty+=time;
        }else{
            break;
        }
    }
    cout<<numAC<<" "<<penalty<<endl;
}