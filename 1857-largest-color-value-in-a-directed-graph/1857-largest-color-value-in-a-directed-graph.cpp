class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        
        vector<vector<int>> adj(n);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> vis(n, 0);
        vector<vector<int>> count(n, vector<int>(26, 0));
        int ans = -1;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans, dfs(adj, colors, i, vis, count));
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
private:
    int dfs(vector<vector<int>>& adj, string& colors, int u, vector<int>& vis, vector<vector<int>>& count){
        if(vis[u] == 1)
            return INT_MAX;
        if(vis[u] == 2) return count[u][colors[u]-'a'];
        
        vis[u] = 1;
        
        for(auto v : adj[u]){
            int val = dfs(adj, colors,  v, vis, count);
            //cout << "val = " << val << endl;
            if(val == INT_MAX) return INT_MAX;
            for(int i = 0 ; i < 26 ; i++){
                count[u][i] = max(count[u][i], count[v][i]);
            }
        }
        count[u][colors[u]-'a']++;
        vis[u] = 2;
        return count[u][colors[u]-'a'];
    }
    
};