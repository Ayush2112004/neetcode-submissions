class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outDegree(n,0);
        vector<int> inDegree(n,0);
        for(auto& t:trust){
            int a=t[0];
            int b=t[1];
            outDegree[a-1]++;
            inDegree[b-1]++;
        }
        for(int i=0;i<n;i++){
            if(outDegree[i]==0 && inDegree[i]==n-1){
                return i+1;
            }
        }
        return -1;
    }
};