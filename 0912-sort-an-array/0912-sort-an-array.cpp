class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> f(100009, 0);
        int val = 50005;
        
        for(auto i : nums)
        {
            f[i + val]++;
        }
        vector<int> ans;
        for(int i = 0 ; i < f.size() ; i++)
        {
            while(f[i]-- > 0)
                ans.push_back(i-val);
        }
        return ans;
    }
};