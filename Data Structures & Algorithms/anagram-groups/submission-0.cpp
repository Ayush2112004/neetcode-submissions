class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> um;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            um[sorted].push_back(strs[i]);
        }
        for(auto& it: um){
            res.push_back(it.second);
        }
        return res;
    }
};
