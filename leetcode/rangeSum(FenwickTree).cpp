class NumArray {

private:
    vector<int>_nums;
    //tree 的index比nums的相应后移一位
    vector<int>tree;
    int n;
public:

    NumArray(vector<int> nums) {
        n = nums.size();
        if(n==0)
            return;
        _nums = nums;
        tree.assign(n+1,0);
        constructTree();
    }

    void myUpdate(int i,int val){
        for(;i<=n;i+=i&(-i) ){
            tree[i]+=val;
        }
    }

    void update(int i, int val) {
        int diff = val-_nums[i];
        _nums[i] = val;
        myUpdate(i+1,diff);
    }

    void constructTree(){
        for(int i=0;i<n;i++){
            myUpdate(i+1,_nums[i]);
        }
    }

    int getSum(int idx)
    {
        int res= 0;
        for(int i=idx;i>0;i-=i&(-i)){
            res+=tree[i];
        }
        return res;
    }
    int sumRange(int i, int j) {
        return getSum(j+1)-getSum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */