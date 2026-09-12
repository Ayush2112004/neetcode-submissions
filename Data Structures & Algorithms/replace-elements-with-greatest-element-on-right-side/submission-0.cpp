class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        ans[n-1]=-1;
        int curr=arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i]>curr){
                ans[i]=curr;
                curr=arr[i];
            }
            else{
                ans[i]=curr;
            }
        }
        return ans;
    }
};