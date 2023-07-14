class DSU{
    private:
    vector<int> par, size;
    int noc;
    public:
    DSU(int n){
        noc = n;
        par.resize(n);
        size.resize(n, 0);
        for(int i = 0 ; i < n ; i++) par[i] = i;
    }
    
    int find(int a){
        if(par[a] == a) return a;
        
        return par[a] = find(par[a]);
    }
    
    void merge(int a, int b){
        int u = find(a), v = find(b);
        if(u == v) return;
        noc--;
        if(size[u] > size[v]) swap(u, v);
        par[u] = v;
        size[v] += (size[u] == size[v]);
        return;
    }
    
    int getNoc()
    {
        return noc;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(n -1 > connections.size()) return -1;
        
        DSU dsu(n);
        
        for(auto i : connections) dsu.merge(i[0], i[1]);
        
        return dsu.getNoc() - 1;
    }
};