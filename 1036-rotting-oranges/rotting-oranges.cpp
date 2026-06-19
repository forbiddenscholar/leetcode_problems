class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int tm = 0;

        int m = grid.size();
        int n = grid[0].size();

        // {{r, c}, tm}
        queue <pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else{
                    visited[i][j] = 0; 
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            tm = max(t, tm);
            q.pop();

            int drow[] = {0, -1, 0, +1};
            int dcol[] = {-1, 0, +1, 0};

            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(ncol >= 0 && nrow >= 0 && ncol<n && nrow<m && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t+1});
                    visited[nrow][ncol] = 2;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && visited[i][j] != 2){
                    return -1;
                }
            }
        }

        return tm;
    }
};