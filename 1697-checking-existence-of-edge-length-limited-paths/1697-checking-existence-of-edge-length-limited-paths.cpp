class DSU{
    private:
    vector<int> par;
    vector<long int> sz;
    public:
    
    DSU(int n){
        par.resize(n), sz.resize(n);
        for(int i = 0 ; i < n; i++){
            sz[i] = 0;
            par[i] = i;
        }
    }
    
    int find(int u){
        if(par[u] == u)
            return u;
        return par[u] = find(par[u]);
    }
    
    void merge(int u, int v){
        int a = find(u), b = find(v);
        if(u == v) return;
        if(sz[a] > sz[b]) swap(a, b);
        if(sz[a] == sz[b]) sz[b]++;
        par[a] = b;
    }
};


bool comp(vector<int>& a, vector<int>& b){
    return a[2] < b[2];
}

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        int q = queries.size();
        for(int i = 0 ; i < q; i++) queries[i].push_back(i);
        vector<bool> ans(q, false);
        sort(edgeList.begin(), edgeList.end(), comp);
        sort(queries.begin(), queries.end(), comp);
        
        DSU dsu(n);
        int j  = 0, eSize = edgeList.size();
        for(int i = 0 ; i < q ; i++){
            auto val = queries[i];
            while(j < eSize and edgeList[j][2] < val[2]){
                dsu.merge(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            if(dsu.find(val[0]) == dsu.find(val[1])) ans[val[3]] = true;
        }
        return ans;
    }
};