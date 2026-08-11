class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
