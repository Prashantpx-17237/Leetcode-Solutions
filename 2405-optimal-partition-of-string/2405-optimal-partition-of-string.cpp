class Solution {
public:
    int partitionString(string s) {
        int mask = 0;
        int ans = 1;
        for(auto i : s){
            int bit = i-'a';
            if((mask & (1 << bit)) > 0){
                ans++;
                mask = 0;
            }
            mask |= (1 << bit);
        }
        return ans;
    }
};