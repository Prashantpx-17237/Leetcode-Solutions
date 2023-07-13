class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& adj) {
        vector<int> v(n, 0) ;
        vector<vector<int>> a(n) ;
        for(int i = 0 ; i < adj.size() ; i++)
        {
            a[adj[i][0]].push_back(adj[i][1]) ;
            //v[adj[i][1]] = -1 ;
        }
        for(int i = 0 ; i < n ; i++)
            if(v[i] == 0 and dfs(i, a, v))
                return false ;
        return true ;
    }
    bool dfs(int s, vector<vector<int>>& adj, vector<int>& v)
    {
        v[s] = 1 ;
        for(int u : adj[s])
        {
            if(v[u] == 0)
            {
                if(dfs(u, adj, v))
                    return true ;
            }
            else if(v[u] == 1)
                return true ;
        }
        v[s] = 2 ;
        return false ;
    }
};