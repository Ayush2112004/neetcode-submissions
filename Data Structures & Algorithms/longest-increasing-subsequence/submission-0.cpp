class Solution {
public:
    int solve(vector<int>& nums,int i,int n,int prev,vector<vector<int>>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int nt=solve(nums,i+1,n,prev,dp);
        int take=0;
        if(prev==-1 || nums[i]>nums[prev]){
            take=1+solve(nums,i+1,n,i,dp);
        }
        return dp[i][prev+1]= max(nt,take);
    }
    int lengthOfLIS(vector<int>& nums) {
          int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
      
        return solve(nums,0,n,-1,dp);
    }
};
