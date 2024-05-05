Question Link : https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    
    #define ll long long
    
    vector<int> seg;
    int n;
    
    void buildTree(int low , int high , int idx, vector<int>& nums){
        if(low==high){
            seg[idx]=nums[low]; // leaf node
            return;
        }
        
        int mid = low+(high-low)/2;
        
        buildTree(low, mid, 2*idx+1, nums);
        buildTree(mid+1, high, 2*idx+2, nums);
        
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    
    void updateTree(int low , int high , int idx, int i, int val){
        if(low==high){
            seg[idx]=val;
            return;
        }
        
        int mid = low+(high-low)/2;
        
        if(i<=mid){
            updateTree(low,mid,2*idx+1,i,val);
        }else{
            updateTree(mid+1,high,2*idx+2,i,val);
        }
        
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    
    int sum(int low , int high , int idx, int lb, int ub){
        // complete overlap
        if(low>=lb && high<=ub) return seg[idx];
        
        // no overlap
        if(high<lb || low>ub) return 0;
        
        // partial overlap
        int mid = low+(high-low)/2;
        
        int l = sum(low, mid, 2*idx+1, lb, ub);
        int r = sum(mid+1, high, 2*idx+2, lb, ub);
        
        return l+r;
    }
    
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n);
        buildTree(0, n-1, 0, nums);
    }
    
    void update(int index, int val) {
        updateTree(0, n-1, 0, index, val);
    }
    
    int sumRange(int left, int right) {
        return sum(0, n-1, 0, left, right);
    }
};
