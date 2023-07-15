class Solution {
public:
    
    int getInd(vector<vector<int>>& events, int time, int low){
        
        int l = low, r = events.size();
        
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(events[mid][0] > time)
                r = mid;
            else
                l = mid;
        }
        return l+1;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        
        int n = events.size();
        int dp[n+1][k+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 1 ; j <= k ; j++){

                // if take
                int time = events[i][1], value = events[i][2];
                int ind = getInd(events, time, i);
                dp[i][j] = events[i][2] + dp[ind][j-1];
                
                // not take
                
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
            }
        }
        return dp[0][k];
    }
};