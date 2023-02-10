class Solution {
public:
    
    bool valid(int x, int y, int n)
    {
        return (x > -1 and y > -1 and x < n and y < n);
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<int> vis(n*n, -1);
        queue<int> q;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 1)
                {
                    vis[n * i + j] = 0;
                    q.push(n * i + j);
                }
            }
        }
        
        
        if(q.size() == 0 or q.size() == n * n)
            return -1;
        
        int dir[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
        int ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++)
            {
                int cordinate = q.front();
                int x = cordinate / n;
                int y = cordinate - x * n;
                q.pop();
                for(int k = 0 ; k < 4 ; k++)
                {
                    int cord = (x + dir[0][k]) * n + (y + dir[1][k]);
                    
                    if(valid(x+dir[0][k], y+dir[1][k], n) and vis[cord] == -1)
                    {
                        vis[cord] = vis[cordinate] + 1;
                        ans = max(ans, vis[cord]);
                        q.push(cord);
                    }
                }
            }
        }
        return ans;
    }
};