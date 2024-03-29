class Solution {
public:
    vector<int> isGood;
    bool dfs(int node, vector<vector<int>>& adj, set<int>& ans, vector<int>& vis){
        
        bool ok = true;
        //if(isGood[node] == 2) return true;
        if(isGood[node] == 0) 
            isGood[node] = 1;
        
        vis[node] = 1;
        for(auto u : adj[node]){
            
            if(vis[u] == 1) ok = false;
            if(isGood[u] != 0) ok = ok & (isGood[u] == 2);
            if(!ok) break;
            else if(vis[u] == 0) ok = ok & dfs(u, adj, ans, vis);
            
        }
        if(ok == true and ans.count(node) == 0) {ans.insert(node); isGood[node] = 2;}
        vis[node] = 2; 
        return ok;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // vector<vector<int>> adj(n);
        // for(auto i : graph) adj[i[0]].push_back(i[1]);
        vector<int> vis(n, 0);
        isGood.resize(n, 0);
        set<int> ans;
        
        for(int i = 0 ; i < n ; i++)
            if(graph[i].size() == 0) {isGood[i] = 2; ans.insert(i); vis[i] = 2;}

        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 0) {
                //cout << i << " " << vis[i] << " " << vis[i+1] << endl;
                dfs(i, graph, ans, vis);
            }
        }
        vector<int> ret(ans.begin(), ans.end());
        return ret;
    }
};