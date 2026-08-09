class Solution {
public:
    void subset(vector<int>& nums,int i,int n,vector<int>& ans,vector<vector<int>>& res){
        if(i>=n){
            res.push_back(ans);
            return ;
        }
        //take
        ans.push_back(nums[i]);
        subset(nums,i+1,n,ans,res);
        ans.pop_back();
        //not take
        subset(nums,i+1,n,ans,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        int n=nums.size();
        subset(nums,0,n,ans,res);
        return res;
    }
};
