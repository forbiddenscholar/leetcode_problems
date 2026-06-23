class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int toChange = image[sr][sc];

        if(image[sr][sc] == color)
            return image; 
        

        int m = image.size();
        int n = image[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({sr, sc});
        visited[sr][sc] = true;
        image[sr][sc] = color;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            int drow[4] = {0, -1, 0, 1};
            int dcol[4] = {-1, 0, 1, 0};

            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r - drow[i];
                int ncol = c - dcol[i];

                if(nrow >= 0 && nrow < m && ncol >=0 && ncol <n && image[nrow][ncol] == toChange){
                    image[nrow][ncol] = color;
                    if(!visited[nrow][ncol]){
                        q.push({nrow, ncol});
                        visited[nrow][ncol] = true;
                    }
                }
            }
        }
        return image;

    }
};

