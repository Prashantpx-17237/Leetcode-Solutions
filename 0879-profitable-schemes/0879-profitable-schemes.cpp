class Solution {
public:
    
    int dp[101][101][101], mod = 1E9 + 7;
    
    int get(int level, int pro, int tot, vector<int>& group, vector<int>& profit, int minP, int sz){
        int n = group.size();
        if(level == n)
            return pro >= minP;
        
        int p = min(pro, minP);
        
        int& ans = dp[level][p][tot];
        
        if(ans != -1)
            return ans;
        
        // not take
        ans = get(level + 1, p, tot, group, profit, minP, sz);
        
        // not take
        if(tot + group[level] <= sz){
            ans = (ans + get(level+1, p+profit[level], tot+group[level], group, profit,                     minP, sz)) % mod;
        }
        
        return ans;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return get(0, 0, 0, group, profit, minProfit, n);
    }
};