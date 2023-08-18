class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> v(n);
        
        vector<int> in(n, 0);
        map<pair<int, int>, int> utov;
        int ans = 0;
        
        for(auto i : roads){
            in[i[0]]++;
            in[i[1]]++;
            utov[{i[0], i[1]}] = 1;
        }
        for(int i = 0 ; i < n ; i++){
            
            for(int j = i+1 ; j < n ; j++){
                
                ans = max(ans, in[i]+in[j] - utov[{i, j}] - utov[{j, i}]);
            }
        }
        return ans;
    }
};