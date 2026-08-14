class Solution {
public:
    int solve(string s,int i,vector<int>& dp){
        if(s[i]=='0'){
            return 0;
        }
        if(i==s.size()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=solve(s,i+1,dp);
        int two=0;
        if(i+1<s.size()){
            int num=(s[i]-'0')*10+(s[i+1]-'0');
            if(num>=10 && num<=26){
                two=solve(s,i+2,dp);
            }
        }
        return dp[i]= one+two;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(s,0,dp);
    }
};
