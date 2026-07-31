class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        vector<int> hash(26);
        int maxLen=0;
        int maxFreq=0;
        while(r<n){
            hash[s[r]-'A']++;
            maxFreq=max(maxFreq,hash[s[r]-'A']);
            int window=r-l+1;
            if(window-maxFreq>k){
                hash[s[l]-'A']--;
                l++;

            }
            window=r-l+1;
            maxLen=max(maxLen,window);
            r++;
        }
        return maxLen;
        
    }
};
