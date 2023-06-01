class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        vector<vector<int>> vis(n, vector<int>(n, -1));
        
    int dir[2][8] = {{0, 0, 1, 1, 1, -1, -1, -1}, 
                     {1, -1, 0, 1, -1, 0, 1, -1}};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            
            for(int i = 0 ; i < 8; i++){
                int nx = x+dir[0][i], ny = y+dir[1][i];
                if((nx < n and nx > -1 and ny > -1 and ny < n) and vis[nx][ny] == -1 and grid[nx][ny] == 0){
                    q.push({nx, ny});
                    vis[nx][ny] = vis[x][y]+1;
                }
            }
        }
        return vis[n-1][n-1];
    }
};