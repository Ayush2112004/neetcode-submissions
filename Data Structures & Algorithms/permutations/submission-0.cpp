class Solution {
public:
    void solve(vector<int>& nums,int i,vector<vector<int>>& ans,int n){
        if(i>=n){
     
                ans.push_back(nums);
            
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            solve(nums,i+1,ans,n);
            swap(nums[i],nums[j]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        solve(nums,0,ans,n);
        return ans;
    }
};
