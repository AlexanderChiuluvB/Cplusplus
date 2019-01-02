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

vector<int>xadj ={2,2,-2,-2,1,1,-1,-1};
vector<int>yadj ={1,-1,1,-1,2,-2,2,-2};

int n;

bool search(string &word,int i,int j,vector<vector<char>>&grid,int count){
    if(count==word.size())
        return true;

    if(grid[i][j]!=word[count])
        return false;

    for(int d=0;d<8;d++){
        int ii = i+xadj[d];
        int jj = j+yadj[d];
        if(ii<0||jj<0||ii>=n||jj>=n){
            continue;
        }

        if (search(word, ii, jj, grid, count + 1)) {
            return true;
        }



    }
    return false;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int N,M,K;
    cin>>N>>M>>K;
    vector<double>spotRadius;
    while(N--){
        double r;
        cin>>r;
        spotRadius.push_back(r);
    }
    sort(spotRadius.begin(),spotRadius.end());

    vector<double>radius;
    for(int i=0;i<M;i++){
        double r;
        cin>>r;
        radius.push_back(r);
    }
    for(int i=0;i<K;i++){
        double r;
        cin>>r;
        radius.push_back(sqrt(2)/2*r);
    }
    sort(radius.begin(),radius.end());


    int ans = 0;
    int j=spotRadius.size()-1;
    for(int i=radius.size()-1;i>=0;i--){
        if(radius[i]<spotRadius[j]){
            ans++;
            if(j>=1)
                j--;
            else
                break;
        }


    }
    cout<<ans<<endl;
}