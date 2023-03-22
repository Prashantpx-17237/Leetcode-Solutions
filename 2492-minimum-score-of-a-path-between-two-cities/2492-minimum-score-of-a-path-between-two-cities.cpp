class Solution {
public:
    vector<vector<vector<int>>> G;
    vector<int> vis;
    
    void dfs(vector<vector<pair<int, int>>>& adj, int node, int &ans, int n, vector<bool>& vis){
        for(auto edge : adj[node]){
            ans = min(ans, edge.second);
            if(!vis[edge.first]){
                vis[edge.first] = true;
                dfs(adj, edge.first, ans, n, vis);
            }
        }
        return;
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<bool> vis(n+1, false);
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        vis[1] = true;
        dfs(adj, 1, ans, n, vis);
        return ans;
    }
};