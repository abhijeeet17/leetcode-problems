class Solution {
public:
    bool isValid(vector<vector<char>>& b, int r, int c, char x) {
        for(int i = 0; i < 9; i++) {
            if(b[r][i] == x) return false;
            if(b[i][c] == x) return false;
            if(b[3*(r/3) + i/3][3*(c/3) + i%3] == x) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& b) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(b[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isValid(b, i, j, ch)) {
                            b[i][j] = ch;
                            
                            if(solve(b)) return true;
                            
                            b[i][j] = '.'; // backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};