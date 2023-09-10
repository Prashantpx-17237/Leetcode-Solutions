class Solution {
public:
    int mod = 1E9+7;
    
    int get(int n){
        if(n == 1) return 1;
        int prev = get(n-1);
        int ans = 0;
        int have = 2*(n-1);
        for(int i = have+1 ; i > -1; i--){
            ans += i;
        }
        return (ans *1LL* prev)%mod;
    }
    int countOrders(int n) {
        // p1,d1
        // n+1 positions for next P
        // p2p1d1 - n+1 pos
        // p1p2d1 - n pos
        // .
        // .
        // .    
        // p1d1p2 - 1 pos
        
        
        return get(n);
    }
};