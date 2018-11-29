class Solution {
public:
    bool inGrid(vector<vector<int>>& grid,int x,int y){
        if(x>=0&&y>=0&&x<grid.size()&&y<grid.size())
            return true;
        return false;
    }


    int swimInWater(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<vector<int>> visited(size,vector<int>(size,-1));
        int ans = max(grid[0][0],grid[size-1][size-1]);

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        pq.push({ans,0,0});
        visited[0][0]=1;
        while(!pq.empty()){
            auto Top = pq.top();
            pq.pop();
            visited[Top[1]][Top[2]] = 1;
            ans = max(ans,Top[0]);
            vector<vector<int>> vec ({{0,1},{0,-1},{1,0},{-1,0}});
            for(int i=0;i<4;i++){
                int xx =Top[1]+vec[i][0];
                int yy = Top[2]+vec[i][1];
                if(inGrid(grid,xx,yy)&&visited[xx][yy]!=1){
                    if(xx==grid.size()-1&&yy==grid.size()-1){
                        return ans;
                    }
                    pq.push({grid[xx][yy],xx,yy});

                }
            }
        }

        return ans;

    }
};