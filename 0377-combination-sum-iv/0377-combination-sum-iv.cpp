class Solution {
public:
    int get(int target, vector<int>& nums, vector<int>& dp){
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > target) break;
            ans += get(target - nums[i], nums, dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> dp(target+1, -1);
        return get(target, nums, dp);
    }
};