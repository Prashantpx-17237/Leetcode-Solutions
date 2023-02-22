class Solution {
public:

    bool can(int limit, vector<int>& weights, int days)
    {
        int ans = 0, curSum = 0, n = weights.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(curSum + weights[i] > limit)
            {
                ans++;
                curSum = weights[i];
            }
            else
                curSum += weights[i];
        }
        //cout << ans << " " << days << " " << limit << endl ;
        return ans < days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int len = weights.size();
        int low = (*max_element(weights.begin(), weights.end()));
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high)
        {
            int limit = low + (high - low) / 2;
            if(can(limit, weights, days))
                high = limit - 1;
            else
                low = limit + 1;
        }
        return low;
    }
};