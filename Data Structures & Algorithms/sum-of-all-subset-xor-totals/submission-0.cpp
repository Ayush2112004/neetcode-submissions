class Solution {
public:
    int sum=0;
    void solve(vector<int>& nums,int n,int i,int mul){
        if(i>=n){
            sum+=mul;
            return ;
        }
        solve(nums,n,i+1,mul^nums[i]);
        solve(nums,n,i+1,mul);
    }
    int subsetXORSum(vector<int>& nums) {
        int mul=0;
        int n=nums.size();
        solve(nums,n,0,mul);
        return sum;
    }
};