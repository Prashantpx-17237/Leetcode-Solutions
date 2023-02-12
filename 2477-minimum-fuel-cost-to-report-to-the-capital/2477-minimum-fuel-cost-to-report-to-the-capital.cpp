class Solution {
public:
    
    long long dfs(int node, vector<vector<int>>& adj, vector<int>& sz, int seats, vector<bool>& vis)
    {
        long long val = 0;
        for(auto i : adj[node])
        {
            if(vis[i] == false)
            {
                vis[i] = true;
                val += dfs(i, adj, sz, seats, vis);
                sz[node] += sz[i];
                val += (sz[i] + seats - 1) / seats ; 
            }
        }
        return val;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        
        vector<vector<int>> G(n);
        
        for(auto i : roads)
        {
            G[i[0]].push_back(i[1]);
            G[i[1]].push_back(i[0]);
        }
        vector<int> sz(n, 1);
        vector<bool> vis(n, false); vis[0] = true;
        long long ans = dfs(0, G, sz, seats, vis);
        return ans;
    }
};