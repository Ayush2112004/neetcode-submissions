class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,int row,int col){
        vis[row][col]=true;
        int n=board.size();
        int m=board[0].size();
        int delrow[]={1,0,-1,0};
        int delcol[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(board,vis,nrow,ncol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(board,vis,0,i);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(board,vis,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(board,vis,i,0);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(board,vis,i,m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
