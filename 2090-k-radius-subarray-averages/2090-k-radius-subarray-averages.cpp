class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        long sum = 0, l = 0, len = 2 * k + 1;
        for(int i = 0 ; i <= min(n-1, 2*k); i++) sum += nums[i];
        for(int i = k ; i + k < n ; i++){
            ans[i] = sum / len;
            sum -= nums[l++];
            if(i + k + 1 >= n) break;
            sum += nums[i+k+1];
        }
        return ans;
    }
};