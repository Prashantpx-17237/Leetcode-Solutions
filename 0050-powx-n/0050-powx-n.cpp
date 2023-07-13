class Solution {
public:
    
    double myPow(double x, int n) {
        double res = 1;
        if(n == 0) return 1;
        int N = abs(n);
        while(N > 0){
            if(N & 1) res = res * x;
            x = x * x;
            N >>= 1;
        }
        if(n > 0) return res;
        return 1.0 / res;
    }
};