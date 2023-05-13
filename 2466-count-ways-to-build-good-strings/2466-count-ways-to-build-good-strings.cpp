class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> cache(high+1, 0);
        cache[0] = 1;
        int mod = 1E9 + 7;
        for(int i = 1 ; i <= high; i++)
        {
            cache[i] += (i - zero > -1 ? cache[i-zero] : 0);
            cache[i] += (i - one > -1 ? cache[i-one] : 0);
            cache[i] %= mod;
        }
        int ans = 0;
        for(int i = low ; i <= high ; i++) ans = (ans + cache[i]) % mod;
        
        return ans;
    }
};