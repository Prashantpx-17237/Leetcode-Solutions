class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        int left = -1, right = *max_element(nums.begin(), nums.end());
        
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            
            if(good(nums, mid))
                right = mid;
            else
                left = mid;
        }
        return left + 1;
    }
    
    bool good(vector<int>& num, int val){
        
        vector<long int> nums ;
        for(auto i : num) nums.push_back(i);
        for(int i = nums.size() - 1; i > 0 ; i--){
            if(nums[i] > val){
                nums[i-1] += 1LL*(nums[i] - val);
                nums[i] = val;
            }
        }
        return (nums[0] <= val);
    }
};