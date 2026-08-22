class Solution {
public:
    int solve(vector<int>& nums,int idx,int jumps,int n,vector<vector<int>>& dp){
        if(idx>=n-1){
            return jumps;
        }
        if(dp[idx][jumps]!=-1){
            return dp[idx][jumps];
        }
        int mini=INT_MAX;
        for(int i=1;i<=nums[idx];i++){
            mini=min(mini,solve(nums,idx+i,jumps+1,n,dp));
        }
        return dp[idx][jumps] = mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,0,0,n,dp);
    }
};
