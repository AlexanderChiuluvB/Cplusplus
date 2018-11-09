
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

#include <iomanip>

#include <unordered_set>

#include <unordered_map>

#include <deque>

using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int,int>ip;

int N,M;

vector<int> visited;

vector<double> dist;

map<int,int>leaveNeighbour;





unordered_map<string,vector<string>> adj;

unordered_map<string,int> numList;

unordered_map<string,int> visitList;

vector<string> vec;



void bfs( unordered_map<string,vector<string>>&adj,const string &source){



    queue<string>q;

    q.push(source);

    numList[source] = 0;
    visitList[source] = 1;
    while(!q.empty()){
        string top = q.front();
        q.pop();

        for(auto &name:adj[top]){
            if(!visitList[name]) {
                visitList[name] = 1;
                numList[name] = numList[top] + 1;
                q.push(name);

            }

        }

    }

}



int main(){

    string record;

    cin.tie(NULL);

    while(getline(cin,record)){

        stringstream ss(record);

        string firstname,name;

        ss>>firstname;

        //cout<<"first"<<firstname<<endl;

        numList[firstname]=INF;

        vec.push_back(firstname);

        while(ss>>name){
            adj[firstname].emplace_back(name);
            adj[name].emplace_back(firstname);

        }

    }

    bfs(adj,"PAUL_ERDOS");

    for(auto &name:vec){

        if(numList[name]!=INF)

            cout<<name<<" "<<numList[name]<<endl;

        else

            cout<<name<<" "<<"no-connection"<<endl;

    }



}

