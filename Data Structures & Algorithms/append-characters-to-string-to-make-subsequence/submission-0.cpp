class Solution {
public:
    void isSubsequence(string s, string t, int& i, int& j) {
        int n1 = s.size();
        int n2 = t.size();

        while(i < n1 && j < n2) {
            if(s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                i++;              // changed: j++ → i++
            }
        }
    }

    int appendCharacters(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        int i = 0;
        int j = 0;
        int ans = 0;

        isSubsequence(s, t, i, j);  // changed: always s, t

        if(j < n2) {
            ans = ans + (n2 - j);   // changed: n2-i → n2-j
        }

        return ans;
    }
};