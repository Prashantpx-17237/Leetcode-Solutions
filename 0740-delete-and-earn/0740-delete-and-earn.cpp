class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        for(auto i : nums) mp[i]++;
        vector<pair<int, int>> v;
        for(auto i: mp) v.push_back({i.first, i.first * i.second});
        int n = mp.size();
        
        vector<int> profit(n, 0);
        
        for(int i = n - 1 ; i > -1; i--){
            int pick = v[i].second;
            int l = i+1;
            while(l < n and v[l].first <= v[i].first + 1) l++;
            if(l < n) pick += profit[l];
            
            int skip = (i + 1 < n ? profit[i+1] : 0);
            
            profit[i] = max(pick, skip);
        }
        
        return profit[0];
    }
};