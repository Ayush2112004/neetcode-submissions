class Solution {
public:
    int solve(vector<int>& nums, int target, int i,
              vector<vector<int>>& dp, int offset) {

        if(i == nums.size()) {
            if(target == 0) {
                return 1;
            }
            return 0;
        }

        // Prevent target + offset from going outside dp
        if(target > offset || target < -offset) {
            return 0;
        }

        if(dp[i][target + offset] != -1) {
            return dp[i][target + offset];
        }

        int add = solve(nums, target - nums[i], i + 1, dp, offset);
        int sub = solve(nums, target + nums[i], i + 1, dp, offset);

        return dp[i][target + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for(int x : nums) {
            sum += x;
        }

        if(abs(target) > sum) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

        return solve(nums, target, 0, dp, sum);
    }
};