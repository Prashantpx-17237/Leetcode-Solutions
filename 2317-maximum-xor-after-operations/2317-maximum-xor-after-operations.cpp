class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        
        /*
           nums[i] XOR x means we can flip any bit
           nums[i] AND nums[i] XOR x means removing bit from nums[i]
           
        */
        
        int ans = 0;
        for(auto i : nums) ans |= i;        
        return ans;
    }
};