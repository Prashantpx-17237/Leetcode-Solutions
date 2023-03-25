class Solution {
public:
    
    int dfs(vector<vector<int>>& adj, vector<bool>& vis, int node){
        
        int count = 1;
        vis[node] = true;
        
        for(auto u : adj[node]){
            if(!vis[u]){
                count += dfs(adj, vis, u);
            }
        }
        return count;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        vector<long long> sz;
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i])
                sz.push_back(dfs(adj, vis, i));
        }
        long long sum = 0;
        for(auto i : sz) sum += i;
        long long ans = 0;
        
        for(auto i : sz){
            sum -= i;
            ans += (i * sum);
        }
        return ans;
    }
};