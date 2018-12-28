#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;

int n, q;


void update(vector<int>&vec,int index,int val){

    //update的时候，index要先++,这里直接用vec[i]就是默认了index++；
    for(int i=index;i<vec.size();i|=(i+1)){
        vec[i]+=val;
    }
}

int getSum(vector<int>&vec,int index){
    int total = 0;
    for(int i=index;i>0;i&=(i-1)){
        total+=vec[i-1];
    }
    return total;

}

int getVal(vector<int>&vec,int index){
    return getSum(vec,index+1)-getSum(vec,index);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>q;
    vector<int>BIT(n+1,0);
    for(int i=0;i<q;i++){
        char c;
        cin>>c;
        if(c=='F'){
            int index;
            cin>>index;
            int val = getVal(BIT,index);
            if(val==0){
                val=1;
            }else{
                val=-1;
            }
            update(BIT,index,val);
            //val = getVal(BIT,index);
        }
        if(c=='C'){
            int a,b;
            cin>>a>>b;
            cout<<getSum(BIT,b+1)-getSum(BIT,a)<<endl;
        }
    }



}