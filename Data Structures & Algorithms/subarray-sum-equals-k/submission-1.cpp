class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        int count=0;
        unordered_map<int,int> um;
        um[0]=1;
        for(int i=0;i<n;i++){
            if(um.find(pref[i]-k)!=um.end()){
                count+=um[pref[i]-k];
            }
            um[pref[i]]++;
        }
        return count;
    }
};