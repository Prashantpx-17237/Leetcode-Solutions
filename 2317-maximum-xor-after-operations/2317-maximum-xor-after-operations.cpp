class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> bit(32, 0);
        
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < 32; j++){
                if(nums[i] & (1 << j)) bit[j]++;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            if(bit[i] > 0) ans += (1 << i);
        }
        
        return ans;
    }
};