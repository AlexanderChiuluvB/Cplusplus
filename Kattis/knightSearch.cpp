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

    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n,' '));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    string word = "ICPCASIASG";
    bool find = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(search(word,i,j,grid,0)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;






}
