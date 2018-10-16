//
// Created by alex on 18-10-16.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//https://open.kattis.com/problems/bard/submit

int main(){

    int N,E,K,temp,numOfSongs=0;
    cin>>N;

    cin>>E;
    //villager---songnums

    unordered_map<int,int> hash;
    map<int,unordered_set<int>> evening;
    //unordered_map<int,int> evening;
    for(int i=0;i<E;i++){
        cin>>K;
        //今晚来的人
        unordered_set<int> set;
        bool oneCome = false;
        for(int j=0;j<K;j++){
            cin>>temp;
            if(temp==1){
                oneCome=true;
                numOfSongs++;
            }
            set.insert(temp);


        }
        if(oneCome){
            for(auto s:set) {
                //hash[s]++;
                //村民s第i个夜晚来了
                evening[s].insert(i);
            }
        }

        else{
            unordered_set<int> allNights;
            for(auto s:set){
                for(auto e:evening[s])
                    allNights.insert(e);
            }
            for(auto s:set){
                evening[s] = allNights;
            }

        }


    }

    //vector<int> result;
    for(auto e:evening){
        if(e.second.size()==numOfSongs)
            cout<<e.first<<endl;
            //result.push_back(e.first);
    }

    //sort(result.begin(),result.end());
    //for(auto i:result)
        //cout<<i<<endl;

    return 0;
}