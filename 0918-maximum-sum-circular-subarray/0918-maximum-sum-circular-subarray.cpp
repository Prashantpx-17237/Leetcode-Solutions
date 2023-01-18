class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int ans = nums[0], cur = 0;
        
        for(auto i : nums)
        {
            if(i + cur <= i)
                cur = i;
            else
                cur += i;
            ans = max(ans, cur);
        }
        
        int len = nums.size();
        vector<int> pref(len), suf(len);
        pref[0] = nums[0];
        
        cur = nums[0];
        for(int i = 1 ; i < len ; i++)
        {
            cur += nums[i];
            pref[i] = max(pref[i-1], cur);
        }
        
        cur = suf[len - 1]  = nums[len - 1];
        for(int i = len - 2 ; i > -1 ; i--)
        {
            cur += nums[i];
            suf[i] = max(suf[i+1], cur);
        }
        
        for(int i = 0 ; i < len - 1 ; i++)
            ans = max(ans, pref[i] + suf[i+1]);
        return ans;
    }
};