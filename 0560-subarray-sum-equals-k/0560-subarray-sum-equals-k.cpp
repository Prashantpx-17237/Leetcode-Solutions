class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        map<int, int> lookup;
        int pre = 0;
        
        lookup[0] = 1;
        
        for(int i = 0 ; i < n ; i++){
            pre += nums[i];
            if(lookup.find(pre - k) != lookup.end())
                ans += lookup[pre - k];
            
            lookup[pre]++;
        }
        return ans;
    }
};