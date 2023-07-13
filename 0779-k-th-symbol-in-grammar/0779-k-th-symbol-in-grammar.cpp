class Solution {
public:
    
    int kthGrammar(int n, int k) {
        
        if(n <= 2 and k == 1) return 0;
        if(n == 2 and k == 2) return 1;
        
        int from =  kthGrammar(n-1, (k+1) / 2);
        
        if(k & 1) return from ^ 0;
        else return from ^ 1;
    }
};