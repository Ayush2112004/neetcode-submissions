class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(m<n){
            return false;
        }
        vector<int> count1(26,0);
        for(int i=0;i<n;i++){
            count1[s1[i]-'a']++;
        }
        vector<int> count2(26,0);
        int l=0;
        int r=0;
        while(r<n){
            count2[s2[r]-'a']++;
            r++;
        }
        while(r<m){
            if(count1==count2){
                return true;
            }
            else{
                count2[s2[l]-'a']--;
                l++;
            
                count2[s2[r]-'a']++;
                r++;
            }
        }
        return (count1==count2);
    }
};
