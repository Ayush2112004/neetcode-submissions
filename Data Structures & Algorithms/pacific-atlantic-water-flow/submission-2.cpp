class Solution {
public:
    void solve(vector<vector<int>>& heights,int i,int j,int prev,vector<vector<int>>& ocean){
        int n=heights.size();
        int m=heights[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return;
        }
        if(heights[i][j]<prev){
            return;
        }
        if(ocean[i][j] == 1) return;
        ocean[i][j]=1;
        solve(heights,i+1,j,heights[i][j],ocean);
        solve(heights,i-1,j,heights[i][j],ocean);
        solve(heights,i,j+1,heights[i][j],ocean);
        solve(heights,i,j-1,heights[i][j],ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.size()<=1){
            return {{0,0}};
        }
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            solve(heights,0,i,INT_MIN,pacific);
            solve(heights,n-1,i,INT_MIN,atlantic);
        }
        for(int i=0;i<n;i++){
            solve(heights,i,0,INT_MIN,pacific);
            solve(heights,i,m-1,INT_MIN,atlantic);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
         
            for(int j=0;j<m;j++){
            
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
