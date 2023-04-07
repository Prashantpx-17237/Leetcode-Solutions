class Solution {
public:
    int dir[2][4] = {{1, 0, -1, 0}, {0, -1, 0, 1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 or j == 0 or j == m - 1 or i == n - 1){
                    if(grid[i][j] == 1 and !vis[i][j]){
                        dfs(i, j, grid, vis);
                    }
                }
            }
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 and vis[i][j] == false)
                    count++;
            }
        }
        return count;
    }
    
    bool valid(int i, int j, int n, int m){
        return (i > -1 and j > -1 and i < n and j < m);
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        int n = grid.size(), m = grid[0].size();
        
        if(grid[i][j] != 1)
            return;
        
        vis[i][j] = true;
        
        for(int k = 0 ; k < 4 ; k++){
            int ni = i+dir[1][k], nj = j+dir[0][k];
            if(valid(ni, nj, n, m) and grid[ni][nj] == 1 and !vis[ni][nj])
                dfs(ni, nj, grid, vis);
        }
        return;
    }
};