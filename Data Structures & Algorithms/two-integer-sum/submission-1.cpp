class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int req=target-nums[i];
            if(um.find(req)!=um.end() && um[req]!=i){
                return {i,um[req]};
            }
        }
        return {-1,-1};
    }
};
