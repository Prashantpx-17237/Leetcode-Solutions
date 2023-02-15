class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        vector<int> nxt;
        while(k > 0)
        {
            nxt.push_back(k % 10);
            k /= 10;
        }
        reverse(nums.begin(), nums.end());
        int carry = 0, n = nums.size(), m = nxt.size();
        vector<int> ans;
        int i = 0, j = 0;
        while(i < n || j < m || carry > 0)
        {
            int cur = (i < n ? nums[i] : 0)
                    + (j < m ? nxt[j] : 0) + carry;
            carry = cur / 10;
            ans.push_back(cur % 10);
            i++, j++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};