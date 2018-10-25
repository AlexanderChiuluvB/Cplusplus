
// KATTIS2.cpp: 定义控制台应用程序的入口点。
//
#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <strstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
using namespace std;

struct Argus{
    int num,period,accu_period;
};
struct cmp{
    bool operator()(Argus s,Argus t){
        if(s.accu_period!=t.accu_period){
            return s.accu_period>t.accu_period;
        }
        return s.num>t.num;
    }
};


int main(){

    string info;
    priority_queue<Argus,vector<Argus>,cmp> pq;
    while(true){

        string buff;int num,Period;
        //stringstream stream(info);
        cin>>buff;
        if(buff=="#")
            break;
        cin>>num>>Period;
        Argus temp;
        temp.num = num;
        temp.accu_period = Period;
        temp.period = Period;
        pq.push(temp);

    }
    int k;
    cin>>k;
    while(k--){
        Argus t = pq.top();
        cout<<t.num<<endl;
        pq.pop();
        t.accu_period+=t.period;
        pq.push(t);
    }

}



