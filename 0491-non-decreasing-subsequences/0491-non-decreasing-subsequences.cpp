class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        int n = nums.size();
        int range = 1 << n;
        
        vector<vector<int>> ans, local;
        for(int i = 0 ; i < range ; i++)
        {
            vector<int> tmp;
            for(int j = 0 ; j < n ; j++)
            {
                int mask = 1 << j;
                if((i & mask) == mask and (tmp.empty() or tmp.back() <= nums[j]))
                    tmp.push_back(nums[j]);
            }
            if(tmp.size() > 1)
                local.push_back(tmp);
        }
        sort(local.begin(), local.end());
        for(int i = 0 ; i < local.size() ; i++)
        {
            if(i == 0 or local[i] != local[i-1])
                ans.push_back(local[i]);
        }
        return ans;
    }
};