#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <sstream>
#include <list>
#include <cmath>
#include <queue>

using namespace std;
#define INF 1e18

int MAX=1000;
typedef long long ll;

vector<int>tempSmaller;

int lowBit(int idx){
    return idx&(-idx);
}

void add(int idx,int val){
    int len = (int)tempSmaller.size();
    while(idx<len){
        tempSmaller[idx]+=val;
        idx +=lowBit(idx);
    }
}

int query(int idx){
    int sum = 0;
    while(idx>0) {
        sum += tempSmaller[idx];
        idx -= lowBit(idx);
    }
    return sum;
}

int sum(int i,int j){
    return query(j)-query(i-1);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;
    vector<int>nums;
    tempSmaller.resize(n+1);
    int *pos= new int [1+n];
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
        pos[num] = i;
        add(i,1);
    }

    int left = 1;
    int right = n;
    for(int i=1;i<=n;i++){
        //odd
        //看前面有多少元素比这个元素大
        if(i%2==1){
            //相当于不再考虑left,
            add(pos[left],-1);
            cout<<sum(1,pos[left])<<endl;
            left++;
        }
        //看后面有多少元素比这个元素小
        else{
            add(pos[right],-1);
            cout<<sum(pos[right],n)<<endl;
            right--;
        }
    }

}

