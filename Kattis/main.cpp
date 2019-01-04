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
#define INF 0x3f3f3f3f


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        cout<<"Case #"<<i<<": ";
        int town,office,E;
        cin>>town>>office;
        cin>>E;
        map<int,int>Town2Car;
        map<int,int>mp;
        map<int,vector<int>>employee;
        for(int j=0;j<E;j++){
            int t,p;
            cin>>t>>p;
            Town2Car[t]+=p;
            mp[t]++;
            employee[t].push_back(p);
        }
        bool impossible = false;
        for(int t=1;t<=town;t++){

            if(mp[t]>Town2Car[t]&&t!=office){
                impossible = true;
                cout<<"IMPOSSIBLE";
                break;

            }
        }
        if(impossible){
            cout<<endl;
            continue;
        }

        for(int t=1;t<=town;t++){

            if(mp[t]==0||t==office){
                cout<<"0 ";
            }

            else if(mp[t]<=Town2Car[t]){
                auto vec = employee[t];
                sort(vec.begin(),vec.end(),greater<int>());
                int car = 1;
                int left = mp[t];
                for(int k=0;k<vec.size();k++){
                    int capa = vec[k];
                    if(capa>=left){
                        break;
                    }
                    else{
                        car++;
                        left-=capa;
                    }

                }
                cout<<car<<" ";
            }
        }
        cout<<endl;
    }
}