class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int curr=0;
        int len=0;
        int ans=0;
        for(int x:nums){
           
            if(st.find(x-1)==st.end()){
                curr=x;
                len=1;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    len++;
                }
            }

            ans=max(ans,len);
        }
        return ans;
    }
};
