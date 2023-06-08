class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), ans = 0;
        
        int i = 0, j = col - 1;
        
        while(i < row and j > -1){
            if(grid[i][j] < 0){
                ans += row - i;
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};