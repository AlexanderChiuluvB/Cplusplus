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
#include <math.h>
#include <deque>

using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int,int> ip;
typedef pair<double,double> dp;
typedef pair<double,int>idp;
typedef tuple<int,int,int,int> iiii;
typedef vector<iiii> viiii;

unsigned int seed;


vector<int>visited;
vector<int>color;
int n;

void bfs(vector<vector<int>>&grid,int src,int TTL){
    queue<int>q;
    q.push(src);
    int qsize = 0;
    while(!q.empty()){
        if(qsize==0){
            qsize = q.size();
        }
        int top = q.front();
        q.pop();
        visited[top] = 1;
        for(auto v:grid[top]){
            if(!visited[v]){
                q.push(v);
            }
        }
        qsize--;
        if(qsize==0){
            TTL--;
        }
        if(TTL==0){
            break;
        }
    }
}

int N;
vector<int>inDegree;
vector<vector<int>>weightList;

void dfs(vector<vector<ip>>&adjList,int src,int target,vector<int>&visited,vector<int>&result,int &count,int &weight){


    visited[src] = 1;
    int temp=0,from;
    if(!result.empty()){
        from = *result.rbegin();
        temp = weightList[from][src];
        weight+=temp;
    }
    result.push_back(src);
    if(src==2&&weight==target){
        count++;
    }
    else{
        for(auto p:adjList[src]){
            if(!visited[p.first]){
                dfs(adjList,p.first,target,visited,result,count,weight);
            }
        }
    }
    weight-=temp;
    visited[src] = false;
    result.erase(result.end()-1);
}


struct TreeNode{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int v){
        left = right = NULL;
        val = v;
    }
};


TreeNode* insert(TreeNode*root,int val){
    if(!root){
        return new TreeNode(val);
    }
    if(val<root->val){
        root->left  =insert(root->left,val);
    }
    else if(val>root->val){
        root->right = insert(root->right,val);
    }
    return root;
}

void countNode(TreeNode*root, int &count){
    if(root){
        countNode(root->left,count);
        count++;
        countNode(root->right,count);
    }
}

void traverse(TreeNode*root,string &ans,int level){
    if(root){
        traverse(root->left,ans,level+1);
        ans+=char(level);
        traverse(root->right,ans,level+1);
    }
}

int main(){

    int n,k;
    cin>>n>>k;
    set<string>st;
    for(int i=0;i<n;i++){
        TreeNode* root=NULL;
        for(int j=0;j<k;j++){
            int num;
            cin>>num;
            root = insert(root,num);
        }
        string ans;
        traverse(root,ans,0);
        st.insert(ans);
    }


    cout<<st.size()<<endl;

}
