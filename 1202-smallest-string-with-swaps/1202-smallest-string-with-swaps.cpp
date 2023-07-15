

class Solution {
public:
    int find(int a, vector<int>& par){
        if(par[a] == a) return a;
        return find(par[a], par);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int> par(n);
        for(int i = 0 ; i < n ; i++) par[i] = i;
        
        for(auto i : pairs){
            int a = find(i[0], par), b = find(i[1], par);
            if(a == b) continue;
            if(a > b) swap(a, b);
            par[a] = b;
        }
        
        vector<vector<int>> ind(n);
        
        for(int i = 0 ; i < n ; i++) ind[find(i, par)].push_back(i);
        
        for(auto i : ind){
            string str = "";
            for(auto j : i) str += s[j];
            
            sort(str.begin(), str.end());
            int k = 0;
            for(auto j : i) s[j] = str[k++];
        }
        return s;
    }
};