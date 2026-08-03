class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int> hash(256,0);
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        int minLen=INT_MAX;
        int idx=-1;
        int l=0;
        int r=0;
        int cnt=0;
        while(r<n){
            hash[s[r]]--;
            if(hash[s[r]]>=0){
                cnt++;
               
            }
            while(cnt==m){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    idx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        if(idx==-1) return "";
        string res=s.substr(idx,minLen);
        return res;
    }
};
