class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        map<int, int> lookup;
        vector<int> prefix(n, 0);
        lookup[0] = 1;
        for(int i = 0 ; i < n ; i++){
            prefix[i] = nums[i];
            
            if(i != 0)
                prefix[i] += prefix[i-1];
            
            if(lookup.find(prefix[i] - k) != lookup.end())
                ans += lookup[prefix[i] - k];
            
            lookup[prefix[i]]++;
        }
        return ans;
    }
};