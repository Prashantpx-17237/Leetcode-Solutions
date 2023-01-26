class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto i : flights)
            adj[i[0]].push_back({i[1], i[2]});
        
        vector<int> d(n, INT_MAX);
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {src, 0}});   // dist, node, steps
        d[src] = 0;
        int ans = 1E9;
        while(!pq.empty())
        {
            auto val = pq.front();
            pq.pop();
            int stops = val.second.second;
            int node = val.second.first, cost = val.first;
            if(node == dst)
            {
                //cout << "fucked" << endl ;
                ans = min(ans, cost);
            }
            if(stops > k)
                continue;
            
            for(auto u : adj[node])
            {
                int nxt = u.first, cst = u.second;
                if(d[nxt] > cost + cst)
                {
                    d[nxt] = cost + cst;
                    pq.push({d[nxt], {nxt, stops + 1}});
                }
            }
            
        }
        return (ans < 1E8 ? ans : -1);
    }
};