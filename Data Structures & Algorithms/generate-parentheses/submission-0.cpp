class Solution {
public:
    void generate(int n,vector<string>& arr,string curr,int open,int close){
        if(curr.size()==2*n){
            arr.push_back(curr);
            return;
        }
        if(open<n) generate(n,arr,curr+'(',open+1,close);
        if(close<open) generate(n,arr,curr+')',open,close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n,ans,"",0,0);
        return ans;
    }
};
