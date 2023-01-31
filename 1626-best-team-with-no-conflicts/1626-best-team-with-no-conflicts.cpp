class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    
        int n = ages.size();
        vector<pair<int, int>> v(n);
        
        for(int i = 0 ; i < n ; i++)
        {
            v[i] = {ages[i], scores[i]};
        }
        sort(v.begin(), v.end());
        
        int cache[n+1];
        
        for(int i = 0 ; i < n ; i++)
        {
            cache[i] = v[i].second;
            for(int j = i - 1 ; j > -1 ; j--)
            {
                if(v[j].second <= v[i].second)
                {
                    cache[i] = max(cache[i], v[i].second + cache[j]);
                }
            }
        }
        
        int ans = cache[0];
        for(int i = 1 ; i < n ; i++)
            ans = max(ans, cache[i]);
        return ans;
    }
};