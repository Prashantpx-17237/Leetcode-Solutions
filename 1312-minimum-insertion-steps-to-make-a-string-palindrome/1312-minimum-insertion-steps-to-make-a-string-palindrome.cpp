class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
       
        // similar to lcs in two strings
        for(int i = n-1 ; i > -1 ; i--){
            
            for(int j = i ; j < n ; j++){
                if(s[i] == s[j]){
                    dp[i][j] = (i+1 < n and j-1 > -1? dp[i+1][j-1] : 0);
                }
                else{
                    dp[i][j] = 1+min(dp[i][j-1], (i+1 < n and j-1 > -1? dp[i+1][j] : 0));
                }
            }
        }
        return dp[0][n-1];
    }
};