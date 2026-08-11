class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vis[i][j]=true;
                    q.push({i,j});
                    int area=1;
                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(int x=0;x<4;x++){
                            int nrow=r+delrow[x];
                            int ncol=c+delcol[x];
                            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                                q.push({nrow,ncol});
                                vis[nrow][ncol]=true;
                                area++;
                            }
                        }
                    }
                    maxArea=max(maxArea,area);
                }
            }
            
        }
        return maxArea;
    }
};
