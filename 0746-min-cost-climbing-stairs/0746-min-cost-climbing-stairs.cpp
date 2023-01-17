class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();

        int dp[len + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 2 ; i <= len ; i++)
        {
            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
        }
        return dp[len];
    }
};