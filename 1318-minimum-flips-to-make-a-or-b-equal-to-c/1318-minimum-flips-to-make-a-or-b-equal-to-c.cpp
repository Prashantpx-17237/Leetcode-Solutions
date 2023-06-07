class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        
        for(int i = 0 ; i < 31; i++){
            int mask = (1 << i);
            if(c & mask){
                ans += (((mask & b) + (mask & a)) == 0);
            }
            else{
                ans += ((mask & b) + (mask & a) ) / mask;
            }
        }
        return ans;
    }
};