class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                curr++;
            }
            else{
                maxi=max(curr,maxi);
                curr=0;
            }
        }
        maxi=max(curr,maxi);
        return maxi;
    }
};