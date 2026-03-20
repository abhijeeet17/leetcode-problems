class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        vector<set<char>> r(9), c(9), box(9);
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(b[i][j] == '.') continue;
                
                char x = b[i][j];
                int k = (i/3)*3 + (j/3);
                
                if(r[i].count(x) || c[j].count(x) || box[k].count(x))
                    return false;
                
                r[i].insert(x);
                c[j].insert(x);
                box[k].insert(x);
            }
        }
        return true;
    }
};