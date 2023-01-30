class Solution {
public:
    map<int, int> mp ;
    int tribonacci(int n) {
        if(n == 0)
            return 0 ;
        if(n == 1)
            return 1 ;
        if(n == 2)
            return 1 ;
        if(mp[n] != 0)
            return mp[n] ;
        return mp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3) ;
    }
};