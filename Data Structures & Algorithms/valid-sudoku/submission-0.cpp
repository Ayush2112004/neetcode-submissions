class Solution {
public:
    bool isRowSame(vector<vector<char>>& board,int row){
        unordered_map<int,int> um;
        for(int i=0;i<9;i++){
            if(isalnum(board[row][i])){
                um[board[row][i]-'0']++;
            }
        }
        for(auto it:um){
            if(it.second>1){
                return true;
            }
        }
        return false;
    }
    bool isColSame(vector<vector<char>>& board,int col){
        unordered_map<int,int> um;
        for(int i=0;i<9;i++){
            if(isalnum(board[i][col])){
                um[board[i][col]-'0']++;
            }
        }
        for(auto it:um){
            if(it.second>1){
                return true;
            }
        }
        return false;
    }
    bool isBoxSame(vector<vector<char>>& board, int row, int col) {
        unordered_map<int, int> um;

        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (isdigit(board[i][j])) {
                    um[board[i][j] - '0']++;
                }
            }
        }

        for (auto it : um) {
            if (it.second > 1) {
                return true;
            }
        }

        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (isRowSame(board, i)) {
                return false;
            }
        }

        // Columns
        for (int i = 0; i < 9; i++) {
            if (isColSame(board, i)) {
                return false;
            }
        }

        // 3x3 boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (isBoxSame(board, i, j)) {
                    return false;
                }
            }
        }

        return true;
    }
};
