class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m = words[0].length(), n = target.size();
        vector<vector<int>> count(m, vector<int>(26, 0)), dp(n+1, vector<int>(m+1, 0));
        
        int mod = 1E9 + 7;
        
        for(int i = 0 ; i < words.size() ; i++){
            
            for(int j = 0 ; j < m; j++){
                
                count[j][words[i][j] -'a']++;
            }
        }
        
        // count array stores count of any character ch on ith index        
        
        for(int i = 0 ; i <= m ; i++) dp[0][i] = 1;
        
        for(int i = 1 ; i <= n ; i++){
            
            for(int j = 1 ; j <= m ; j++){
                
                dp[i][j] = ((dp[i-1][j-1] * 1LL * count[j-1][target[i-1]-'a']) % mod + 
                    dp[i][j-1]) % mod;
                
                // dp[i][j] represents number of ways we can make i len target string
                //          using upto j indices of all strings in words. 
                
                // when we make ith char => number of ways to (i-1, j-1) * count(j-1, cur char)
                // when ith character is already made using j-1 charac only then dp[i][j-1]
                
            }
        }
        return dp[n][m];
        
    }
};