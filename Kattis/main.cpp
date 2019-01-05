#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <cmath>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define oo 2147483647


vector<vector<int>>adj;
vector<vector<int>>checkadj;
vector<int>visited;
int N;


int gird2idx(int i,int j){
    return i*N+j;
}

bool onBoard(int i,int j){
    if(i>=0&&j>=0&&i<N&&j<N)
        return true;
    return false;
}


void dfs(int u,int d,vector<int>&visited){

    visited[u] = 1;

    for(auto p:adj[u]) {
        if (!visited[p]) {
            dfs(p, d, visited);
        }
    }
}





int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N;
    char c;
    vector<vector<char>> grid(N, vector<char>(N, ' '));

    visited.assign(N * N, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            grid[i][j] = c;
        }
    }

    adj.assign(N * N, vector<int>());
    ll dp[1010][1010];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (grid[i][j] == '.') {
                if (onBoard(i + 1, j) && grid[i + 1][j] == '.') {
                    adj[gird2idx(i, j)].push_back(gird2idx(i + 1, j));

                }
                if (onBoard(i, j + 1) && grid[i][j + 1] == '.') {
                    adj[gird2idx(i, j)].push_back(gird2idx(i, j + 1));

                }
                if (onBoard(i, j - 1) && grid[i][j - 1] == '.') {
                    adj[gird2idx(i, j)].push_back(gird2idx(i, j - 1));

                }
                if (onBoard(i - 1, j) && grid[i - 1][j] == '.') {
                    adj[gird2idx(i, j)].push_back(gird2idx(i - 1, j));

                }


            }

            if (i == 0 && j == 0 && grid[i][j] == '.') {
                dp[i][j] = 1;
                continue;
            }
            if (i == 0 && grid[i][j] == '.') {
                dp[i][j] = (dp[i][j - 1])%oo;
                continue;
            }
            if (j == 0 && grid[i][j] == '.') {
                dp[i][j] = (dp[i - 1][j])%oo;
                continue;
            }
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%oo;
            }
        }
    }


    if (dp[N - 1][N - 1] != 0) {
        cout << dp[N - 1][N - 1] << endl;
        return 0;
    }
    else {
        visited.assign(N * N, 0);
        dfs(0, N * N - 1, visited);
        if (visited[N * N - 1]) {
            cout << "THE GAME IS A LIE" << endl;
            return 0;
        }
        else {
            cout << "INCONCEIVABLE" << endl;
        }
    }



}