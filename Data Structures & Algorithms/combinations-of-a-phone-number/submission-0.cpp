class Solution {
public:
    void solve(string digits,string mapping[],string& output,vector<string>& ans,int idx){
        if(idx>=digits.size()){
            ans.push_back(output);
            return ;
        }
        int dig=digits[idx]-'0';
        string value=mapping[dig];
        for(int i=0;i<value.size();i++){
            output.push_back(value[i]);
            solve(digits,mapping,output,ans,idx+1);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string output;
        vector<string> ans;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,mapping,output,ans,0);
        return ans;
    }
};
