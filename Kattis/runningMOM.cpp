#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <stack>
#include <iterator>
#include <string.h>
#include <sstream>
#include <string>
#include <queue>
#include <list>
#include <unordered_map>
#include <deque>
using namespace std;
#define INF 0x3f3f3f3f


unordered_map<string,vector<string>>mp;
unordered_map<string,int> status;

void isCycle(string source,bool &find){


    status[source] = 1;
    for(auto city:mp[source]){
        if(status[city]==0){
            isCycle(city,find);
        }
        else if(status[city]==1)
            find = true;
    }
    status[source] = 2;
}


int main() {

    int N;
    cin>>N;

    while(N--){
        string from,to;
        cin>>from>>to;
        mp[from].push_back(to);
    }
    string city;
    while(cin>>city){
        for(auto c:mp)
            status[c.first]= 0;
        bool find = false;
        isCycle(city,find);
        if(find){
            cout<<city<<" safe"<<endl;
        }
        else{
            cout<<city<<" trapped"<<endl;
        }

    }


    return 0;

}