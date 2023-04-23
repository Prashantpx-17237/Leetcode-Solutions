class Solution {
public:
    const int mod = 1E9+7;
    /*int get(string& s, int ind, int k, vector<int>& dp){
        if(ind == s.length())
            return 1;
        if(s[ind] == '0') return 0;
        if(dp[ind] != -1)
            return dp[ind];
        long int cur = 0, ans = 0;
        for(int i = ind ; i < s.length() ; i++){
            cur = cur * 10 + (s[i] - '0');
            if(cur <= k)
                ans = (ans + get(s, i+1, k, dp)) % mod;
            else
                break;
        }
        return dp[ind] = ans % mod;
    }*/
    
    int numberOfArrays(string s, int k) {
        
        int n = s.length();
        vector<int> dp(n, 0);
        
        for(int i = n - 1 ; i > -1 ; i--){
            if(s[i] == '0') continue;
            long int cur = 0;
            for(int j = i ; j < n ; j++){
                cur = cur * 10 + (s[j]-'0');
                if(cur <= k){
                    dp[i] = (dp[i] + (j+1 < n ? dp[j+1] : 1))% mod;
                }
                else break;
            }
        }
        
        return dp[0];
    }
};