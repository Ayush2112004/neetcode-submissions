class Solution {
public:
    void solve(vector<int>& candidates,vector<int>& ans,vector<vector<int>>& res,int i,int sum,int target){
        if(sum==target){
            res.push_back(ans);
            return ;
        }
        if(i>=candidates.size() || sum>target){
            if(sum==target){
                res.push_back(ans);
            }
            return ;
        }
        ans.push_back(candidates[i]);
        solve(candidates,ans,res,i+1,sum+candidates[i],target);
        ans.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]){
            i++;
        }
        solve(candidates,ans,res,i+1,sum,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        vector<vector<int>> res;
        solve(candidates,ans,res,0,0,target);
        return res;
    }
};
