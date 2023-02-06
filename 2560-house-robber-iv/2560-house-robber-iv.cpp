class Solution {
public:
    
    bool check(vector<int> &nums, int k, int val)
    {
        int count = 0;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] <= val)
            {
                count++;
                i++;
            }
        }
        
        return count >= k;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        
        while(low < high)
        {
            int mid = (low + high)  >> 1;
            
            if(check(nums, k, mid))
            {
                high = mid;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};