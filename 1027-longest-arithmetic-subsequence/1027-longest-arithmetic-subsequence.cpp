class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ret = 2;
        vector<vector<int>> ans(n, vector<int>(1010, 1)); // maxlen using i elements of len j
        
        for(int i = 0 ; i < n; i++){
            
            for(int j = 0; j < i; j++){
                
                int dif =  nums[i] - nums[j] + 501; // 500 - 0  and 0 - 500
                
                ans[i][dif] = ans[j][dif] + 1;
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < 1010 ; j++)
                ret = max(ret, ans[i][j]);
        }
        return ret;
    }
};