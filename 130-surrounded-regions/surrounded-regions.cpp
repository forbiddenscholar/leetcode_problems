class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // put the boundary zeros into queue and mark them as not to be converted and their neighbours too
        // lastly convert all the remaining zeros to x
        int m = board.size();
        int n = board[0].size();

        // q{row, col}
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && board[i][j] == 'O'){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            int drow[4] = {0, -1, 0, 1};
            int dcol[4] = {-1, 0, 1, 0};

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }

};