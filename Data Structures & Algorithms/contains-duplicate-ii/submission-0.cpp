class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        unordered_set<int> st;
        int j=0;
        while(j<k && j<n){
            if(st.count(nums[j])){
                return true;
            }
            st.insert(nums[j]);
            j++;
        }
        while(j<n){

       
            if(st.count(nums[j])){
                return true;
            }
            st.insert(nums[j]);
            st.erase(nums[i]);
            i++;
            j++;
        }
        return false;
    }
};