class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size(), m = spells.size();
        vector<int> ans;
        for(auto i : spells){
            long req = (success + i - 1) / i*1LL;
            int ind = lower_bound(potions.begin(), potions.end(), req) - potions.begin();
            ans.push_back(n - ind);
        }
        return ans;
    }
};