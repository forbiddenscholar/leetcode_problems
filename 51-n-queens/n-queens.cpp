class Solution {
private:
    bool isSafe(int row, int col, int n, vector <string>& curr){
        // check in the same col
        for(int i=0; i<row; i++)
            if(curr[i][col] == 'Q')
                return false;
        // check in the upper left diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j--)
            if(curr[i][j] == 'Q')
                return false;
        // check in the upper right diagonal
        for(int i=row, j=col; i>=0 && j<n; i--, j++)
            if(curr[i][j] == 'Q')
                return false;
        
        return true;
    }

    void solve(int row, int n, vector<vector<string>>& ans, vector<string>& curr){
        if(row == n){
            ans.push_back(curr);
            return;
        }
        for(int col=0; col<n; col++){
            if(isSafe(row, col, n, curr)){
                curr[row][col] = 'Q';
                solve(row+1, n, ans, curr);
                curr[row][col] = '.';
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr (n, string(n, '.'));
        solve(0, n, ans, curr);
        return ans;
    }
};