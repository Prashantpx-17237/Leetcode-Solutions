class Solution {
public:
    
    bool check(vector<int>& time, int trips, long long int tim)
    {
        long int ans = 0;
        for(auto i : time)
            ans += tim / i;
        //cout << ans << "  " << trips << endl;
        return ans >= trips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int low = 0, high = time[0] * 1LL * totalTrips;
        
        while(low + 1 < high)
        {
            //cout << low  << " " << high << endl ;
            long long int mid = (low + high) / 2;
            if(check(time, totalTrips, mid))
                high = mid ;
            else
                low = mid ;
        }
        
        return high;
    }
};