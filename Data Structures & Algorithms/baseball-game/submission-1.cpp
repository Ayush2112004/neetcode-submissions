class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n=operations.size();
        for(int i=0;i<n;i++){
            if(operations[i]!="+" && operations[i]!="D" && operations[i]!="C"){
                st.push(stoi(operations[i]));
            }
            else if(operations[i]=="+"){
                int s1=st.top();
                st.pop();
                int s2=st.top();
                st.pop();
                int sum=s1+s2;
                st.push(s2);
                st.push(s1);
                st.push(sum);
            }
            else if(operations[i]=="D"){
                int t=st.top();
                st.pop();
                int d=2*t;
                st.push(t);
                st.push(d);
            }
            else{
                st.pop();
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};