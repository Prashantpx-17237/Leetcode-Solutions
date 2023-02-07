class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, 1);
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n; i++)
        {
            for(int j = i - 1 ; j > -1 ; j--)
                if(nums[i] % nums[j] == 0)
                    cache[i] = max(cache[i], 1 + cache[j]);
        }
        int ind = 0, mx = cache[0];
        for(int i = 0 ; i < n ; i++)
            if(cache[i] > mx)
            {
                mx = cache[i];
                ind = i;
            }
        
        //cout << mx << endl ;
        vector<int> ans;
        int last = nums[ind];
        for(int i = ind ; i > -1; i--)
        {
            if(last % nums[i] == 0 && cache[i] == mx)
            {   
                ans.push_back(nums[i]);
                last = nums[i];
                mx--;
            }
        }
        return ans;
    }
};