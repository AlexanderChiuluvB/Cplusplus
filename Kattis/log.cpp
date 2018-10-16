#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<string,int> PAIR;

struct CmpByValue {
    bool operator ()(const PAIR &lhs, const PAIR &rhs) {
        if(lhs.second!=rhs.second)
            return lhs.second > rhs.second;
        else
            return lhs.first<rhs.first;
    }
};


int main() {

    int N;
    cin>>N;
    //unordered_map<string,int> namehash;
    unordered_map<string,vector<string>>m;
    int numOfUser=0;
    int i=0;
    string temp,name,word;
    getline(cin,word);
    while(i<N){
        getline(cin,temp);
        stringstream stream(temp);
        getline(stream,name,' ');
        while(getline(stream,word,' ')){
            m[name].push_back(word);
        }
        i++;
    }

    numOfUser = m.size();
    unordered_map<string,int> M;
    unordered_map<string,int> C;
    for(auto p:m){
        unordered_set<string> set;
        for(auto w:p.second){
            set.insert(w);
            C[w]++;
        }
        for(auto s:set){
            M[s]++;
        }
    }


    vector<pair<string,int>> vec;
    for(auto w:C) {
        if(M[w.first]==numOfUser)
            vec.push_back(make_pair(w.first, w.second));
    }
    sort(vec.begin(),vec.end(),CmpByValue());

    bool find = false;
    for(auto v:vec){

        cout<<v.first<<endl;
        find = true;


    }

    if(!find)
        cout<<"ALL CLEAR"<<endl;

    return 0;
}