class Solution {
public:
    
    bool good(vector<int>& piles, int h, int k)
    {
        long int ans = 0;
        
        for(auto i : piles)
            ans += 1LL * ((i + k - 1) / k);
        
        return ans <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long int low = 0, high = *max_element(piles.begin(), piles.end());
        
        while(low + 1 < high)
        {
            int mid = (low + high) / 2;
            if(good(piles, h, mid))
                high = mid;
            else
                low = mid;
        }
        return high;
    }
};