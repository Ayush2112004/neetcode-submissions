class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(int i:nums){
            st.insert(i);
        }
        for(int i=1;i<=n;i++){
            if(!st.count(i)){
                return i;
            }
        }
        return 0;
    }
};
