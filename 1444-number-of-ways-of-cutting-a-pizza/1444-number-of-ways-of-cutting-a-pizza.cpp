class Solution {
public:
    
    // agar vertical se kata to left wala gya 
    // else horizontal case me uppar wala gya
    int dp[51][51][10];
    const int mod = 1E9 + 7;
    int canCut(vector<string>& pizza, int x1, int x2, int y1, int y2){
        int count = 0;
        for(int i = x1 ; i < x2 ; i++){
            for(int j = y1 ; j < y2; j++)
                count += (pizza[i][j] == 'A');
        }
        return count;
    }
    int get(vector<string>& pizza, int x1, int y1, int x2, int y2, int rem, int tot)
    {
        int& cache = dp[x1][y1][rem];
        if(tot < rem){
            return 0;
        }
        if(rem == 1){
           
            return 1;
        }
        if(cache != -1)
            return cache;
        int ans = 0;
        for(int i = x1 + 1; i <= x2 ; i++){
            int val = canCut(pizza, x1, i, y1, y2+1);
            if(val > 0) {
                ans = ans % mod + get(pizza, i, y1, x2, y2, rem - 1, tot-val) % mod;
            }
        }
        for(int j = y1 + 1; j <= y2; j++){
            int val = canCut(pizza, x1, x2+1, y1, j);
            if(val > 0){
                ans = ans % mod + get(pizza, x1, j, x2, y2, rem - 1, tot-val) % mod;
            }
        }
        ans = ans % mod;
        return cache = ans;
     }
    
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].length();
        memset(dp, -1, sizeof(dp));
        int count = 0;
        for(auto i : pizza) for(auto j : i) count += (j == 'A');
        return get(pizza, 0, 0, n-1, m-1, k, count);
    }
};