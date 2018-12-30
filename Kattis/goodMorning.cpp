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

    unordered_map<int,int>mpx;
    unordered_map<int,int>mpy;
    mpx[1]=0;
    mpx[4]=0;
    mpx[7]=0;
    mpx[2]=1;
    mpx[5]=1;
    mpx[8]=1;
    mpx[0]=1;
    mpx[3]=2;
    mpx[6]=2;
    mpx[9]=2;

    mpy[1]=0;
    mpy[4]=1;
    mpy[7]=2;
    mpy[2]=0;
    mpy[5]=1;
    mpy[8]=2;
    mpy[0]=3;
    mpy[3]=0;
    mpy[6]=1;
    mpy[9]=2;

    set<int>st;
    for(int i=1;i<201;i++){
        bool valid = true;
        vector<int>temp;
        int num = i;
        while(num!=0){
            int digit = num%10;
            temp.push_back(digit);
            num/=10;
        }
        for(int j = temp.size()-1;j>0;j--){
            if(mpx[temp[j]]>mpx[temp[j-1]]||mpy[temp[j]]>mpy[temp[j-1]]){
                valid = false;
                break;
            }
        }

        if(valid){
            st.insert(i);
        }

    }


    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        if(st.find(num)!=st.end()){
            cout<<num<<endl;
            continue;
        }
        int i=1;
        while(true){
            if(st.find(num-i)!=st.end()){
                cout<<num-i<<endl;
                break;
            }
            if(st.find(num+i)!=st.end()){
                cout<<num+i<<endl;
                break;
            }
            i++;
        }

    }

}

