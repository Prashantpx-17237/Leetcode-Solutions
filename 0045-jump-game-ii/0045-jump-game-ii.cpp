class Solution {
public:
    int jump(vector<int>& nums) {
        
        int ans = 1, cur = nums[0], maxReach = nums[0];
        int n = nums.size();
        if(n == 1)
            return 0;
        for(int i = 1 ; i < n ; i++)
        {
            if(cur >= n - 1)
                return ans;
            maxReach = max(i + nums[i], maxReach);
            if(i == cur)
            {
                cur = maxReach;
                ans++;
            }
            
        }
        if(maxReach >= nums[n-1])
            return ans;
        //cout << cur << endl ;
        return -1;
    }
};