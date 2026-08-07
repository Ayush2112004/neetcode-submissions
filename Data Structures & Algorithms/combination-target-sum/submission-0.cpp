class Solution {
public:
    void solve(vector<int>& nums,int target,int i,vector<int>& ans,vector<vector<int>>& res){
        int n=nums.size();
        if(i==n){
            if(target==0){
                res.push_back(ans);
                return ;
            }
            else{
                return ;
            }
        }
        if(nums[i]<=target){
            ans.push_back(nums[i]);
            solve(nums,target-nums[i],i,ans,res);
            ans.pop_back();
        }
        solve(nums,target,i+1,ans,res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<vector<int>> res;
        solve(nums,target,0,ans,res);
        return res;
    }
};
