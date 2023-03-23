class Solution {
public:
    
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node){
        vis[node] = true;
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(adj, vis, i);
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int count = 0;
        vector<vector<int>> adj(n);
        for(auto i : connections){
            count++;
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        if(count < n - 1)
            return -1;
        vector<bool> vis(n, false);
        int noc = 0;
        for(int i = 0 ; i < n ; i++){
            
            if(!vis[i]){
                
                vis[i] = true;
                dfs(adj, vis, i);
                noc++;
            }
        }
        return noc - 1;
    }
};