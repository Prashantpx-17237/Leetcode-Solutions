class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long ans = 0;
        
        map<int, int> mp;
        int n = basket1.size();
        map<int, int> mp1, mp2;
        
        for(int i = 0 ; i < n ; i++)
        {
            mp[basket1[i]]++;
            mp[basket2[i]]++;
            mp1[basket1[i]]++;
            mp2[basket2[i]]++;
        }
        
        for(auto i : mp)
            if(i.second % 2)
                return -1;
        
        vector<int> need;
        int mn = (*mp.begin()).first;
        for(auto i : mp)
        {
            int require = i.second / 2;
            int j = 1;
            while(mp1[i.first] + j++ <= require)
                need.push_back(i.first);
            j = 1;
            while(mp2[i.first] + j++ <= require)
                need.push_back(i.first);
        }
        for(int i = 0 ; i < need.size() / 2 ; i++)
            ans += min(2 * mn, need[i]);
        return ans;
    }
};