class Solution {
public:
    bool strs(string& s1,string& s2){
        int i=0;
        int j=s2.size()-1;
        if(s1.size()!=s2.size()){
            return false;
        }
        while(i<s1.size() && j>=0){
            if(tolower(s1[i])!=tolower(s2[j])){
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<j){
            while(i<j && !isalnum(s[i])) i++;
            while(i<j && !isalnum(s[j])) j--;
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            else{
                i++;j--;
            }
        }
        return true;
    }
};
