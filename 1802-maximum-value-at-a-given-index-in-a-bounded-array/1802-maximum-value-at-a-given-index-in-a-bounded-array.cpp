class Solution {
public:
    
    bool check(int val, int ind, int n, int maxSum){
        long sum = val, prev = val;
        
        int have = val - 1, left = ind, right = n - ind - 1;
        long haveLeft = max(have - left, 0), haveRight = max(0, have-right);
        long summ = (val - 1) * 1LL * val;
        haveLeft = (haveLeft * (haveLeft + 1)) / 2;
        haveRight = (haveRight * (haveRight + 1)) / 2;
        sum += summ;
        sum += max(left - have, 0);
        sum += max(right - have, 0);
        sum -= haveLeft;
        sum -= haveRight;
        return sum <= maxSum;
    }
    
    int maxValue(int n, int index, int maxSum) {
        int r = maxSum+5, l = 0;
        
        // l holds true
        // r holds false
        
        while(l+1 < r){
            int mid = l + (r - l) / 2;
            
            if(check(mid, index, n, maxSum)){
                l = mid;
            }
            else
                r = mid;
        }
        return l;
    }
};

/*

4
2
6
6
1
10
1
0
24
6
2
931384943
4760576
1973182
461577676

*/