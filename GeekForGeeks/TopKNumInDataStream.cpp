#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
using namespace std;
typedef pair<int,int> iPair;

//重载set的operator一定要在后面加上const修饰
struct cmp{
    bool operator()(const iPair&A,const iPair&B)const{
        if(A.first==B.first)
            return A.second<B.second;
        return A.first>B.first;
    }
};


typedef set<pair<int,int>,cmp> pairset;

int main() {
    int T;
    cin>>T;
    getchar();
    for(int i=0;i<T;i++){
        int N,K;
        cin>>N>>K;
        map<int,int> mp;
        set<pair<int,int>,cmp> st;
        for(int j=0;j<N;j++){
            int num;
            cin>>num;
            if(st.find(make_pair(mp[num],num))!=st.end())
                st.erase(make_pair(mp[num],num));
            mp[num]++;
            st.insert(make_pair(mp[num],num));
            //cout<<pq.size()<<endl;
            auto it = st.begin();
            int sz = st.size();
            for(int d=0;d<min(sz,K);d++){
                cout<<(*it).second<<" ";
                it++;
            }

        }
        cout<<endl;

    };


    return 0;
}