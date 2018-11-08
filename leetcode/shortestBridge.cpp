class Solution {
public:


    vector<vector<int>> visited;
 

    bool inGraph(vector<vector<int>>&A,int x,int y){
        if(x>=0&&y>=0&&x<A.size()&&y<A[0].size())
            return true;
        return false;
    }


    void dfs(vector<vector<int>>&A,int xx,int yy,vector<pair<int,int>>&vec){



        visited[xx][yy] = 1;
        vec.push_back(make_pair(xx,yy));
        if(inGraph(A,xx+1,yy)&&A[xx+1][yy]==1&&!visited[xx+1][yy]){
            dfs(A,xx+1,yy,vec);
        }
        if(inGraph(A,xx-1,yy)&&A[xx-1][yy]==1&&!visited[xx-1][yy]){
            dfs(A,xx-1,yy,vec);
        }
        if(inGraph(A,xx,yy+1)&&A[xx][yy+1]==1&&!visited[xx][yy+1]){
            dfs(A,xx,yy+1,vec);
        }
        if(inGraph(A,xx,yy-1)&&A[xx][yy-1]==1&&!visited[xx][yy-1]){
            dfs(A,xx,yy-1,vec);
        }
    }



    int shortestBridge(vector<vector<int>>& A) {


        visited.assign(A.size(),vector<int>(A[0].size(),0));
        vector<pair<int,int>> vec1;
        vector<pair<int,int>> vec2;
        bool stop = false;
        // cc2.assign(A.size(),vector<int>(A[0].size(),0));
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(A[i][j]==1&&!visited[i][j]){
                    dfs(A,i,j,vec1);
                    stop = true;
                    break;
                }
            }
            if(stop)
                break;
        }
        stop  =false;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(A[i][j]==1&&!visited[i][j]){
                    dfs(A,i,j,vec2);
                    stop = true;
                    break;
                }
            }
            if(stop)
                break;
        }

        int minDis =INT_MAX;
        for(auto p:vec1){
            int xx1 = p.first;
            int yy1 = p.second;
            for(auto pp:vec2){
                int xx2 = pp.first;
                int yy2 = pp.second;
                if(abs(xx1-xx2)+abs(yy1-yy2)-1<minDis)
                    minDis = abs(xx1-xx2)+abs(yy1-yy2)-1;
            }
        }
        return minDis==0?1:minDis;
        //visited.assign(A.size(),vector<int>(A[0].size(),0));

    }


};