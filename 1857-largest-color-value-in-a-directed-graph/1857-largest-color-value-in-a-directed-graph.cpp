class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<int> in(n, 0);
        vector<vector<int>> adj(n);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            in[edge[1]]++;
        }
        
        int ans = 0;         
        vector<int> tsort = topo(in, adj, ans, colors);
        if(tsort.size() != n) return -1;
        
        return ans;
    }
private:
    vector<int> topo(vector<int>& in, vector<vector<int>>& adj, int& ret, string& colors){
        vector<vector<int>> col(colors.length(), vector<int>(26, 0));
        queue<int> q;
        for(int i = 0 ; i < in.size() ; i++){
            if(in[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int u = q.front(); q.pop();
            ret = max(ret, ++col[u][colors[u]-'a']);
            //cout << col[u][colors[u]-'a'] << " ";
            ans.push_back(u);
            for(int v : adj[u]){
                for(int i = 0 ; i < 26 ; i++){
                    col[v][i] = max(col[v][i], col[u][i]);
                }
                //cout << "v = " << v << " in[v] = " << in[v] << endl ;
                in[v]--;
                if(in[v] == 0) q.push(v);
            }
        }
        return ans;
    }
    
};