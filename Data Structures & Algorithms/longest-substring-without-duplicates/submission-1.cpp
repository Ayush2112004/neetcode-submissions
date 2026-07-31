class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> um;
        int l=0;
        int n=s.size();
        int r=0;
        int len=0;
        while(r<n){
            if(um.find(s[r])!=um.end()){
                l=max(l,um[s[r]]+1);
                
            }
            len=max(len,r-l+1);
            um[s[r]]=r;
            r++;
        }
        return len;
    }
};
