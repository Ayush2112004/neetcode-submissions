class Solution {
public:
    int solve(vector<int>& prices,int n,int buy,int i,vector<vector<int>>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit=0;
        if(buy){
            profit=max(-prices[i]+solve(prices,n,0,i+1,dp),solve(prices,n,1,i+1,dp));
        }
        else{
            profit=max(prices[i]+solve(prices,n,1,i+1,dp),solve(prices,n,0,i+1,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,n,1,0,dp);
    }
};