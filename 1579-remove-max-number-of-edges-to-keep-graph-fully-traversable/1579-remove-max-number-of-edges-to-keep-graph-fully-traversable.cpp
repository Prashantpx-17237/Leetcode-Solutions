class DSU{
    private:
    vector<int> par, rank;
    int connected;
    
    public:
    
    DSU(int n){
        connected = n;
        par.resize(n), rank.resize(n);
        for(int i = 0 ; i < n ; i++) par[i] = i;
    }
    
    int get(){
        return connected;
    }
    
    int find(int u){
        if(par[u] == u)
            return u;
        return find(par[u]);
    }
    
    void merge(int u, int v){
        int a = find(u), b = find(v);
        if(a == b) return;
        connected--;
        if(rank[a] > rank[b]) swap(a, b);
        par[a] = b;
        if(rank[a] == rank[b]) rank[b]++;
        return;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {return a[0] > b[0];});
        DSU alice(n), bob(n);
        int ans = 0;
        for(int i = 0 ; i < edges.size() ; i++){
            int type = edges[i][0], u = edges[i][1]-1, v = edges[i][2]-1;
            
            if(type == 3){
                if(alice.find(u) == alice.find(v)) ans++;
                alice.merge(u, v);
                bob.merge(u, v);
            }
            else if(type == 2){
                if(bob.find(u) == bob.find(v)) ans++;
                bob.merge(u, v);
            }
            else{
                if(alice.find(u) == alice.find(v)) ans++;
                alice.merge(u, v);
            }
        }
        return (alice.get() == 1 and bob.get() == 1 ? ans : -1);
    }
};