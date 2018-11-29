
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
typedef pair<int,int> ip;
typedef tuple<int,int,int,int> iiii;
typedef vector<iiii> viiii;

unsigned int seed;


int main(){

    int n=0;
    while(n!=-1){
        cin>>n;
        int adjmatrix [21][21];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>adjmatrix[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            vector<int>vec;
            bool weak = true;
            for(int j=1;j<=n;j++){
                if(adjmatrix[i][j]==1)
                    vec.push_back(j);
            }
            if(vec.size()>1){
                for(int j=0;j<vec.size()-1;j++){
                    bool done = false;
                    for(int k=j+1;k<vec.size();k++){
                        if(adjmatrix[vec[j]][vec[k]]){
                            weak = false;
                            done = true;
                        }
                    }
                    if(done)
                        break;
                }
            }

            if(weak){
                cout<<i-1<<" ";
            }
        }
        cout<<endl;
    }


}

