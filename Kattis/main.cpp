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
#include <queue>

using namespace std;
#define INF 0x3f3f3f3f


vector<int>xadj={0,0,1,1,1,-1,-1,-1};
vector<int>yadj={-1,1,-1,0,1,-1,0,1};
set<string>st;
vector<vector<int>>visited;

bool search(string &word,int i,int j,vector<vector<char>>&grid,int ch){

    if(ch==word.size())
        return true;


    if(i<0||j<0||i>3||j>3){
        return false;
    }

    if(visited[i][j]){
        return false;
    }


    if(word[ch]!=grid[i][j]){
        return false;
    }

    for(int u=0;u<8;u++){
        int ii = xadj[u]+i;
        int jj = yadj[u]+j;
        visited[i][j] = true;
        bool valid= search(word,ii,jj,grid,ch+1);
        visited[i][j] = false;
        if(valid){
            return true;
        }
    }

    return false;
}


bool found(vector<vector<char>>&grid,string &word){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(search(word,i,j,grid,0)){
                //cout<<word<<endl;
                return true;
            }
        }
    }
    return false;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int w;
    cin>>w;
    string word;
    vector<string>res;
    while(w--){
        cin>>word;
        res.push_back(word);
    }

    int n;
    cin>>n;
    vector<int>scoreList = {0,0,0,1,1,2,3,5,11,11};
    while(n--){
        int score=0;
        visited.resize(4,vector<int>(4,0));
        vector<vector<char>>grid(4,vector<char>(4,' '));
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                char c;cin>>c;
                grid[i][j] = c;
            }
        }
        string maxWord = "";
        int maxLen = -INF;
        int total = 0;
        for(auto word:res){
            if(found(grid,word)){
                total++;
                if(word.size()>maxWord.size()){
                    maxLen = (int)word.size();
                    maxWord = word;
                }else if(word.size()==maxWord.size()){
                    if(word<maxWord){
                        maxWord = word;
                    }
                }
               if(word.size()<=8){
                   score+=scoreList[word.size()];
               }
               else{
                   score+=11;
               }
            }
        }

        cout<<score<<" "<<maxWord<<" "<<total<<endl;

    }





}