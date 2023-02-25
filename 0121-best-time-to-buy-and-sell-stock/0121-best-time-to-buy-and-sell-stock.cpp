class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int ans = 0, curMin = prices[0];
        for(auto i : prices)
        {
            ans = max(i - curMin, ans);
            curMin = min(curMin, i);
        }
        return ans;
    }
};