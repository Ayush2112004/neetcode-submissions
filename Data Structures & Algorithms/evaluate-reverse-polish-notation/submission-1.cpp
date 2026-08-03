class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int res=0;
        for(int i=0;i<tokens.size();i++){
            if (tokens[i] != "+" && tokens[i] != "-" &&
                tokens[i] != "*" && tokens[i] != "/") {
                st.push(stoi(tokens[i]));
            }
            else if(tokens[i]=="+"){
                int sum=0;
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                sum=a+b;
                st.push(sum);
            }
            else if(tokens[i]=="*"){
                int mul=1;
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                mul=a*b;
                st.push(mul);
            }
            else if(tokens[i]=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b/a);
            }
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);
            }
        }
        return st.top();
    }
};
