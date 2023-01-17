class Solution {
public:
    int get(int n, int dp[])
    {
        if(n == 0 or n == 1)
            return 1 ;
        if(dp[n] != -1)
            return dp[n] ;
        return dp[n] = get(n-1, dp) + get(n-2, dp) ;
    }
    int climbStairs(int n) {
        int dp[n+1] ;
        memset(dp, -1,  sizeof(dp)) ;
        return get(n, dp) ;
    }
};