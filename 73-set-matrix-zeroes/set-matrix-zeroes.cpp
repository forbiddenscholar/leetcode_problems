class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // store row and col indices to be zeroed
        vector <bool> rows(m, false);
        vector <bool> cols(n, false);

        // find zeros
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0)
                    rows[i] = cols[j] = true;
            }
        }

        // now zero them
        // firstly rowsyou swapped your indices
        for(int i=0; i<m; i++){
            if(rows[i] == true)
                for(int col=0; col<n; col++)
                    matrix[i][col] = 0;
        }

        // secondly cols
        for(int j=0; j<n; j++){
            if(cols[j] == true)
                for(int row=0; row<m; row++)
                    matrix[row][j] = 0;
        }
    }
};