class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n,string(n,'.'));
        solve(res,nQueens,0,n);
        return res;

    }

    void solve(vector<vector<string> >&res,vector<string> &nQueens,int row, int &n){
        //quit 来到了最后一行，证明已经找到解
        if(row==n){
            res.push_back(nQueens);
            return;
        }
        for(int col=0;col!=n;col++){
            if(isValid(nQueens,row,col,n)){
                //按列来摆好，如果这一列可以摆，那就移到下一行（递归）
                nQueens[row][col] = 'Q';
                solve(res,nQueens,row+1,n);
                //回溯，说明刚才那一列不能摆，继续这个循环
                nQueens[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string> &nQueens,int row,int col,int &n){

        //针对某一列，遍历所有行看他是否满足资格
        int r,c;
        for(r=0;r<row;r++){
            //这一列不能存在其他皇后而且对角线不能有皇后（斜率不等于1/-1）

            if(nQueens[r][col]=='Q')
                return false;
        }

        for(r=row-1, c = col-1;r>=0&&c>=0;r--,c--){
            if(nQueens[r][c]=='Q')
                return false;
        }

        for(r=row-1, c = col+1;r>=0&&c<=n-1;r--,c++){
            //这一列不能存在其他皇后而且对角线不能有皇后（斜率不等于1/-1）
            if(nQueens[r][c]=='Q')
                return false;
        }

        return true;



    }


};

/*
 *
 * Ver2
 *
 *
 *
 * */

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> nQueens(n,-1);
        solve(res,nQueens,0,n);
        return res;

    }

    void solve(vector<vector<string> >&res,vector<int> &nQueens,int row,int &n){
        //quit 来到了最后一行，证明已经找到解
        if(row==n){
            vector<string> temp(n,string(n,'.'));
            for(int i=0;i<n;i++){
                //nQueens[i]表示第i行皇后所在的列
                temp[i][nQueens[i]] = 'Q';
            }
            res.push_back(temp);
            return;
        }
        for(int col=0;col!=n;col++){
            if(isValid(nQueens,row,col,n)){
                //按列来摆好，如果这一列可以摆，那就移到下一行（递归）
                nQueens[row]=col;
                solve(res,nQueens,row+1,n);
                //回溯，说明刚才那一列不能摆，继续这个循环
                nQueens[row]=-1;
            }
        }
    }

    bool isValid(vector<int> &nQueens,int row,int col,int &n){

        //针对某一列，遍历所有行看他是否满足资格
        int r,c;

        for(r=0;r<row;r++){
            //看这一列是否有其他皇后或者经过该点的对角线上是否有其他皇后
            if(col==nQueens[r]||abs(r-row)==abs(nQueens[r]-col))
                return false;
        }

        return true;



    }


};