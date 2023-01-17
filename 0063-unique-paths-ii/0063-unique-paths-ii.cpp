class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, 0));
        ans[0][0] = 1;
        if(grid[0][0] == 1)
            return 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(i + j == 0)
                    continue;
                if(grid[i][j] == 1)
                {
                    ans[i][j] = 0;
                    continue;
                }
                ans[i][j] = (i == 0 ? 0 : ans[i-1][j]) 
                           +(j == 0 ? 0 : ans[i][j-1]);
            }
        }
        return ans[n-1][m-1];
    }
};