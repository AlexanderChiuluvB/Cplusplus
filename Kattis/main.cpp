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


int one(string pat,string S){
    int count=0;
    int index=0;
    index = S.find(pat);
    while(index!=-1){
        count++;
        index = S.find(pat,index+1);
    }
    return count;

}

int two(string pat,string S){
    set<string> temp;
    for(int i=0;i<pat.size();i++){
        string newpat = pat;
        newpat.erase(i,1);
        temp.insert(newpat);
    }
    int count=0;

    for(auto &str:temp){
        count+=one(str,S);
    }
    return count;
}

int three(string pat,string S){

    string agct = "AGCT";
    set<string> temp;
    for(int i=0;i<pat.size()+1;i++){
        for(int j=0;j<4;j++){
            string temppat = pat;
            temppat.insert(i,1,agct[j]);
            temp.insert(temppat);
        }
    }


    int count=0;
    for(auto &str:temp){
        count+=one(str,S);
    }
    return count;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string pat,S;
    while(true){

        cin>>pat>>S;
        if(pat=="0"){
            break;
        }
        cout<<one(pat,S)<<" "<<two(pat,S)<<" "<<three(pat,S)<<endl;
    }
}