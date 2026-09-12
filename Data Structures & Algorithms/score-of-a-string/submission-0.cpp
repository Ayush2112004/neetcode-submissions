class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size();
        int i=0;
        int j=1;
        int ans=0;
        while(j<n){
            int res=abs(s[j]-s[i]);
            ans+=res;
            j++;
            i++;

        }
        return ans;
    }
};