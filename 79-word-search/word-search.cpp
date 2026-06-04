class Solution {
private:
    bool backtrack(int idx, int i, int j, vector<vector<char>>& grid, string s){
        if(idx == s.size())
            return true;
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || s[idx] != grid[i][j])
            return false;
        
        char temp = grid[i][j];
        grid[i][j] = '#';

        bool found = (backtrack(idx+1, i+1, j, grid, s) ||
         backtrack(idx+1, i-1, j, grid, s) || 
         backtrack(idx+1, i, j+1, grid, s) || 
         backtrack(idx+1, i, j-1, grid, s));
        
        grid[i][j] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(word[0] == board[i][j]){
                    ans = backtrack(0, i, j, board, word);
                    if(ans == true)
                        return true;
                }
            }
        }
        return ans;
    }
};