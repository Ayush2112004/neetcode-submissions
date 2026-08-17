class Solution {
public:
    int squareAdd(int n){
        int s=0;
        while(n>0){
            int rem=n%10;
            s+=(rem*rem);
            n=n/10;
        }
        return s;
    }
    bool isHappy(int n) {
       
        unordered_set<int> st;
        while(n!=1){
            if(st.count(n)){
                return false;
            }
            st.insert(n);
            n=squareAdd(n);
        }
        return true;
    }
};
