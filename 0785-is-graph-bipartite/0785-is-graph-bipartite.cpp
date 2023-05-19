class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color){
        bool ok = true;
        for(auto v : graph[node]){
            if(color[v] == color[node])
                return false;
            if(color[v] == -1){
                color[v] = 1 - color[node];
            
                ok &= dfs(v, graph, color);
            }
        }
        return ok;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};