class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        // q {row, col}
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // if the element is 1 and not visited, push it in q
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    vis[i][j] = 1;
                    q.push({i, j});
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;

                        q.pop();

                        // check all adjacent nodes if 1 and not visited then push
                        int drow[4] = {0, -1, 0, 1};
                        int dcol[4] = {-1, 0, 1, 0};

                        for(int i=0; i<4; i++){
                            int nrow = row + drow[i];
                            int ncol = col + dcol[i];

                            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                                vis[nrow][ncol] = 1;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};