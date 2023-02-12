class Solution {
public:
    
    long long dfs(int node, vector<vector<int>>& adj, vector<int>& sz, int seats, int par)
    {
        long long val = 0;
        for(auto i : adj[node])
        {
            if(i != par)
            {
                val += dfs(i, adj, sz, seats, node);
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
        
        long long ans = dfs(0, G, sz, seats, -1);
        return ans;
    }
};