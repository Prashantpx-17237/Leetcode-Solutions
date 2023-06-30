class Solution {
public:
    
    bool check(int day, vector<vector<int>>& cells, int row, int col){
        vector<vector<int>> grid(row, vector<int> (col, 1));
        
        for(int i = 0 ; i < day; i++){
            grid[cells[i][0]-1][cells[i][1]-1] = 0;
        }
        vector<vector<bool>> vis(row, vector<bool> (col, false));
        queue<pair<int, int>> q;
        for(int i = 0 ; i < col ; i++){
            vis[0][i] = true;
            if(grid[0][i] != 0) q.push({0, i});
        }
        int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
        while(!q.empty()){
            
            auto [x, y] = q.front();
            if(x == row - 1) return true;
            q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dir[0][i], ny = y + dir[1][i];
                if(nx < row and nx > -1 and ny > -1 and ny < col){
                    if(grid[nx][ny] == 1 && !vis[nx][ny]){
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                        if(nx == row - 1) return true;
                    }
                }
            }
        }
            
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = -1, high = row * col;
        
        // low holds <= 
        // high holds >
        
        while(low + 1 < high){
            
            int mid = low + (high - low) / 2;
            if(check(mid, cells, row, col))
                low = mid;
            else
                high = mid;
        }
        
        return low;
    }
};