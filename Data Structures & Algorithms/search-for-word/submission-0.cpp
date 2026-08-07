class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,vector<vector<bool>>& vis,int x,int y,int i){
        if(i==word.size()-1){
            return true;
        }
        vis[x][y]=true;
        int n=board.size();
        int m=board[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        for(int idx=0;idx<4;idx++){
            int nrow=x+delrow[idx];
            int ncol=y+delcol[idx];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]==word[i+1]){
                if(dfs(board,word,vis,nrow,ncol,i+1)==true){
                    return true;
                    break;
                }
            }
        }
        vis[x][y]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,vis,i,j,0)==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
