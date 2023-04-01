class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            
            int ind = low + (high - low) / 2;
            if(nums[ind] == target)
                return ind;
            if(nums[ind] > target)
                high = ind - 1;
            else
                low = ind + 1;
        }
        return -1;
    }
};