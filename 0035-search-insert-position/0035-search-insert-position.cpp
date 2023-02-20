class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n;
        
        while(l + 1 < r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid;
            else
                r = mid;
        }
        return r;
    }
};