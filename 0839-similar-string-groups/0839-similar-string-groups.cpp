class DSU{
private:
    vector<int> par, sz;
    int connected;
public:
    DSU(int n){
        connected = n;
        par.resize(n), sz.resize(n);
       for(int i = 0 ; i < n ; i++){
           this->par[i] = i;
           this->sz[i] = 1;
       }
    }
    
    int get(){
        return this->connected;
    }
        
        int find(int u){
            if(par[u] != u)
                par[u] = find(par[u]);
            return par[u];
        }
        
        void merge(int u, int v){
            int a = find(u), b = find(v);
            if(a == b) return;
            this->connected--;
            if(sz[a] > sz[b]) swap(a, b);
            par[a] = par[b];
            sz[b] += sz[a];
            return;
        }
};

class Solution {
public:
    bool same(string& a, string& b){
        int cnt = 0;
        for(int i = 0 ; i < a.length() ; i++) cnt += (a[i] != b[i]);
        return (cnt == 2 or cnt == 0);
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU dsu(n);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(same(strs[i], strs[j])) dsu.merge(i, j);
            }
        }
        return dsu.get();
    }
};