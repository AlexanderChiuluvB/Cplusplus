#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <unordered_map>
using namespace std;
#define INF 0x3f3f3f3f
#define R 256
int const MAXM = 4000000;
char s[MAXM],t[MAXM];
int Next[MAXM];
//int output[MAXM];


void cal_next(const char *str,int *next,int len){

    next[0] = -1;//-1表示不存在相同的最大前缀和最大后缀

    int k = -1;
    for(int q=1;q<=len-1;q++){
        //如果下一个字符不同，那么k变成next【k】
        while(k>-1&&str[k+1]!=str[q]){
            k = next[k];
        }
        if(str[k+1]==str[q]){
            k++;
        }
        //k就是相同的最大前缀和最大后缀长
        next[q] = k;
    }
}

void KMP(const char *str,int slen,const char *ptr,int plen){
    int *next = new int[plen];
    cal_next(ptr,next,plen);

    int k = -1;
    for(int i=0;i<slen;i++){
        while(k>-1&&ptr[k+1]!=str[i]){
            k = next[k];
        }
        if(ptr[k+1]==str[i]){
            k++;
        }
        if(k==plen-1){
            cout<<i-plen+1<<" ";
        }
    }
    cout<<endl;
}





int main(){
    string pattern,text;
    while(getline(cin,pattern)&&getline(cin,text)){
        KMP(text.c_str(),text.size(),pattern.c_str(),pattern.size());
    }


}