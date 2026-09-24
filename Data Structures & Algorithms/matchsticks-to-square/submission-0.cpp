class Solution {
public:
    bool solve(vector<int>& matchsticks,vector<int>& sides,int i,int side_length,int n){
        if(i>=n){
            return true;
        }
        for(int j=0;j<4;j++){
            if(sides[j]+matchsticks[i]<=side_length){
                sides[j]+=matchsticks[i];
                if(solve(matchsticks,sides,i+1,side_length,n)){
                    return true;
                }
                sides[j]-=matchsticks[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        int perimeter=0;
        for(int i=0;i<n;i++){
            perimeter+=matchsticks[i];
        }
        if(perimeter%4!=0){
            return false;
        }
        int side_length=perimeter/4;
        vector<int> sides(4,0);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return solve(matchsticks,sides,0,side_length,n);
    }
};