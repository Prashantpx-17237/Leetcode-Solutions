class Solution {
public:
    
    int get(int i,  int j, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        if(i >= 0 and i < n and j >= 0 and j < m)
            return grid[i][j];
        return 10000005;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans[i][j] = grid[i][j];
                int val = min(get(i-1, j, ans), get(i, j-1, ans));
               
                if(val != 10000005) ans[i][j] += val;
                
            }
        }
        return ans[n-1][m-1];
    }
};