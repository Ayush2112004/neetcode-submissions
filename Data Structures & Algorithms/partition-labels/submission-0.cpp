class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int> um;
        for(int i=n-1;i>=0;i--){
            if(um.find(s[i])!=um.end()){
                continue;
            }
            um[s[i]]=i;
        }
        vector<int> ans;
        int i=0;
        while(i<n){
            int start=i;
            int end=um[s[i]];
            for(int j=start;j<=end;j++){
                if(um[s[j]]>end){
                    end=um[s[j]];
                }
            }
            ans.push_back(end-start+1);
            i=end+1;
        }
        return ans;
    }
};
