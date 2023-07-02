class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int ans = 0;
        for(int i = 0 ; i < (1 << m) ; i++){
            vector<int> count(n, 0);
            int bitc = __builtin_popcount(i);
            if(bitc <= ans) continue;
            for(int j = 0 ; j < m; j++){
                if(i & (1 << j)){
                    count[requests[j][0]]--;
                    count[requests[j][1]]++;
                }
            }
            int ok = 0;
            for(int j = 0; j < n; j++) ok += (count[j] != 0);
            if(ok == 0) ans = max(ans, bitc);
        }
        return ans;
    }
};