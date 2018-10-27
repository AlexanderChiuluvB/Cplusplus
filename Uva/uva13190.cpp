#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct node{
    string name;
    int idx;
    int time;
    int accumulateTime;
};
struct cmp{
    bool operator()(node &A,node &B){
        if(A.accumulateTime==B.accumulateTime){
            return A.idx>B.idx;
        }
        return A.accumulateTime>B.accumulateTime;
    }
};

int main() {


    int N;
    cin>>N;
    string name;
    int time;
    for(int i=0;i<N;i++){
        priority_queue<node,vector<node>,cmp> pq;
        int num,k;
        cin>>num>>k;
        for(int j=0;j<num;j++){
            cin>>name>>time;
            node temp;
            temp.name = name;
            temp.accumulateTime = time;
            temp.time = time;
            temp.idx = j;
            pq.push(temp);
        }
        while(k--){
            node topNode = pq.top();
            pq.pop();
            cout<<topNode.accumulateTime<<" "<<topNode.name<<endl;
            topNode.accumulateTime+=topNode.time;
            pq.push(topNode);
        }


    }


}


