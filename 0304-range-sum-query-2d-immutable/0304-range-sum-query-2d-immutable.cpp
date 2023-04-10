class NumMatrix {

private:
    vector<vector<int>> ans;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        ans.resize(m+1, vector<int>(n+1, 0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                ans[i+1][j+1] = ans[i][j+1] + ans[i+1][j] - ans[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int tot = ans[row2+1][col2+1];
        int left = ans[row2+1][col1];
        int upper = ans[row1][col2+1];
        int leftOut = ans[row1][col1];
        
        return tot - left - upper + leftOut;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */