class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1});
        int maxlen = 1;
        for(int i = 1 ; i < n ; i++){
            for(int j = i -1; j > -1; j--){
                if(nums[j] < nums[i]){
                    if(dp[j].second + 1 >= dp[i].second){
                        if(dp[j].second + 1 == dp[i].second) {
                            dp[i].first += dp[j].first;
                            continue;
                        }
                        dp[i].second = dp[j].second+1;
                        dp[i].first = dp[j].first;
                    }
                }
            }
            maxlen = max(maxlen, dp[i].second);
        }
        
        int ans = 0;
        for(auto i : dp){
            ans += (i.second == maxlen ? i.first : 0);
        }
        return ans;
    }
};