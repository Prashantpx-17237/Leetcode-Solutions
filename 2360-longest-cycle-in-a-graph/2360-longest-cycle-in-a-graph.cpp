class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> inDeg(n, 0);
        for(auto i : edges) (i != -1 ? inDeg[i]++ : true);
        
        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            if(inDeg[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            int v = edges[u];
            edges[u] = -1;
            if(v == -1)
                continue;
            inDeg[v]--;
            if(inDeg[v] == 0) q.push(v);
        }
        int ans = -1;
        for(int i = 0 ; i < n ; i++){
            if(edges[i] != -1){
                int u = i, cnt = 0;
                while(u != -1 and edges[u] != -1){
                    cnt++;
                    int v = edges[u];
                    
                    edges[u] = -1;
                    u = v;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};