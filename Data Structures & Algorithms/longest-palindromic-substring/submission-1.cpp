class Solution {
public:
    string expand(int left,int right,int n,string& s){
        //we just expand the string from its center and check for palindrome substr and if its palindrome then return the substring
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1){
            return s;
        }
        string max_str=s.substr(0,1);
        for(int i=0;i<n-1;i++){
            //in odd we have to start the left and r from the same point and in even left and right from diff because of the indexes so we will take both the case and take the max one 
            string odd=expand(i,i,n,s);
            string even=expand(i,i+1,n,s);
            if(odd.size()>max_str.size()){
                max_str=odd;
            }
            if(even.size()>max_str.size()){
                max_str=even;
            }
        }
        return max_str;
    }
};
