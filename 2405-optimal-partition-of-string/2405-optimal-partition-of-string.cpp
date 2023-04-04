class Solution {
public:
    int partitionString(string s) {
        int mask = 0;
        int ans = 1;
        for(auto i : s){
            int bit = i-'a';
            int bitmask = 1 << bit;
            if((mask & bitmask) == bitmask){
                ans++;
                mask = 0;
            }
            mask |= (1 << bit);
        }
        return ans;
    }
};