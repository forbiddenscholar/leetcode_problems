class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // queue {{r, c}}
        queue <pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cntGrid = 0, cntVis = 0;

        //put all the boundary 1's in the queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            int drow[4] = {0, -1, 0, 1};
            int dcol[4] = {-1, 0, 1, 0};

            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }

        }
        // now check how many 1's remained unvisited
           for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    cntGrid++;
                if(vis[i][j] == 1){
                    cntVis++;
                }
            }
           }
        return cntGrid - cntVis;
    }
};